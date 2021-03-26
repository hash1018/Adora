

#ifndef _OUTPUTCONTEXT_H
#define _OUTPUTCONTEXT_H

#include <qmutex.h>

extern"C" {
#include <libavformat/avformat.h>

}

class VideoCodecInfo;
class VideoEncoder;
class VideoPacket;


class AudioCodecInfo;
class AudioEncoder;
class AudioPacket;

class OutputContext {

private:
	QMutex packetMutex;

private:
	AVFormatContext *formatContext;
	AVOutputFormat *outputFormat;


	int videoStreamIndex;
	int audioStreamIndex;
	int audioPacketCount;


public:
	OutputContext();
	~OutputContext();


	bool create(const char *fileName, const char *formatName = NULL);
	VideoEncoder* createEncoder(const VideoCodecInfo &codecInfo);
	AudioEncoder* createEncoder(const AudioCodecInfo &codecInfo);
	bool open();

	bool writePacket(VideoPacket *packet);
	bool writePacket(AudioPacket *packet);

	bool close();

	bool destroy();



private:
	VideoEncoder* createSwEncoder(const VideoCodecInfo &codecInfo);
	VideoEncoder* createHwEncoder(const VideoCodecInfo &codecInfo);

};



#endif //_OUTPUTCONTEXT_H
