

#include "Encoder.h"
#include "Frame.h"
#include "Packet.h"
#include "HwEncoder.h"

VideoEncoder::VideoEncoder()
	:codecContext(NULL), hwEncoder(NULL) {

}

VideoEncoder::~VideoEncoder() {

	if (this->codecContext != NULL)
		avcodec_free_context(&this->codecContext);

	if (this->hwEncoder != NULL)
		delete this->hwEncoder;
}



bool VideoEncoder::encode(VideoFrame *frame, VideoPacket *packet) {

	AVFrame *avFrame;

	if (this->hwEncoder != NULL) {
	
		avFrame = this->convertHwFrame(frame);

		if (avFrame == NULL)
			return false;
	}
	else {
	
		avFrame = frame->frame;
	}

	avFrame->pts = frame->frame->pts;


	if (avcodec_send_frame(this->codecContext, avFrame) < 0) {
		return false;
	}


	av_packet_unref(packet->packet);
	packet->packet->data = NULL;
	packet->packet->size = 0;
	packet->packet->flags |= AV_PKT_FLAG_KEY;

	int ret;
	if (ret=avcodec_receive_packet(this->codecContext, packet->packet) < 0) {
		
		
	}

	packet->codecTimeBase = this->codecContext->time_base;

	return true;
}

bool VideoEncoder::getDelayedPacket(VideoPacket *packet) {

	
	av_packet_unref(packet->packet);
	packet->packet->data = NULL;
	packet->packet->size = 0;
	packet->packet->flags |= AV_PKT_FLAG_KEY;
	
	avcodec_send_frame(this->codecContext, NULL);
	if (avcodec_receive_packet(this->codecContext, packet->packet) < 0) {
	
		
		return false;
	}

	packet->codecTimeBase = this->codecContext->time_base;
	return true;
	
}


AVFrame* VideoEncoder::convertHwFrame(VideoFrame *frame) {

	if (this->hwEncoder->allocFrame() == false) {
	
		return NULL;
	}

	if (this->hwEncoder->avFramegetBuffered == false) {
		if (av_hwframe_get_buffer(this->codecContext->hw_frames_ctx, this->hwEncoder->avFrame, 0) < 0) {
		
			return NULL;
		}
		this->hwEncoder->avFramegetBuffered = true;
	}

	if (av_hwframe_transfer_data(this->hwEncoder->avFrame, frame->frame, 0) < 0) {
		return NULL;
	}

	return this->hwEncoder->avFrame;
}



/////////////////////////////////////////////////////////////////


AudioEncoder::AudioEncoder()
	:codecContext(NULL) {

}

AudioEncoder::~AudioEncoder() {

	if (this->codecContext != NULL)
		avcodec_free_context(&this->codecContext);

}

bool AudioEncoder::encode(AudioFrame *frame, AudioPacket *packet) {

	if (avcodec_send_frame(this->codecContext, frame->frame) < 0)
		return false;

	av_packet_unref(packet->packet);
	packet->packet->data = NULL;
	packet->packet->size = 0;
	packet->packet->flags |= AV_PKT_FLAG_KEY;

	int ret;
	if (ret = avcodec_receive_packet(this->codecContext, packet->packet) < 0) {


	}

	return true;
}


bool AudioEncoder::getDelayedPacket(AudioPacket *packet) {

	av_packet_unref(packet->packet);
	packet->packet->data = NULL;
	packet->packet->size = 0;
	packet->packet->flags |= AV_PKT_FLAG_KEY;

	avcodec_send_frame(this->codecContext, NULL);
	if (avcodec_receive_packet(this->codecContext, packet->packet) < 0) {

		return false;
	}

	return true;
}