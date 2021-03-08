

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
	inline LanguageSetting* getLanguageSetting() { return &(this->languageSetting); }

	
};

//////////////////////////////////////////////////////////////


#endif //_SETTINGMANAGER_H
