

#ifndef _FRAME_H
#define _FRAME_H

extern "C" {
#include <libavutil/frame.h>
}

class VideoFrame {

	friend class VideoEncoder;
	friend class VideoScaler;

private:
	AVFrame *frame;

public:
	VideoFrame(int width, int height, AVPixelFormat format);
	~VideoFrame();


	void setPts(int pts);
};


class AudioFrame {

	friend class AudioEncoder;
	friend class AudioFormatConverter;

private:
	AVFrame *frame;

public:
	AudioFrame(AVSampleFormat sampleFormat, int frameSize, uint64_t channelLayout);
	~AudioFrame();

};


#endif //_FRAME_H
