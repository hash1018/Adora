
#include "Parameter.h"

VideoParameter::VideoParameter()
	:x(0), y(0), width(0), height(0), drawCursor(false) {

}

VideoParameter::VideoParameter(const VideoParameter &other)
	: x(other.x), y(other.y), width(other.width), height(other.height), drawCursor(other.drawCursor) {

}

VideoParameter::~VideoParameter() {


}

VideoParameter& VideoParameter::operator=(const VideoParameter &other) {

	this->x = other.x;
	this->y = other.y;
	this->width = other.width;
	this->height = other.height;
	this->drawCursor = other.drawCursor;

	return *this;
}

////////////////////////////////////////////////////////////////////////////

AudioParameter::AudioParameter()
	:muted(false) {


}

AudioParameter::AudioParameter(const AudioParameter &other)
	: deviceName(other.deviceName), muted(other.muted), type(other.type) {


}

AudioParameter::~AudioParameter() {

}

AudioParameter& AudioParameter::operator=(const AudioParameter &other) {

	this->type = other.type;
	this->deviceName = other.deviceName;
	this->muted = other.muted;

	return *this;
}