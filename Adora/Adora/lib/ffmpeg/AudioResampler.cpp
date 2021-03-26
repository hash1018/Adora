

#include "AudioResampler.h"
#include <qdebug.h>

AudioResampler::AudioResampler()
	:initialized(false), swrContext(NULL), outData(NULL) {

}

AudioResampler::~AudioResampler() {


}

bool AudioResampler::init(int inChannel, int inSampleRate, int inBitsPerSample, int outChannel, int outSampleRate, AVSampleFormat outSampleFormat) {

	if (this->initialized == true)
		return false;


	this->initialized = true;

	this->outMaxFrameSize = -1;

	this->inChannel = inChannel;
	this->inSampleRate = inSampleRate;
	this->inBitsPerSample = inBitsPerSample;
	this->outChannel = outChannel;
	this->outSampleRate = outSampleRate;
	this->outSampleFormat = outSampleFormat;


	if (this->swrContext != NULL) {
	
		swr_free(&this->swrContext);
		this->swrContext = NULL;
	}

	this->swrContext = swr_alloc();
	if (swrContext == NULL) {

		this->finish();
		return false;
	}


	av_opt_set_int(this->swrContext, "in_channel_layout", AudioResampler::getChannelLayout(this->inChannel), 0);
	av_opt_set_int(this->swrContext, "in_sample_rate", this->inSampleRate, 0);
	av_opt_set_sample_fmt(this->swrContext, "in_sample_fmt", AudioResampler::getSampleFormat(this->inBitsPerSample), 0);

	av_opt_set_int(this->swrContext, "out_channel_layout", AudioResampler::getChannelLayout(this->outChannel), 0);
	av_opt_set_int(this->swrContext, "out_sample_rate", this->outSampleRate, 0);
	av_opt_set_sample_fmt(this->swrContext, "out_sample_fmt", this->outSampleFormat, 0);

	if (swr_init(this->swrContext) < 0) {

		this->finish();
		return false;
	}

	return true;
}

void AudioResampler::finish() {

	if (this->initialized == false)
		return;

	this->initialized = false;

	this->outFrameSize = -1;

	if (this->swrContext != NULL) {
	
		swr_free(&this->swrContext);
		this->swrContext = NULL;
	}

	if (this->outData != NULL) {
	
		av_freep(&this->outData[0]);
		this->outData = NULL;
	}

}


bool AudioResampler::resample(uint8_t *inBuffer, int inFrameSize, const uint8_t* *outBuffer, int &bufferSize) {

	/* compute the number of converted samples: buffering is avoided
	* ensuring that the output buffer will contain at least all the
	* converted input samples */

	int bytesPerSample = this->inBitsPerSample / 8;

	if (this->outMaxFrameSize == -1) {

		this->outFrameSize = av_rescale_rnd(inFrameSize, this->outSampleRate, this->inSampleRate, AV_ROUND_UP);
		this->outMaxFrameSize = this->outFrameSize;
		int lineSize;
		if (av_samples_alloc_array_and_samples(&this->outData, &lineSize, this->outChannel, this->outFrameSize, this->outSampleFormat, 0) < 0) {

			qDebug() << "failed alloc array and samples";
		}
	}
	

	this->outFrameSize = av_rescale_rnd(swr_get_delay(this->swrContext, this->inSampleRate) + inFrameSize, this->outSampleRate, this->inSampleRate, AV_ROUND_UP);
	
	if (this->outFrameSize > this->outMaxFrameSize) {
	
		av_freep(&this->outData[0]);
		int lineSize;

		if (av_samples_alloc(this->outData, &lineSize, this->outChannel, this->outFrameSize, this->outSampleFormat, 1) < 0) {
		
			qDebug() << "failed alloc samples";
		}

		this->outMaxFrameSize = this->outFrameSize;
	}

	int outFrameSize = swr_convert(this->swrContext, this->outData, this->outFrameSize, (const uint8_t**)&inBuffer, inFrameSize);

	*outBuffer = this->outData[0];
	
	int lineSize;
	bufferSize = av_samples_get_buffer_size(&lineSize, this->outChannel, outFrameSize, this->outSampleFormat, 1);

	//qDebug() << " resampler  inFrameSize   " << inFrameSize << " outFrameSize  " << outFrameSize << "bufferSize " << bufferSize;
	return true;
}


int64_t AudioResampler::getChannelLayout(int channels) {

	return av_get_default_channel_layout(channels);
}

AVSampleFormat AudioResampler::getSampleFormat(int bitsPerSample) {

	AVSampleFormat sampleFormat = AV_SAMPLE_FMT_NONE;

	if (bitsPerSample == 8) {
	
		sampleFormat = AVSampleFormat::AV_SAMPLE_FMT_U8;
	}
	else if (bitsPerSample == 16) {
	
		sampleFormat = AVSampleFormat::AV_SAMPLE_FMT_S16;
	}
	else if (bitsPerSample == 32) {
	
		sampleFormat = AVSampleFormat::AV_SAMPLE_FMT_S32;

		//sampleFormat = AVSampleFormat::AV_SAMPLE_FMT_FLT;

		//sampleFormat = AVSampleFormat::AV_SAMPLE_FMT_FLT;
	}

	qDebug() << "sampleFormat " << sampleFormat;
	
	return sampleFormat;
}