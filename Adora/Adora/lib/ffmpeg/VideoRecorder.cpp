

#include "VideoRecorder.h"
#include "lib/ffmpeg/OutputContext.h"
#include "lib/multimedia/VideoCaptureSource.h"
#include "lib/ffmpeg/Packet.h"
#include "lib/ffmpeg/Encoder.h"
#include "EncodeThread.h"
#include <qdebug.h>
#include "lib/multimedia/AudioCaptureSource.h"
#include "TimeCounter.h"


VideoRecorder::VideoRecorder()
	:status(NotRecording), readyToCaptureVideo(false), readyToCaptureAudio(false), readyCaptureAudioCount(0) {

}

VideoRecorder::~VideoRecorder() {

	if (this->status != Status::NotRecording)
		this->stop();
}


void VideoRecorder::setVideoCodecInfo(const VideoCodecInfo &videoCodecInfo) {

	if (this->status != Status::NotRecording)
		return;

	this->videoCodecInfo = videoCodecInfo;
}


void VideoRecorder::setVideoParameter(const VideoParameter &videoParameter) {

	if (this->status != Status::NotRecording)
		return;

	this->videoParameter = videoParameter;
}

void VideoRecorder::changeVideoParameter(const VideoParameter &videoParameter) {

	if (this->status == Status::Pausing) {
	
		this->videoParameter = videoParameter;
		this->videoCaptureSource->setVideoParameter(videoParameter);
	}

}

void VideoRecorder::setAudioCodecInfo(const AudioCodecInfo &audioCodecInfo) {

	if (this->status != Status::NotRecording)
		return;

	this->audioCodecInfo = audioCodecInfo;
}

void VideoRecorder::setAudioParameter(const QList<AudioParameter> &audioParameterList) {

	if (this->status != Status::NotRecording)
		return;

	this->audioParameterList = audioParameterList;
}

bool VideoRecorder::setAudioMuted(const QString deviceName, bool muted) {

	if (this->audioCaptureSourceList.size() == 0)
		return false;

	for (int i = 0; i < this->audioCaptureSourceList.size(); i++) {

		if (this->audioCaptureSourceList.at(i)->getDeviceName() == deviceName) {

			this->audioCaptureSourceList.at(i)->setMuted(muted);
			break;
		}
	}

	return true;
}

void VideoRecorder::setFilePath(const QString &filePath) {

	if (this->status != Status::NotRecording)
		return;

	this->filePath = filePath;
}

bool VideoRecorder::start() {

	if (this->status != Status::NotRecording) {

		//qDebug() << "already start";
		return false;
	}

	this->initTimer();

	this->outputContext = new OutputContext;
	
	if (this->outputContext->create(this->filePath.toUtf8()) == false)
		return false;
	
	if ((this->videoEncoder = this->outputContext->createEncoder(this->videoCodecInfo)) == NULL)
		return false;

	if (this->audioParameterList.size() > 0) {
	
		if ((this->audioEncoder = this->outputContext->createEncoder(this->audioCodecInfo)) == NULL)
			return false;
	}
		
	if (this->outputContext->open() == false)
		return false;


	if (this->initVideo() == false)
		return false;

	if (this->audioParameterList.size() > 0) {

		if (this->initAudio() == false)
			return false;
	}

	this->videoEncodeThread->start();
	this->videoCaptureSource->start();

	if (this->audioCaptureSourceList.size() != 0) {

		this->audioEncodeThread->start();

		for (int i = 0; i < this->audioCaptureSourceList.size(); i++) {

			this->audioCaptureSourceList.at(i)->start();
		}
	}


	return true;
}

bool VideoRecorder::stop() {

	if (this->status == Status::NotRecording) {

		//qDebug() << "already finished";
		return false;
	}

	this->closeTimer();

	this->closeVideo();
	this->readyToCaptureVideo = false;

	this->closeAudio();
	this->readyToCaptureAudio = false;

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

	if (this->audioParameterList.size() > 0) {
	
		AudioPacket audioPacket(this->audioEncoder->getSampleRate(), this->audioEncoder->getFrameSize());
		for (;;) {

			if (this->audioEncoder->getDelayedPacket(&audioPacket) == true) {

				this->outputContext->writePacket(&audioPacket);
			}
			else {

				break;
			}
		}
	}

	this->outputContext->close();
	this->outputContext->destroy();
	delete this->outputContext;
	this->outputContext = nullptr;

	delete this->videoEncoder;
	this->videoEncoder = nullptr;

	if (this->audioParameterList.size() > 0) {
	
		delete this->audioEncoder;
		this->audioEncoder = nullptr;
	}

	this->status = Status::NotRecording;

	emit this->stopped();

	return true;
}

bool VideoRecorder::resume() {

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

	if (this->audioCaptureSourceList.size() != 0) {

		this->audioEncodeThread->start();

		for (int i = 0; i < this->audioCaptureSourceList.size(); i++) {

			this->audioCaptureSourceList.at(i)->start();
		}
	}

	return true;
}

bool VideoRecorder::pause() {


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



	if (this->audioCaptureSourceList.size() > 0) {

		for (int i = 0; i < this->audioCaptureSourceList.size(); i++) {

			this->audioCaptureSourceList.at(i)->quit();
			this->audioCaptureSourceList.at(i)->wait();
		}

		//AudioEncodeThread quit ,wait should be done last.
		this->audioEncodeThread->quit();
		this->audioEncodeThread->wait();

		this->readyToCaptureAudio = false;

		this->readyCaptureAudioCount = 0;
	}


	this->status = Status::Pausing;
	emit this->paused();

	return true;
}


void VideoRecorder::videoCaptureReady() {

	this->readyToCaptureVideo = true;

	if (this->audioCaptureSourceList.size() > 0) {

		if (this->readyToCaptureAudio == true) {

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
	}
	else {

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

}

void VideoRecorder::audioCaptureReady() {

	this->readyCaptureAudioCount++;

	if (this->readyCaptureAudioCount != this->audioCaptureSourceList.size())
		return;

	this->readyToCaptureAudio = true;

	if (this->readyToCaptureVideo == true) {

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
}


bool VideoRecorder::initVideo() {

	this->videoCaptureSource = new VideoCaptureSource(this->videoCodecInfo.fps, this->videoParameter, this);
	if (this->videoCaptureSource->init() == false) {

		this->videoCaptureSource->close();

		delete this->videoCaptureSource;
		this->videoCaptureSource = nullptr;

		return false;
	}

	connect(this->videoCaptureSource, &VideoCaptureSource::captureReady, this, &VideoRecorder::videoCaptureReady);
	//connect(this->videoCaptureSource, &VideoCaptureSource::captureAccessLost, this, &VideoRecorder::videoCaptureAccessLost);

	this->videoEncodeThread = new VideoEncodeThread(&this->mainTime, this->videoCodecInfo.fps, this->videoCaptureSource, this->videoEncoder, this->outputContext, this);


	return true;
}

void VideoRecorder::closeVideo() {

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

bool VideoRecorder::initAudio() {

	this->readyCaptureAudioCount = 0;

	for (int i = 0; i < this->audioParameterList.size(); i++) {


		AudioCaptureSource *source = new AudioCaptureSource(&this->mainTime, this->audioCodecInfo, this->audioParameterList.at(i), this);

		if (source->init() == false) {

			qDebug() << " audio init failed";
			delete source;
		}
		else {

			this->audioCaptureSourceList.append(source);
			connect(source, &AudioCaptureSource::captureReady, this, &VideoRecorder::audioCaptureReady);

		}
	}

	this->audioEncodeThread = new AudioEncodeThread(&this->mainTime, &this->audioCaptureSourceList, this->audioEncoder, this->outputContext, this);

	return true;
}

void VideoRecorder::closeAudio() {

	if (this->audioCaptureSourceList.size() > 0) {

		for (int i = 0; i < this->audioCaptureSourceList.size(); i++) {

			this->audioCaptureSourceList.at(i)->quit();
			this->audioCaptureSourceList.at(i)->wait();


		}


		//AudioEncodeThread quit ,wait should be done last.
		this->audioEncodeThread->quit();
		this->audioEncodeThread->wait();

		delete this->audioEncodeThread;
		this->audioEncodeThread = nullptr;

		for (int i = 0; i < this->audioCaptureSourceList.size(); i++) {

			delete this->audioCaptureSourceList.at(i);
		}

		this->audioCaptureSourceList.clear();
	}
}


void VideoRecorder::initTimer() {

	this->timeThread = new QThread(this);
	this->timeCounter = new TimeCounter(&this->mainTime);
	this->timeCounter->moveToThread(this->timeThread);

	qRegisterMetaType<Time>("Time&");
	connect(this->timeCounter, SIGNAL(timePassed(Time&)), this, SIGNAL(timePassed(Time&)));
	connect(this->timeThread, &QThread::started, this->timeCounter, &TimeCounter::start);
	connect(this->timeThread, &QThread::finished, this->timeCounter, &TimeCounter::finish);
}

void VideoRecorder::closeTimer() {

	this->timeThread->quit();
	this->timeThread->wait();
	delete this->timeCounter;
	this->timeCounter = nullptr;
	delete this->timeThread;
	this->timeThread = nullptr;
}


