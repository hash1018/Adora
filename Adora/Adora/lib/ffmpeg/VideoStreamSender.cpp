

#include "VideoStreamSender.h"
#include "ffmpeg-lib/OutputContext.h"
#include "multimedia-lib/VideoCaptureSource.h"
#include "ffmpeg-lib\Packet.h"
#include "ffmpeg-lib\Encoder.h"
#include "EncodeThread.h"
#include <qdebug.h>
#include "TimeCounter.h"


VideoStreamSender::VideoStreamSender()
	:status(NotRecording), readyToCaptureVideo(false) {

}

VideoStreamSender::~VideoStreamSender() {

	if (this->status != Status::NotRecording)
		this->stop();
}


void VideoStreamSender::setVideoCodecInfo(const VideoCodecInfo &videoCodecInfo) {

	if (this->status != Status::NotRecording)
		return;

	this->videoCodecInfo = videoCodecInfo;
}


void VideoStreamSender::setVideoParameter(const VideoParameter &videoParameter) {

	if (this->status != Status::NotRecording)
		return;

	this->videoParameter = videoParameter;
}

void VideoStreamSender::setIp(const QString &ip) {

	if (this->status != Status::NotRecording)
		return;

	this->ip = ip;
}

void VideoStreamSender::setPort(int port) {

	if (this->status != Status::NotRecording)
		return;

	this->port = port;
}

bool VideoStreamSender::start() {

	if (this->status != Status::NotRecording) {

		//qDebug() << "already start";
		return false;
	}

	this->initTimer();

	this->outputContext = new OutputContext;

	QString url = "rtp://" + this->ip + ":" + QString::number(this->port);

	if (this->outputContext->create(url.toUtf8(), "rtp") == false)
		return false;

	if ((this->videoEncoder = this->outputContext->createEncoder(this->videoCodecInfo)) == NULL)
		return false;

	if (this->outputContext->open() == false)
		return false;


	if (this->initVideo() == false)
		return false;

	this->videoEncodeThread->start();
	this->videoCaptureSource->start();

	return true;
}

bool VideoStreamSender::stop() {

	if (this->status == Status::NotRecording) {

		//qDebug() << "already finished";
		return false;
	}

	this->closeTimer();

	this->closeVideo();
	this->readyToCaptureVideo = false;


	this->mainTime.clear();


	VideoPacket videoPacket;
	for (;;) {

		if (this->videoEncoder->getDelayedPacket(&videoPacket) == true) {

			this->outputContext->writePacket(&videoPacket);
		}
		else {

			break;
		}
	}

	this->outputContext->close();
	this->outputContext->destroy();
	delete this->outputContext;
	this->outputContext = nullptr;

	delete this->videoEncoder;
	this->videoEncoder = nullptr;

	this->status = Status::NotRecording;

	emit this->stopped();

	return true;
}

bool VideoStreamSender::resume() {

	if (this->status != Status::Pausing) {

		//qDebug() << "not pausing";
		return false;
	}

	if (this->videoCaptureSource->init() == false) {

		this->videoCaptureSource->close();

		return false;
	}

	this->videoCaptureSource->start();
	this->videoEncodeThread->start();

	return true;
}

bool VideoStreamSender::pause() {


	if (this->status != Status::Recording) {

		//qDebug() << "not recording";
		return false;
	}

	this->timeThread->quit();
	this->timeThread->wait();

	this->videoEncodeThread->quit();
	this->videoEncodeThread->wait();

	this->videoCaptureSource->quit();
	this->videoCaptureSource->wait();
	this->videoCaptureSource->close();

	this->readyToCaptureVideo = false;

	this->status = Status::Pausing;
	emit this->paused();

	return true;
}


void VideoStreamSender::videoCaptureReady() {

	this->readyToCaptureVideo = true;

	if (this->status == Status::NotRecording) {

		this->status = Status::Recording;

		this->timeThread->start();

		emit this->started();
	}
	else if (this->status == Status::Pausing) {

		this->status = Status::Recording;

		this->timeThread->start();

		emit this->resumed();
	}
}

bool VideoStreamSender::initVideo() {

	this->videoCaptureSource = new VideoCaptureSource(this->videoCodecInfo.fps, this->videoParameter, this);
	if (this->videoCaptureSource->init() == false) {

		this->videoCaptureSource->close();

		delete this->videoCaptureSource;
		this->videoCaptureSource = nullptr;

		return false;
	}

	connect(this->videoCaptureSource, &VideoCaptureSource::captureReady, this, &VideoStreamSender::videoCaptureReady);
	//connect(this->videoCaptureSource, &VideoCaptureSource::captureAccessLost, this, &VideoRecorder::videoCaptureAccessLost);

	this->videoEncodeThread = new VideoEncodeThread(&this->mainTime, this->videoCodecInfo.fps, this->videoCaptureSource, this->videoEncoder, this->outputContext, this);


	return true;
}

void VideoStreamSender::closeVideo() {

	this->videoEncodeThread->quit();
	this->videoEncodeThread->wait();

	delete this->videoEncodeThread;
	this->videoEncodeThread = nullptr;


	this->videoCaptureSource->quit();
	this->videoCaptureSource->wait();

	this->videoCaptureSource->close();

	delete this->videoCaptureSource;
	this->videoCaptureSource = nullptr;
}

void VideoStreamSender::initTimer() {

	this->timeThread = new QThread(this);
	this->timeCounter = new TimeCounter(&this->mainTime);
	this->timeCounter->moveToThread(this->timeThread);

	qRegisterMetaType<Time>("Time&");
	connect(this->timeCounter, SIGNAL(timePassed(Time&)), this, SIGNAL(timePassed(Time&)));
	connect(this->timeThread, &QThread::started, this->timeCounter, &TimeCounter::start);
	connect(this->timeThread, &QThread::finished, this->timeCounter, &TimeCounter::finish);
}

void VideoStreamSender::closeTimer() {

	this->timeThread->quit();
	this->timeThread->wait();
	delete this->timeCounter;
	this->timeCounter = nullptr;
	delete this->timeThread;
	this->timeThread = nullptr;
}


