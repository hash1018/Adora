

#ifndef _AUDIODEVICELIST_H
#define _AUDIODEVICELIST_H

#include <qstringlist.h>

#ifdef Q_OS_WIN

#include <Audioclient.h>
#include <mmdeviceapi.h>
#include <mmsystem.h>
#include <audiopolicy.h>
#endif 

class AudioDeviceList {

public:
	AudioDeviceList();
	~AudioDeviceList();

public:
	static QStringList getDeviceList(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001 type);
	

private:
	static QString getDeviceName(IMMDeviceCollection *deviceCollection, UINT deviceIndex);
};



#endif //_AUDIODEVICELIST_H
