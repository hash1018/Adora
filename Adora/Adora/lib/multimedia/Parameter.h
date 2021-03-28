

#ifndef _PARAMETER_H
#define _PARAMETER_H

#include <qstring.h>

#ifdef Q_OS_WIN
#include <mmdeviceapi.h>
#endif 

class VideoParameter {

public:
	int x;
	int y;
	int width;
	int height;
	bool drawCursor;


public:
	VideoParameter();
	VideoParameter(const VideoParameter &other);
	~VideoParameter();

	VideoParameter& operator=(const VideoParameter &other);

};

class AudioParameter {

public:
	__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001 type;
	QString deviceName;
	bool muted;

public:
	AudioParameter();
	AudioParameter(const AudioParameter &other);
	~AudioParameter();

	AudioParameter& operator=(const AudioParameter &other);

};

#endif //_PARAMETER_H
