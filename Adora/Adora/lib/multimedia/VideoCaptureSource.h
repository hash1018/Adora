

#ifndef _VIDEOCAPTURESOURCE_H
#define _VIDEOCAPTURESOURCE_H

#include <qthread.h>
#include "Parameter.h"
#include <qmutex.h>


#ifdef Q_OS_WIN
#include "GDIManager.h"
#endif 

class VideoCaptureSource : public QThread {

	Q_OBJECT

private:
	bool initialized;

private:
	VideoParameter parameter;
	unsigned char *bits;


#ifdef Q_OS_WIN
private:
	GDIManager gdiManager;
#endif 

private:
	int fps;

private:
	bool requestToFinish;

private:
	QMutex mutex;

private:
	unsigned char *copyBuffer;
	QMutex copyMutex;

public:
	VideoCaptureSource(int fps, const VideoParameter &parameter, QObject *parent = nullptr);
	~VideoCaptureSource();

	// ///////  using mutex functions.  ////////////
public:
	void setVideoParameter(const VideoParameter &parameter);
	void copyToBuffer(uint8_t* (*buffer));
	void getSize(int &width, int &height);

	bool init();
	bool close();
	////////////////////////////////////////////////

	virtual void quit() { this->requestToFinish = true; }

signals:
	void captureReady();
	void captureAccessLost();

private:
	void clearCaptureInfo();
	bool initCaptureInfo();

protected:
	virtual void run();

private:
	void capture();

};



#endif //_VIDEOCAPTURESOURCE_H