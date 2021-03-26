

#include "OutputContext.h"
#include "CodecInfo.h"
#include "Encoder.h"
#include "Packet.h"

extern "C" {

#include <libavutil/opt.h>
}

OutputContext::OutputContext()
	:formatContext(NULL), outputFormat(NULL), videoStreamIndex(-1), audioStreamIndex(-1), audioPacketCount(0) {

	av_register_all();
	avcodec_register_all();
}

OutputContext::~OutputContext() {


}


bool OutputContext::create(const char *fileName, const char *formatName) {

	int result = avformat_alloc_output_context2(&this->formatContext, NULL, formatName, fileName);
	if (result < 0)
		return false;

	this->outputFormat = this->formatContext->oformat;

	return true;
}

VideoEncoder* OutputContext::createEncoder(const VideoCodecInfo &codecInfo) {

	if (codecInfo.useHwAccels == false) {
	
		return this->createSwEncoder(codecInfo);
	}

	return this->createHwEncoder(codecInfo);
}

AudioEncoder* OutputContext::createEncoder(const AudioCodecInfo &codecInfo) {

	this->outputFormat->audio_codec = codecInfo.codecID;

	AVCodec *avCodec = NULL;
	avCodec = avcodec_find_encoder(this->outputFormat->audio_codec);
	if (avCodec == NULL)
		return NULL;

	AVStream *avStream = avformat_new_stream(this->formatContext, avCodec);
	if (avStream == NULL)
		return NULL;

	AudioEncoder *encoder = new AudioEncoder;

	encoder->codecContext = avcodec_alloc_context3(avCodec);
	if (encoder->codecContext == NULL) {
		delete encoder;
		return NULL;
	}


	avStream->codecpar->codec_id = this->outputFormat->audio_codec;
	avStream->codecpar->codec_type = AVMEDIA_TYPE_AUDIO;
	avStream->codecpar->format = codecInfo.sampleFormat;
	avStream->codecpar->bit_rate = codecInfo.bitRate;
	avStream->codecpar->sample_rate = codecInfo.sampleRate;
	avStream->codecpar->channels = codecInfo.channels;
	avStream->codecpar->channel_layout = av_get_default_channel_layout(codecInfo.channels);


	if (avcodec_parameters_to_context(encoder->codecContext, avStream->codecpar) < 0) {
		delete encoder;
		return false;
	}

	if (this->formatContext->oformat->flags & AVFMT_GLOBALHEADER)
		encoder->codecContext->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;

	if (avcodec_open2(encoder->codecContext, avCodec, NULL) < 0) {
		delete encoder;
		return NULL;
	}

	if (avcodec_parameters_from_context(avStream->codecpar, encoder->codecContext) < 0) {
		delete encoder;
		return NULL;
	}


	for (int i = 0; i < this->formatContext->nb_streams; i++) {

		if (this->formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO) {
			this->audioStreamIndex = i;
		}
	}

	return encoder;
}


bool OutputContext::open() {

	int error;
	if (!(this->formatContext->flags & AVFMT_NOFILE))
		if ((error = avio_open(&this->formatContext->pb, this->formatContext->filename, AVIO_FLAG_WRITE)) < 0)
			return false;

	if ((error = avformat_write_header(this->formatContext, NULL)) < 0)
		return false;


	av_dump_format(this->formatContext, 0, this->formatContext->filename, 1);

	return true;
}


bool OutputContext::writePacket(VideoPacket *packet) {

	packet->packet->stream_index = this->videoStreamIndex;
	packet->packet->pts = av_rescale_q(packet->packet->pts, packet->codecTimeBase, this->formatContext->streams[this->videoStreamIndex]->time_base);
	packet->packet->dts = av_rescale_q(packet->packet->dts, packet->codecTimeBase, this->formatContext->streams[this->videoStreamIndex]->time_base);

	bool result;
	this->packetMutex.lock();

	if (av_interleaved_write_frame(this->formatContext, packet->packet) < 0) {
	
		result = false;
	}
	else {
	
		result = true;
	}

	this->packetMutex.unlock();

	return result;
}

bool OutputContext::writePacket(AudioPacket *packet) {

	packet->packet->pts= (1.0 / (packet->sampleRate * 1.0 / packet->frameSize)) *
		this->formatContext->streams[this->audioStreamIndex]->time_base.den /
		this->formatContext->streams[this->audioStreamIndex]->time_base.num *
		(this->audioPacketCount++);

	packet->packet->stream_index = this->audioStreamIndex;

	bool result;
	this->packetMutex.lock();

	if (av_interleaved_write_frame(this->formatContext, packet->packet) < 0) {

		result = false;
	}
	else {

		result = true;
	}

	this->packetMutex.unlock();

	return result;
}

bool OutputContext::close() {

	av_write_trailer(this->formatContext);
	if (!(this->formatContext->flags & AVFMT_NOFILE)) {
		int err = avio_close(this->formatContext->pb);
		if (err < 0) {
			return false;
		}
	}

	return true;
}

bool OutputContext::destroy() {

	avformat_free_context(this->formatContext);

	return true;
}



VideoEncoder* OutputContext::createSwEncoder(const VideoCodecInfo &codecInfo) {

	this->outputFormat->video_codec = codecInfo.codecID;

	AVCodec *codec = NULL;
	codec = avcodec_find_encoder(this->outputFormat->video_codec);
	if (codec == NULL)
		return NULL;

	AVStream *stream = avformat_new_stream(this->formatContext, codec);
	if (stream == NULL)
		return NULL;
	VideoEncoder *encoder = new VideoEncoder;

	encoder->codecContext = avcodec_alloc_context3(codec);
	if (encoder->codecContext == NULL) {
		delete encoder;
		return NULL;
	}

	stream->codecpar->codec_id = this->outputFormat->video_codec;
	stream->codecpar->codec_type = AVMEDIA_TYPE_VIDEO;
	stream->codecpar->width = codecInfo.width;
	stream->codecpar->height = codecInfo.height;
	stream->codecpar->format = codecInfo.pixelFormat;
	stream->codecpar->bit_rate = codecInfo.bitrate;

	if (avcodec_parameters_to_context(encoder->codecContext, stream->codecpar) < 0) {
		delete encoder;
		return NULL;
	}

	encoder->codecContext->time_base.num = 1;
	encoder->codecContext->time_base.den = codecInfo.fps;
	encoder->codecContext->max_b_frames = 10;
	encoder->codecContext->gop_size = 12;
	encoder->codecContext->framerate.num = codecInfo.fps;
	encoder->codecContext->framerate.den = 1;

	if (stream->codecpar->codec_id == AV_CODEC_ID_H264) {

		if (av_opt_set(encoder->codecContext->priv_data, "preset", "ultrafast", 0) != 0) {

		}
	}

	if (this->formatContext->oformat->flags & AVFMT_GLOBALHEADER)
		encoder->codecContext->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;

	int ret = avcodec_open2(encoder->codecContext, codec, NULL);
	if (ret < 0) {
		delete encoder;
		return NULL;
	}

	if (avcodec_parameters_from_context(stream->codecpar, encoder->codecContext) < 0) {
		delete encoder;
		return NULL;
	}

	for (int i = 0; i < this->formatContext->nb_streams; i++) {

		if (this->formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
			this->videoStreamIndex = i;
		}
	}

	encoder->pixelFormat = codecInfo.pixelFormat;
	encoder->width = codecInfo.width;
	encoder->height = codecInfo.height;

	return encoder;
}

VideoEncoder* OutputContext::createHwEncoder(const VideoCodecInfo &codecInfo) {
	
	const_cast<VideoCodecInfo&>(codecInfo).pixelFormat = AV_PIX_FMT_NV12;

	HwEncoder *hwEncoder = new HwEncoder;

	AVCodec *avCodec = hwEncoder->getCodec(const_cast<VideoCodecInfo&>(codecInfo).hwAccelsName.toLocal8Bit().data());

	if (avCodec == NULL) {
		delete hwEncoder;
		return NULL;
	}

	this->outputFormat->video_codec = avCodec->id;

	AVStream *avStream = avformat_new_stream(this->formatContext, avCodec);
	if (avStream == NULL) {
		delete hwEncoder;
		return NULL;
	}

	VideoEncoder *encoder = new VideoEncoder;
	encoder->hwEncoder = hwEncoder;

	encoder->codecContext = avcodec_alloc_context3(avCodec);
	if (encoder->codecContext == NULL) {
		delete encoder;
		return NULL;
	}

	avStream->codecpar->codec_id = this->outputFormat->video_codec;
	avStream->codecpar->codec_type = AVMEDIA_TYPE_VIDEO;
	avStream->codecpar->width = codecInfo.width;
	avStream->codecpar->height = codecInfo.height;
	avStream->codecpar->format = encoder->hwEncoder->getPixelFormat();
	avStream->codecpar->bit_rate = codecInfo.bitrate;

	avcodec_parameters_to_context(encoder->codecContext, avStream->codecpar);

	encoder->codecContext->time_base.num = 1;
	encoder->codecContext->time_base.den = codecInfo.fps;
	encoder->codecContext->max_b_frames = 0;   
	encoder->codecContext->gop_size = 12;        
	encoder->codecContext->framerate.num = codecInfo.fps;
	encoder->codecContext->framerate.den = 1;

	if (encoder->hwEncoder->setHwFrameContext(encoder->codecContext, codecInfo) == false) {
		delete encoder;
		return NULL;
	}

	if (avStream->codecpar->codec_id == AV_CODEC_ID_H264) {

		if (av_opt_set(encoder->codecContext, "preset", "ultrafast", 0) != 0) {
		
		}
	}

	if (this->formatContext->oformat->flags & AVFMT_GLOBALHEADER)
		encoder->codecContext->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;

	if (avcodec_open2(encoder->codecContext, avCodec, NULL) < 0) {
		delete encoder;
		return NULL;
	}

	if (avcodec_parameters_from_context(avStream->codecpar, encoder->codecContext) < 0) {
		delete encoder;
		return NULL;
	}

	for (int i = 0; i < this->formatContext->nb_streams; i++) {

		if (this->formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
			this->videoStreamIndex = i;
		}
	}

	//swFormat
	encoder->pixelFormat = codecInfo.pixelFormat;
	encoder->width = codecInfo.width;
	encoder->height = codecInfo.height;

	return encoder;

}