

#ifndef _PACKET_H
#define _PACKET_H


extern "C" {

#include <libavcodec/avcodec.h>
}

class VideoPacket {

	friend class VideoEncoder;
	friend class OutputContext;

private:
	AVPacket *packet;
	AVRational codecTimeBase;

public:
	VideoPacket();
	~VideoPacket();

};


class AudioPacket {

	friend class AudioEncoder;
	friend class OutputContext;

private:
	AVPacket *packet;
	int sampleRate;
	int frameSize;
	
public:
	AudioPacket(int sampleRate, int frameSize);
	~AudioPacket();

};

#endif //_PACKET_H
