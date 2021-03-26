

#ifndef _ENCODER_H
#define _ENCODER_H

#include "HwEncoder.h"

extern"C" {
#include <libavcodec/avcodec.h>
}

class VideoFrame;
class VideoPacket;

class AudioFrame;
class AudioPacket;


class VideoEncoder {

	friend class OutputContext;

private:
	AVCodecContext *codecContext;

private:
	HwEncoder *hwEncoder;

	int width;
	int height;

	//**swPixelFormat
	AVPixelFormat pixelFormat;

private:
	VideoEncoder();

public:
	~VideoEncoder();


	bool encode(VideoFrame *frame, VideoPacket *packet);
	
	bool getDelayedPacket(VideoPacket *packet);



public:
	inline int getWidth() const { return this->width; }
	inline int getHeight() const { return this->height; }
	inline AVPixelFormat getFormat() const { return this->pixelFormat; }



private:
	AVFrame* convertHwFrame(VideoFrame *frame);
	
};



//////////////////////////////////////////////////////////


class AudioEncoder {

	friend class OutputContext;

private:
	AVCodecContext *codecContext;

private:
	AudioEncoder();

public:
	~AudioEncoder();

	bool encode(AudioFrame *frame, AudioPacket *packet);

	bool getDelayedPacket(AudioPacket *packet);

public:
	inline AVSampleFormat getFormat() const { return this->codecContext->sample_fmt; }
	inline int getBitrate() const { return this->codecContext->bit_rate; }
	inline int getSampleRate() const { return this->codecContext->sample_rate; }
	inline int getFrameSize() const { return this->codecContext->frame_size; }
	inline uint64_t getChannelLayout() const { return this->codecContext->channel_layout; }
};



#endif //_ENCODER_H
