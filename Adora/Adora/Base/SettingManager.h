

#ifndef _SETTINGMANAGER_H
#define _SETTINGMANAGER_H

#include "Singleton.h"
#include <qpoint.h>
#include <qstring.h>

class GeneralSetting {

	friend class SettingManager;

private:
	QString savePath;

private:
	GeneralSetting();
	~GeneralSetting();

	void load();
	void save();

public:
	void setSavePath(const QString &path) { this->savePath = path; }

public:
	inline const QString& getSavePath() const { return this->savePath; }

};


////////////////////////////////////////////////////////

class VideoSetting {

	friend class SettingManager;

private:
	bool useStartAndStopHotkey;
	bool usePauseAndResumeHotkey;
	bool includeCursor;
	bool useHwEncoder;
	int fps;
	int videoBitrate;

private:
	VideoSetting();
	~VideoSetting();

	void load();
	void save();

public:
	void setUseStartAndStopHotkey(bool useStartAndStopHotkey) { this->useStartAndStopHotkey = useStartAndStopHotkey; }
	void setUsePauseAndResumeHotkey(bool usePauseAndResumeHotkey) { this->usePauseAndResumeHotkey = usePauseAndResumeHotkey; }
	void setIncludeCursor(bool includeCursor) { this->includeCursor = includeCursor; }
	void setUseHwEncoder(bool useHwEncoder) { this->useHwEncoder = useHwEncoder; }
	void setFps(int fps) { this->fps = fps; }
	void setVideoBitrate(int videoBitrate) { this->videoBitrate = videoBitrate; }

public:
	inline bool getUseStartAndStopHotkey() const { return this->useStartAndStopHotkey; }
	inline bool getUsePauseAndResumeHotkey() const { return this->usePauseAndResumeHotkey; }
	inline bool getIncludeCursor() const { return this->includeCursor; }
	inline bool getUseHwEncoder() const { return this->useHwEncoder; }
	inline int getFps() const { return this->fps; }
	inline int getVideoBitrate() const { return this->videoBitrate; }
};

////////////////////////////////////////////////////////

class AudioSetting {

	friend class SettingManager;

private:
	QString audioDevice;
	bool audioMuted;
	int audioVolume;

	QString audioDevice2;
	bool audioMuted2;
	int audioVolume2;

private:
	AudioSetting();
	~AudioSetting();

	void load();
	void save();

public:
	void setAudioDevice(const QString &audioDevice) { this->audioDevice = audioDevice; }
	void setAudioMuted(bool audioMuted) { this->audioMuted = audioMuted; }
	void setAudioVolume(int audioVolume) { this->audioVolume = audioVolume; }

	void setAudioDevice2(const QString &audioDevice2) { this->audioDevice2 = audioDevice2; }
	void setAudioMuted2(bool audioMuted2) { this->audioMuted2 = audioMuted2; }
	void setAudioVolume2(int audioVolume2) { this->audioVolume2 = audioVolume2; }

public:
	inline const QString& getAudioDevice() const { return this->audioDevice; }
	inline bool getAudioMuted() const { return this->audioMuted; }
	inline int getAudioVolume() const { return this->audioVolume; }

	inline const QString& getAudioDevice2() const { return this->audioDevice2; }
	inline bool getAudioMuted2() const { return this->audioMuted2; }
	inline int getAudioVolume2() const { return this->audioVolume2; }

};

////////////////////////////////////////////////////////


class ImageSetting {

	friend class SettingManager;

private:
	bool includeCursor;
	bool useImageCaptureHotkey;

private:
	ImageSetting();
	~ImageSetting();

	void load();
	void save();


public:
	void setIncludeCursor(bool includeCursor) { this->includeCursor = includeCursor; }
	void setUseImageCaptureHotkey(bool useImageCaptureHotkey) { this->useImageCaptureHotkey = useImageCaptureHotkey; }

public:
	inline bool getIncludeCursor() const { return this->includeCursor; }
	inline bool getUseImageCaptureHotkey() const { return this->useImageCaptureHotkey; }
};



/////////////////////////////////////////////////////////



class LanguageSetting {

	friend class SettingManager;

public:
	enum Language {

		English,
		Korean,
	};

private:
	Language language;

private:
	LanguageSetting();
	~LanguageSetting();

	void load();
	void save();

public:
	void setLanguage(Language language) { this->language = language; }

public:
	inline Language getLanguage() const { return this->language; }
};



//////////////////////////////////////////////////////////////////////

class SettingManager {

	DeclareSingleton(SettingManager)

private:
	QPoint adoraPosition;

private:
	GeneralSetting generalSetting;
	VideoSetting videoSetting;
	AudioSetting audioSetting;
	ImageSetting imageSetting;
	LanguageSetting languageSetting;
	

public:
	void load();
	void save();
	
public:
	void setAdoraPosition(const QPoint &point) { this->adoraPosition = point; }


public:
	inline const QPoint& getAdoraPosition() const { return this->adoraPosition; }

	inline GeneralSetting* getGeneralSetting() { return &(this->generalSetting); }
	inline VideoSetting* getVideoSetting() { return &(this->videoSetting); }
	inline AudioSetting* getAudioSetting() { return &(this->audioSetting); }
	inline ImageSetting* getImageSetting() { return &(this->imageSetting); }
	inline LanguageSetting* getLanguageSetting() { return &(this->languageSetting); }

	
};

//////////////////////////////////////////////////////////////


#endif //_SETTINGMANAGER_H
