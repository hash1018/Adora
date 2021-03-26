

#include "VideoScaler.h"
#include "Frame.h"

VideoScaler::VideoScaler(int inWidth, int inHeight, AVPixelFormat inFormat, int outWidth, int outHeight, AVPixelFormat outFormat) {

	this->inWidth = inWidth;
	this->inHeight = inHeight;
	this->inFormat = inFormat;
	this->outWidth = outWidth;
	this->outHeight = outHeight;
	this->outFormat = outFormat;

	this->context = sws_getContext(inWidth, inHeight, inFormat, outWidth, outHeight, outFormat, SWS_BICUBIC, 0, 0, 0);
}

VideoScaler::~VideoScaler() {

	sws_freeContext(this->context);
}


bool VideoScaler::scale(unsigned char *data, int lineSize, VideoFrame *frame) {
	
	int line[1] = { lineSize, };
	sws_scale(this->context, (const uint8_t * const *)&data, line, 0, this->inHeight,
		frame->frame->data, frame->frame->linesize);
	return true;
}

bool VideoScaler::rescale(int inWidth, int inHeight, AVPixelFormat inFormat, int outWidth, int outHeight, AVPixelFormat outFormat) {

	sws_freeContext(this->context);

	this->inWidth = inWidth;
	this->inHeight = inHeight;
	this->inFormat = inFormat;
	this->outWidth = outWidth;
	this->outHeight = outHeight;
	this->outFormat = outFormat;

	this->context = sws_getContext(inWidth, inHeight, inFormat, outWidth, outHeight, outFormat, SWS_BICUBIC, 0, 0, 0);

	return true;
}