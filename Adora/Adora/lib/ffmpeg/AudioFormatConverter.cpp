
#include "AudioFormatConverter.h"
#include "Frame.h"


AudioFormatConverter::AudioFormatConverter(uint64_t channelLayout, int sampleRate, AVSampleFormat inFormat, AVSampleFormat outFormat)
	:inFormat(inFormat), outFormat(outFormat) {

	this->context = swr_alloc();
	av_opt_set_int(this->context, "in_channel_layout", channelLayout, 0);
	av_opt_set_int(this->context, "out_channel_layout", channelLayout, 0);
	av_opt_set_int(this->context, "in_sample_rate", sampleRate, 0);
	av_opt_set_int(this->context, "out_sample_rate", sampleRate, 0);
	av_opt_set_sample_fmt(this->context, "in_sample_fmt", inFormat, 0);
	av_opt_set_sample_fmt(this->context, "out_sample_fmt", outFormat, 0);
	swr_init(this->context);
}

AudioFormatConverter::~AudioFormatConverter() {

	swr_free(&this->context);
}


void AudioFormatConverter::resample(unsigned char *data, AudioFrame *frame) {

	swr_convert(this->context, frame->frame->data, frame->frame->nb_samples, (const uint8_t**)&data, frame->frame->nb_samples);
}