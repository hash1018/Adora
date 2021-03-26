

#include "Packet.h"

VideoPacket::VideoPacket() {

	this->packet = av_packet_alloc();
	av_init_packet(this->packet);

}

VideoPacket::~VideoPacket() {

	av_packet_free(&this->packet);
}


AudioPacket::AudioPacket(int sampleRate, int frameSize)
	:sampleRate(sampleRate), frameSize(frameSize) {

	this->packet = av_packet_alloc();
	av_init_packet(this->packet);
}

AudioPacket::~AudioPacket() {

	av_packet_free(&this->packet);
}