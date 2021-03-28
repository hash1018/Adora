

#ifndef _AUDIOCAPTURESOURCE_H
#define _AUDIOCAPTURESOURCE_H

#include <qobject.h>
#include "Parameter.h"
#include <qthread.h>
#include "lib/ffmpeg/AudioResampler.h"
#include "lib/ffmpeg/CodecInfo.h"
#include <qqueue.h>
#include <qmutex.h>

#ifdef Q_OS_WIN

#include <Audioclient.h>
#include <mmdeviceapi.h>
#include <mmsystem.h>
#include <audiopolicy.h>
#endif


class AudioFrameQueue;
class Capture_AudioFrame;
class Time;

#define OneFrameBufferSize 4096

class AudioCaptureSource : public QThread {

	Q_OBJECT

private:
#ifdef Q_OS_WIN
	REFERENCE_TIME hnsRequestedDuration;
	REFERENCE_TIME hnsActualDuration;

	UINT32 bufferFrameCount;
	UINT32 numFramesAvailable;

	IMMDeviceEnumerator *deviceEnumerator;
	IMMDevice *device;
	IAudioClient *audioClient;
	IAudioCaptureClient *captureClient;
	WAVEFORMATEX *waveFormat;
	WAVEFORMATEXTENSIBLE *waveFormatExtensible;
	UINT32 packetLength = 0;
	BYTE *data;
	DWORD flags;

#endif

private:
	AudioParameter parameter;
	AudioCodecInfo codecInfo;

private:
	QMutex muteMutex;

private:
	Time *mainTime;

private:
	bool requestToFinish;
	bool noNeedToPushQueueMore;

private:
	int frameSize;

private:
	AudioResampler resampler;

	uint8_t bits[OneFrameBufferSize];
	int bitsIndex;

private:
	double cycleTimeByOneFrame;

	uint64_t totalPushedtoQueueCount;
	uint64_t totalCountToBePushedQueue;

private:
	AudioFrameQueue *audioFrameQueue;

public:
	AudioCaptureSource(Time *mainTime, const AudioCodecInfo &codecInfo, const AudioParameter &parameter, QObject *parent = nullptr);
	~AudioCaptureSource();

	virtual void quit();

	bool init();


public:
	void clearFrameQueue();
	Capture_AudioFrame* popAudioFrame();
	

	inline const QString& getDeviceName() const { return this->parameter.deviceName; }
	void setMuted(bool muted) { this->muteMutex.lock(); this->parameter.muted = muted; this->muteMutex.unlock(); }

signals:
	void captureReady();

protected:
	virtual void run();


private:
	static void getDevice(IMMDeviceEnumerator *deviceEnumerator, __MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001 eType, const QString &deviceName, IMMDevice **device);
	static QString getDeviceName(IMMDeviceCollection *deviceCollection, UINT deviceIndex);

	void clear();

#ifdef Q_OS_WIN
	bool initWinOS();
#endif



private:
	void append(uint8_t *totalBuffer, int &totalBufferIndex, uint8_t *buffer, int length);
	void resampleAndPush(uint8_t *buffer, int length);


	void appendLast(uint8_t *totalBuffer, int &totalBufferIndex, uint8_t *buffer, int length);
	void resampleAndPushLast(uint8_t *buffer, int length);


	int getFrameSize();
	uint64_t convertTotalPushedToQueueCount(Time &mainTime);


	void setMuteData(uint8_t *buffer, int size);

};



class Capture_AudioFrame {

private:
	uint8_t buffer[OneFrameBufferSize];
	int frameIndex;

public:
	Capture_AudioFrame(uint8_t *buffer, int bufferSize, int frameIndex);
	~Capture_AudioFrame();

	const uint8_t* getBuffer() { return this->buffer; }
	int getFrameIndex() const { return this->frameIndex; }
};


class AudioFrameQueue {

private:
	QMutex mutex;
	QQueue<Capture_AudioFrame*> queue;

public:
	AudioFrameQueue();
	~AudioFrameQueue();

	void push(Capture_AudioFrame *frame);
	Capture_AudioFrame* pop();
	void clear();
	


};



#endif //_AUDIOCAPTURESOURCE_H
