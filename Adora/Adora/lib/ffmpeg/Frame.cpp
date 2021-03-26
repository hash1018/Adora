

#include "Frame.h"

VideoFrame::VideoFrame(int width, int height, AVPixelFormat format) {

	this->frame = av_frame_alloc();
	this->frame->format = format;
	this->frame->width = width;
	this->frame->height = height;

	av_frame_get_buffer(this->frame, 32);
}

VideoFrame::~VideoFrame() {

	av_frame_free(&this->frame);
}

void VideoFrame::setPts(int pts) {

	this->frame->pts = pts;
}



AudioFrame::AudioFrame(AVSampleFormat sampleFormat, int frameSize, uint64_t channelLayout) {

	this->frame = av_frame_alloc();
	this->frame->format = sampleFormat;
	this->frame->nb_samples = frameSize;
	this->frame->channel_layout = channelLayout;

	av_frame_get_buffer(this->frame, 0);
}

AudioFrame::~AudioFrame() {

	av_frame_free(&this->frame);
}