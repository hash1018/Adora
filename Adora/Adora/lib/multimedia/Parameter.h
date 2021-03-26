

#ifndef _PARAMETER_H
#define _PARAMETER_H

#include <qstring.h>

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
	QString deviceName;
	bool muted;

public:
	AudioParameter();
	AudioParameter(const AudioParameter &other);
	~AudioParameter();

	AudioParameter& operator=(const AudioParameter &other);

};

#endif //_PARAMETER_H
