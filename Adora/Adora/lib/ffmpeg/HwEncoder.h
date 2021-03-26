

#ifndef _HWENCODER_H
#define _HWENCODER_H

extern "C" {

#include <libavutil/hwcontext.h>
#include <libavcodec/avcodec.h>
}

class VideoCodecInfo;

class HwEncoder {

	friend class VideoEncoder;
	friend class OutputContext;

private:
	AVBufferRef *hwDeviceContext;
	AVHWDeviceType hwDeviceType;
	AVFrame *avFrame;
	bool avFramegetBuffered;

private:
	HwEncoder();
	~HwEncoder();

	void findHwEncoderName(AVCodecID codecId, char *hwEncoderName);
	AVPixelFormat getPixelFormat();

	bool setHwFrameContext(AVCodecContext *avCodecContext, const VideoCodecInfo &videoCodecInfo);

	bool allocFrame();


	AVCodec* findUseableCodec(const VideoCodecInfo &videoCodecInfo);

	AVCodec* getCodec(char *hwEncoderName);
	AVHWDeviceType getHWDeviceType(char *hwEncoderName);


	void convertDeviceTypeToString(char *string);

};



#endif //_HWENCODER_H