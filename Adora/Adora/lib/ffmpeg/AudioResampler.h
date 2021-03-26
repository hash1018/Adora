

#ifndef _AUDIORESAMPLER_H
#define _AUDIORESAMPLER_H


extern "C" {
#include <libavutil/samplefmt.h>
#include <libavutil/opt.h>
#include <libavutil/channel_layout.h>
#include <libswresample/swresample.h>
}



class AudioResampler {


private:
	bool initialized;

private:
	SwrContext *swrContext;

private:
	int inChannel;
	int inSampleRate;
	int inBitsPerSample;
	int outChannel;
	int outSampleRate;
	AVSampleFormat outSampleFormat;


private:
	int outMaxFrameSize;
	int outFrameSize;
	uint8_t **outData;

public:
	AudioResampler();
	~AudioResampler();

	bool init(int inChannel, int inSampleRate, int inBitsPerSample, int outChannel, int outSampleRate, AVSampleFormat outSampleFormat);

	void finish();

	bool resample(uint8_t *inBuffer, int inFrameSize, const uint8_t* *outBuffer, int &bufferSize);



public:
	static int64_t getChannelLayout(int channels);
	static AVSampleFormat getSampleFormat(int bitsPerSample);
};

#endif //_AUDIORESAMPLER_H
