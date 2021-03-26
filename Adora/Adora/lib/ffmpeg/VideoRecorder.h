

#ifndef _VIDEORECORDER_H
#define _VIDEORECORDER_H

#include <qobject.h>
#include "Base\Time.h"
#include <qstring.h>
#include "lib/ffmpeg/CodecInfo.h"
#include "lib/multimedia/Parameter.h"

class QTimer;
class TimeCounter;
class VideoEncoder;
class VideoCaptureSource;
class VideoEncodeThread;
class OutputContext;
class VideoScaler;


class AudioCaptureSource;
class AudioEncodeThread;
class Capture_AudioFrame;
class AudioEncoder;

class VideoRecorder : public QObject {

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
	QString filePath;

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
	AudioEncoder *audioEncoder;
	QList<AudioCaptureSource*> audioCaptureSourceList;
	QList<AudioParameter> audioParameterList;
	AudioCodecInfo audioCodecInfo;
	AudioEncodeThread *audioEncodeThread;
	bool readyToCaptureAudio;
	int readyCaptureAudioCount;


private:
	Time mainTime;
	TimeCounter *timeCounter;
	QThread *timeThread;

public:
	VideoRecorder();
	~VideoRecorder();

	void setFilePath(const QString &filePath);

public:
	void setVideoCodecInfo(const VideoCodecInfo &videoCodecInfo);
	void setVideoParameter(const VideoParameter &videoParameter);
	void changeVideoParameter(const VideoParameter &videoParameter);

public:
	void setAudioCodecInfo(const AudioCodecInfo &audioCodecInfo);
	void setAudioParameter(const QList<AudioParameter> &audioParameterList);
	
	
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
	void audioCaptureReady();




private:
	bool initVideo();
	void closeVideo();

	bool initAudio();
	void closeAudio();

	void initTimer();
	void closeTimer();
};



#endif //_VIDEORECORDER_H


