
#include "CodecInfo.h"

VideoCodecInfo::VideoCodecInfo()
	:width(0), height(0), bitrate(0), fps(0),
	codecID(AVCodecID::AV_CODEC_ID_H264), pixelFormat(AV_PIX_FMT_YUV420P), useHwAccels(false) {

}

VideoCodecInfo::~VideoCodecInfo() {


}

VideoCodecInfo& VideoCodecInfo::operator=(const VideoCodecInfo &other) {

	this->width = other.width;
	this->height = other.height;
	this->bitrate = other.bitrate;
	this->fps = other.fps;
	this->codecID = other.codecID;
	this->pixelFormat = other.pixelFormat;
	
	this->useHwAccels = other.useHwAccels;
	this->hwAccelsName = other.hwAccelsName;

	return *this;
}


////////////////////////////////////////////////////////////////////////


AudioCodecInfo::AudioCodecInfo()
	:sampleRate(44100), bitRate(64000), channels(2),
	codecID(AV_CODEC_ID_AAC), sampleFormat(AV_SAMPLE_FMT_FLTP) {


}

AudioCodecInfo::AudioCodecInfo(const AudioCodecInfo &other)
	:sampleRate(other.sampleRate), bitRate(other.bitRate), channels(other.channels),
	codecID(other.codecID), sampleFormat(other.sampleFormat) {


}

AudioCodecInfo::~AudioCodecInfo() {


}

AudioCodecInfo& AudioCodecInfo::operator=(const AudioCodecInfo &other) {

	this->sampleRate = other.sampleRate;
	this->bitRate = other.bitRate;
	this->channels = other.channels;
	this->codecID = other.codecID;
	this->sampleFormat = other.sampleFormat;

	return *this;
}