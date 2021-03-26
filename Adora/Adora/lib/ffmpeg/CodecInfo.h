

#ifndef _CODECINFO_H
#define _CODECINFO_H

extern "C" {

#include <libavcodec\avcodec.h>
#include <libavutil\pixfmt.h>

}

#include <qstring.h>

class VideoCodecInfo {

public:
	int width;
	int height;
	int bitrate;
	int fps;
	AVCodecID codecID;
	AVPixelFormat pixelFormat;
	
public:
	bool useHwAccels;
	QString hwAccelsName;

public:
	VideoCodecInfo();
	~VideoCodecInfo();

	VideoCodecInfo& operator=(const VideoCodecInfo &other);

};

class AudioCodecInfo {

public:
	int sampleRate;
	int bitRate;
	int channels;
	AVCodecID codecID;
	AVSampleFormat sampleFormat;

public:
	AudioCodecInfo();
	AudioCodecInfo(const AudioCodecInfo &other);
	~AudioCodecInfo();

	AudioCodecInfo& operator=(const AudioCodecInfo &other);
};

#endif //_CODECINFO_H
