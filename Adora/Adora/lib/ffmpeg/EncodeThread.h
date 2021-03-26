
#ifndef _ENCODETHREAD_H
#define _ENCODETHREAD_H

#include <qthread.h>
class VideoCaptureSource;
class VideoEncoder;
class OutputContext;
class Time;
class AudioCaptureSource;
class AudioEncoder;
class Capture_AudioFrame;

class VideoEncodeThread : public QThread {

private:
	VideoCaptureSource *source;
	VideoEncoder *videoEncoder;
	OutputContext *outputContext;

	bool requestToFinish;

private:
	Time *mainTime;

private:
	int fps;

private:
	uint64_t totalPushedtoQueueCount;
	uint64_t totalCountToBePushedQueue;


public:
	VideoEncodeThread(Time *mainTime, int fps, VideoCaptureSource *source, VideoEncoder *videoEncoder, OutputContext *outputContext, QObject *parent = nullptr);
	~VideoEncodeThread();

	virtual void quit() { this->requestToFinish = true; }

private:
	virtual void run();

private:
	uint64_t convertTotalPushedToQueueCount(Time &mainTime);
	uint64_t convertMilliseconds(Time &mainTime);

};


////////////////////////////////////////////////////////////////

class AudioEncodeThread : public QThread {

private:
	QList<AudioCaptureSource*> *list;
	AudioEncoder *encoder;
	OutputContext *outputContext;

	bool requestToFinish;

	QList<Capture_AudioFrame*> audioFrameList;

private:
	Time *mainTime;

private:
	uint64_t totalPushedtoQueueCount;
	uint64_t totalCountToBePushedQueue;

public:
	AudioEncodeThread(Time *mainTime, QList<AudioCaptureSource*> *list, AudioEncoder *encoder, OutputContext *outputContext, QObject *parent = nullptr);
	~AudioEncodeThread();

public:
	virtual void quit() { this->requestToFinish = true; }

private:
	virtual void run();



	void mixAudioData(uint8_t *finalBuffer);

};




#endif //_ENCODETHREAD_H
