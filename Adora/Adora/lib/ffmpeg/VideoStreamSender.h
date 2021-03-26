

#ifndef _VIDEOSTREAMSENDER_H
#define _VIDEOSTREAMSENDER_H

#include <qobject.h>
#include "Time.h"
#include <qstring.h>
#include "ffmpeg-lib\CodecInfo.h"
#include "multimedia-lib\Parameter.h"

class QTimer;
class TimeCounter;
class VideoEncoder;
class VideoCaptureSource;
class VideoEncodeThread;
class OutputContext;
class VideoScaler;

class VideoStreamSender : public QObject {

	Q_OBJECT

public:
	enum Status {
		NotRecording,
		Pausing,
		Recording,
	};

private:
	Status status;

private:
	QString ip;
	int port;

private:
	OutputContext *outputContext;

private:
	VideoEncoder *videoEncoder;
	VideoParameter videoParameter;
	VideoCodecInfo videoCodecInfo;
	VideoCaptureSource *videoCaptureSource;
	VideoEncodeThread *videoEncodeThread;
	bool readyToCaptureVideo;

private:
	Time mainTime;
	TimeCounter *timeCounter;
	QThread *timeThread;

public:
	VideoStreamSender();
	~VideoStreamSender();

	void setIp(const QString &ip);
	void setPort(int port);

public:
	void setVideoCodecInfo(const VideoCodecInfo &videoCodecInfo);
	void setVideoParameter(const VideoParameter &videoParameter);

public:
	bool start();
	bool stop();
	bool resume();
	bool pause();

public:
	inline Status getStatus() const { return this->status; }


signals:
	void timePassed(Time &time);
	void started();
	void paused();
	void stopped();
	void resumed();

	private slots:
	void videoCaptureReady();
	
private:
	bool initVideo();
	void closeVideo();

	void initTimer();
	void closeTimer();
};



#endif //_VIDEOSTREAMSENDER_H
