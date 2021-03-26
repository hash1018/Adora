

#ifndef _AUDIOFORMATCONVERTER_H
#define _AUDIOFORMATCONVERTER_H

extern"C" {

#include <libswresample/swresample.h>
#include <libavutil/opt.h>
}

class AudioFrame;
class AudioFormatConverter {

private:
	SwrContext *context;

private:
	AVSampleFormat inFormat;
	AVSampleFormat outFormat;


public:
	AudioFormatConverter(uint64_t channelLayout, int sampleRate, AVSampleFormat inFormat, AVSampleFormat outFormat);
	~AudioFormatConverter();

	void resample(unsigned char *data, AudioFrame *frame);
	

};


#endif //_AUDIOFORMATCONVERTER_H
