

#ifndef _VOLUMELEVELGETTER_H
#define _VOLUMELEVELGETTER_H

#include <qthread.h>

#ifdef Q_OS_WIN

#include <Audioclient.h>
#include <mmdeviceapi.h>
#include <mmsystem.h>
#include <audiopolicy.h>
#include <Functiondiscoverykeys_devpkey.h>
#endif

class VolumeLevelGetter : public QThread {

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
	bool requestToFinish;

public:
	VolumeLevelGetter(QObject *parent = nullptr);
	~VolumeLevelGetter();

#ifdef Q_OS_WIN
	bool init(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001 type, const QString &deviceName);
	
#endif 

	virtual void quit();

signals:
	void amplitudeChanged(float level);

protected:
	virtual void run();


#ifdef Q_OS_WIN
private:
	void getDevice(IMMDeviceEnumerator *deviceEnumerator, 
		__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001 eType, 
		const QString &deviceName, IMMDevice **device);

	QString getDeviceName(IMMDeviceCollection *deviceCollection, UINT deviceIndex);

	void clear();
#endif 


	float getAmplitude(uint8_t *buffer, int length);
};



#endif //_VOLUMELEVELGETTER_H
