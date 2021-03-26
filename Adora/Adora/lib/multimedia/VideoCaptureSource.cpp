

#include "VideoCaptureSource.h"
#include <qtimer.h>
#include <qdebug.h>
#include <qthread.h>

VideoCaptureSource::VideoCaptureSource(int fps, const VideoParameter &parameter, QObject *parent)
	:QThread(parent), fps(fps), parameter(parameter), initialized(false) {

	this->bits = nullptr;

	this->copyBuffer = nullptr;
}



VideoCaptureSource::~VideoCaptureSource() {

	qDebug() << "VideoCaptureSource ~ VideoCaptureSource";

}

void VideoCaptureSource::setVideoParameter(const VideoParameter &parameter) {

	this->mutex.lock();
	this->parameter = parameter;

	if (this->initialized == true) {
	
		this->clearCaptureInfo();
		this->initCaptureInfo();
	}

	this->mutex.unlock();
}

void VideoCaptureSource::copyToBuffer(uint8_t* (*buffer)) {

	this->copyMutex.lock();

	memcpy((*buffer), this->copyBuffer, this->parameter.width*this->parameter.height * 4);

	this->copyMutex.unlock();
}

void VideoCaptureSource::getSize(int &width, int &height) {

	this->mutex.lock();

	width = this->parameter.width;
	height = this->parameter.height;

	this->mutex.unlock();
}

bool VideoCaptureSource::init() {

	qDebug() << "VideoCaptureSource ::init";

	this->mutex.lock();

	bool result = this->initCaptureInfo();

	this->mutex.unlock();

	return result;
}

bool VideoCaptureSource::close() {
	qDebug() << "VideoCaptureSource::close";

	this->mutex.lock();

	this->clearCaptureInfo();

	this->mutex.unlock();


	return true;
}


#include <qelapsedtimer.h>
void VideoCaptureSource::run() {

	qDebug() << "VideoCaptureSource::run    " << QThread::currentThreadId();
	QThread::currentThread()->setPriority(QThread::Priority::HighPriority);

	this->requestToFinish = false;

	emit this->captureReady();
	quint64 elapsed;

	QElapsedTimer timer;

	for (;;) {
	
		if (this->requestToFinish == true)
			return;
	
		this->mutex.lock();

		timer.start();
		this->capture();
		elapsed = timer.elapsed();

		this->mutex.unlock();

		if (elapsed > (1000 / this->fps)) {
			QThread::msleep(elapsed - (1000 / this->fps));
		}

	}

}


void VideoCaptureSource::clearCaptureInfo() {

#ifdef Q_OS_WIN


	this->gdiManager.close();
	


	////////////////////////////////////

	this->copyMutex.lock();

	if (this->copyBuffer != nullptr) {
		delete[] this->copyBuffer;
		this->copyBuffer = nullptr;
	}

	this->copyMutex.unlock();

	this->initialized = false;

#endif

}

bool VideoCaptureSource::initCaptureInfo() {

#ifdef Q_OS_WIN


	int maxWidth = GetSystemMetrics(SM_CXVIRTUALSCREEN);
	int maxHeight = GetSystemMetrics(SM_CYVIRTUALSCREEN);

	if (this->parameter.width <= 0 || this->parameter.width > maxWidth)
		this->parameter.width = maxWidth;

	if (this->parameter.height <= 0 || this->parameter.height > maxHeight)
		this->parameter.height = maxHeight;

	this->gdiManager.init(&this->bits, this->parameter.width, this->parameter.height);
	
	this->copyMutex.lock();

	this->copyBuffer = new unsigned char[this->parameter.width*this->parameter.height * 4];
	this->copyMutex.unlock();

#endif

	this->initialized = true;

	return true;
}


void VideoCaptureSource::capture() {

#ifdef Q_OS_WIN


	//////////////////////////////////////////////////////////

	this->gdiManager.capture(this->parameter.x, this->parameter.y, this->parameter.width, this->parameter.height, this->parameter.drawCursor);
	

	this->copyMutex.lock();
	memcpy(this->copyBuffer, this->bits, this->parameter.width*this->parameter.height * 4);
	this->copyMutex.unlock();

#endif

}
