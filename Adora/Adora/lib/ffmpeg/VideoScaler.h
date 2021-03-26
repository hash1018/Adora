

#ifndef _VIDEOSCALER_H
#define _VIDEOSCALER_H

extern "C" {

#include <libavutil/pixfmt.h>
#include <libswscale/swscale.h>
}

class VideoFrame;

class VideoScaler {

private:
	SwsContext *context;

private:
	int inWidth;
	int inHeight;
	AVPixelFormat inFormat;
	int outWidth;
	int outHeight;
	AVPixelFormat outFormat;


public:
	VideoScaler(int inWidth, int inHeight, AVPixelFormat inFormat, int outWidth, int outHeight, AVPixelFormat outFormat);
	~VideoScaler();


	bool scale(unsigned char *data, int lineSize, VideoFrame *frame);

	bool rescale(int inWidth, int inHeight, AVPixelFormat inFormat, int outWidth, int outHeight, AVPixelFormat outFormat);


};



#endif //_VIDEOSCALER_H
