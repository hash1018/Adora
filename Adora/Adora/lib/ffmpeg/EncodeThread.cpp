

#include "EncodeThread.h"
#include <qdebug.h>

#include "Frame.h"
#include "VideoScaler.h"
#include "Packet.h"
#include "lib/multimedia/VideoCaptureSource.h"
#include "lib/multimedia/AudioCaptureSource.h"
#include "Encoder.h"
#include "OutputContext.h"
#include "AudioFormatConverter.h"
#include "Base/Time.h"

VideoEncodeThread::VideoEncodeThread(Time *mainTime, int fps, VideoCaptureSource *source, VideoEncoder *videoEncoder, OutputContext *outputContext, QObject *parent)
	:QThread(parent), mainTime(mainTime), fps(fps), source(source), videoEncoder(videoEncoder), outputContext(outputContext), requestToFinish(false) {

	this->totalCountToBePushedQueue = 0;
	this->totalPushedtoQueueCount = 0;
}


VideoEncodeThread::~VideoEncodeThread() {

}

void VideoEncodeThread::run() {

	qDebug() << "VideoEncodeThread ::run";
	this->setPriority(QThread::Priority::HighPriority);

	this->requestToFinish = false;

	uint8_t(*buffer) = nullptr;
	int width, height;

	VideoFrame videoFrame(this->videoEncoder->getWidth(), this->videoEncoder->getHeight(), this->videoEncoder->getFormat());
	VideoScaler *videoScaler;
	VideoPacket videoPacket;

	qDebug() << this->videoEncoder->getWidth() << "  " << this->videoEncoder->getHeight() << "   " << this->videoEncoder->getFormat();

	for (;;) {

		this->totalCountToBePushedQueue = this->convertTotalPushedToQueueCount(*this->mainTime);

		//qDebug() << "totalPushedtoQueueCount  " << totalPushedtoQueueCount;
		//qDebug() << " totalCountToBePushedQueue  " << totalCountToBePushedQueue;
		if (this->totalPushedtoQueueCount >= this->totalCountToBePushedQueue) {

			if (this->requestToFinish == true) {

				if (buffer != nullptr) {

					delete[] buffer;
					delete videoScaler;
				}

				return;
			}

		}
		else {

			if (buffer == nullptr) {

				this->source->getSize(width, height);

				buffer = new unsigned char[width*height * 4];

				videoScaler = new VideoScaler(width, height, AV_PIX_FMT_RGB32, this->videoEncoder->getWidth(), this->videoEncoder->getHeight(), this->videoEncoder->getFormat());
			}

			this->source->copyToBuffer(&buffer);


			while (this->totalPushedtoQueueCount < this->totalCountToBePushedQueue) {

				videoScaler->scale(buffer, 4 * width, &videoFrame);

				videoFrame.setPts(this->totalPushedtoQueueCount);

				this->videoEncoder->encode(&videoFrame, &videoPacket);
				this->outputContext->writePacket(&videoPacket);

				this->totalPushedtoQueueCount++;
			}
		}

		this->msleep(5);
	}
}


uint64_t VideoEncodeThread::convertTotalPushedToQueueCount(Time &mainTime) {

	Time time = mainTime;
	uint64_t milliseconds = time.getMilliseconds();
	uint64_t seconds = time.getSeconds();
	uint64_t minutes = time.getMinutes();
	uint64_t hours = time.getHours();

	minutes += hours * 60;
	seconds += minutes * 60;
	milliseconds += (seconds * 1000);

	double cycleTimeByOneFrame = 1000.0 / this->fps;

	return int(milliseconds / cycleTimeByOneFrame);
}


uint64_t VideoEncodeThread::convertMilliseconds(Time &mainTime) {

	Time time = mainTime;
	uint64_t milliseconds = time.getMilliseconds();
	uint64_t seconds = time.getSeconds();
	uint64_t minutes = time.getMinutes();
	uint64_t hours = time.getHours();

	minutes += hours * 60;
	seconds += minutes * 60;
	milliseconds += (seconds * 1000);

	return milliseconds;
}



////////////////////////////////////////////////////////////////////////////////////////


AudioEncodeThread::AudioEncodeThread(Time *mainTime, QList<AudioCaptureSource*> *list, AudioEncoder *encoder, OutputContext *outputContext, QObject *parent)
	:QThread(parent), mainTime(mainTime), list(list), encoder(encoder), outputContext(outputContext) {

}


AudioEncodeThread::~AudioEncodeThread() {


}

void AudioEncodeThread::run() {

	qDebug() << "AudioEncodeThread::run " << this->currentThreadId();

	this->requestToFinish = false;

	uint8_t finalBuffer[OneFrameBufferSize];

	AudioFrame audioFrame(this->encoder->getFormat(), this->encoder->getFrameSize(), this->encoder->getChannelLayout());
	AudioPacket audioPacket(this->encoder->getSampleRate(), this->encoder->getFrameSize());
	AudioFormatConverter converter(this->encoder->getChannelLayout(), this->encoder->getSampleRate(),
		AV_SAMPLE_FMT_S16, this->encoder->getFormat());

	for (;;) {

		Capture_AudioFrame *frame;

		for (int i = 0; i < this->list->size(); i++) {

			frame = this->list->at(i)->popAudioFrame();

			while (frame == nullptr) {

				if (this->requestToFinish == true)
					break;

				QThread::msleep(1);
				frame = this->list->at(i)->popAudioFrame();
			}

			this->audioFrameList.append(frame);

		}

		for (int i = 0; i < this->audioFrameList.size(); i++) {

			if (this->audioFrameList.at(i) == nullptr) {

				if (this->requestToFinish == true) {
					this->audioFrameList.clear();
					return;
				}
			}
		}

		this->mixAudioData(finalBuffer);

		converter.resample(finalBuffer, &audioFrame);


		this->encoder->encode(&audioFrame, &audioPacket);
		this->outputContext->writePacket(&audioPacket);


		while (this->audioFrameList.isEmpty() == false) {

			delete this->audioFrameList.takeFirst();
		}



		QThread::msleep(10);
	}


}

void AudioEncodeThread::mixAudioData(uint8_t *finalBuffer) {

	if (this->audioFrameList.size() == 1) {

		memcpy(finalBuffer, this->audioFrameList.at(0)->getBuffer(), OneFrameBufferSize);

	}
	else if (this->audioFrameList.size() == 2) {

		const uint16_t *buffer1 = (const uint16_t*)this->audioFrameList.at(0)->getBuffer();
		const uint16_t *buffer2 = (const uint16_t*)this->audioFrameList.at(1)->getBuffer();


		uint16_t *temp = (uint16_t*)finalBuffer;

		for (int i = 0; i < OneFrameBufferSize / 2; i++) {

			temp[i] = (buffer1[i] + buffer2[i]);
		}

	}
}



