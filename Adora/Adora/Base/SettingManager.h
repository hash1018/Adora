

#ifndef _SETTINGMANAGER_H
#define _SETTINGMANAGER_H

#include "Singleton.h"
#include <qpoint.h>
#include <qstring.h>
#include <qkeysequence.h>

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
	QKeySequence startStopHotkey;

	bool usePauseAndResumeHotkey;
	QKeySequence pauseResumeHotkey;

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
	void setStartStopHotkey(const QKeySequence &startStopHotkey) { this->startStopHotkey = startStopHotkey; }

	void setUsePauseAndResumeHotkey(bool usePauseAndResumeHotkey) { this->usePauseAndResumeHotkey = usePauseAndResumeHotkey; }
	void setPauseResumeHotkey(const QKeySequence &pauseResumeHotkey) { this->pauseResumeHotkey = pauseResumeHotkey; }

	void setIncludeCursor(bool includeCursor) { this->includeCursor = includeCursor; }
	void setUseHwEncoder(bool useHwEncoder) { this->useHwEncoder = useHwEncoder; }
	void setFps(int fps) { this->fps = fps; }
	void setVideoBitrate(int videoBitrate) { this->videoBitrate = videoBitrate; }

public:
	inline bool getUseStartAndStopHotkey() const { return this->useStartAndStopHotkey; }
	inline const QKeySequence& getStartStopHotkey() const { return this->startStopHotkey; }

	inline bool getUsePauseAndResumeHotkey() const { return this->usePauseAndResumeHotkey; }
	inline const QKeySequence& getPauseResumeHotkey() const { return this->pauseResumeHotkey; }

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
	QKeySequence imageCaptureHotkey;
	QString imageFormat;

private:
	ImageSetting();
	~ImageSetting();

	void load();
	void save();


public:
	void setIncludeCursor(bool includeCursor) { this->includeCursor = includeCursor; }
	void setUseImageCaptureHotkey(bool useImageCaptureHotkey) { this->useImageCaptureHotkey = useImageCaptureHotkey; }
	void setImageCaptureHotkey(const QKeySequence &imageCaptureHotkey) { this->imageCaptureHotkey = imageCaptureHotkey; }
	void setImageFormat(const QString &imageFormat) { this->imageFormat = imageFormat; }

public:
	inline bool getIncludeCursor() const { return this->includeCursor; }
	inline bool getUseImageCaptureHotkey() const { return this->useImageCaptureHotkey; }
	inline const QKeySequence& getImageCaptureHotkey() const { return this->imageCaptureHotkey; }
	inline const QString& getImageFormat() const { return this->imageFormat; }
};



/////////////////////////////////////////////////////////

class TimeLimitSetting {

	friend class SettingManager;

private:
	bool useTimeLimit;

	int hour;
	int minute;
	int second;

private:
	TimeLimitSetting();
	~TimeLimitSetting();

	void load();
	void save();

public:
	void setUseTimeLimit(bool useTimeLimit) { this->useTimeLimit = useTimeLimit; }
	void setHour(int hour) { this->hour = hour; }
	void setMinute(int minute) { this->minute = minute; }
	void setSecond(int second) { this->second = second; }

public:
	inline bool getUseTimeLimit() const { return this->useTimeLimit; }
	inline int getHour() const { return this->hour; }
	inline int getMinute() const { return this->minute; }
	inline int getSecond() const { return this->second; }

};


//////////////////////////////////////////////////////////

class WatermarkSetting {
	
	friend class SettingManager;

public:
	enum Layout {
		TopLeft,
		TopCenter,
		TopRight,
		CenterLeft,
		CenterCenter,
		CenterRight,
		BottomLeft,
		BottomCenter,
		BottomRight,
	};
private:
	bool useWatermark;
	QString imagePath;
	int opacity;
	Layout layout;
	
private:
	WatermarkSetting();
	~WatermarkSetting();

	void load();
	void save();

public:
	void setUseWatermark(bool useWatermark) { this->useWatermark = useWatermark; }
	void setImagePath(const QString &imagePath) { this->imagePath = imagePath; }
	void setOpacity(int opacity) { this->opacity = opacity; }
	void setLayout(Layout layout) { this->layout = layout; }

public:
	inline bool getUseWatermark() const { return this->useWatermark; }
	inline const QString& getImagePath() const { return this->imagePath; }
	inline int getOpacity() const { return this->opacity; }
	inline Layout getLayout() const { return this->layout; }
};


//////////////////////////////////////////////////////////

class WritingSetting {

	friend class SettingManager;

private:
	bool useCursorHotkey;
	QKeySequence cursorHotkey;

	bool usePencilHotkey;
	QKeySequence pencilHotkey;

	bool useHighlightHotkey;
	QKeySequence highlightHotkey;

	bool useLineHotkey;
	QKeySequence lineHotkey;

	bool useArrowLineHotkey;
	QKeySequence arrowLineHotkey;

	bool useNumberingHotkey;
	QKeySequence numberingHotkey;

	bool useEraserHotkey;
	QKeySequence eraserHotkey;

	bool useDeleteAllHotkey;
	QKeySequence deleteAllHotkey;

private:
	WritingSetting();
	~WritingSetting();

	void load();
	void save();

public:

	void setUseCursorHotkey(bool useCursorHotkey) { this->useCursorHotkey = useCursorHotkey; }
	void setCursorHotkey(const QKeySequence &cursorHotkey) { this->cursorHotkey = cursorHotkey; }

	void setUsePencilHotkey(bool usePencilHotkey) { this->usePencilHotkey = usePencilHotkey; }
	void setPencilHotkey(const QKeySequence &pencilHotkey) { this->pencilHotkey = pencilHotkey; }

	void setUseHighlightHotkey(bool useHighlightHotkey) { this->useHighlightHotkey = useHighlightHotkey; }
	void setHighlightHotkey(const QKeySequence &highlightHotkey) { this->highlightHotkey = highlightHotkey; }

	void setUseLineHotkey(bool useLineHotkey) { this->useLineHotkey = useLineHotkey; }
	void setLineHotkey(const QKeySequence &lineHotkey) { this->lineHotkey = lineHotkey; }

	void setUseArrowLineHotkey(bool useArrowLineHotkey) { this->useArrowLineHotkey = useArrowLineHotkey; }
	void setArrowLineHotkey(const QKeySequence &arrowLineHotkey) { this->arrowLineHotkey = arrowLineHotkey; }

	void setUseNumberingHotkey(bool useNumberingHotkey) { this->useNumberingHotkey = useNumberingHotkey; }
	void setNumberingHotkey(const QKeySequence &numberingHotkey) { this->numberingHotkey = numberingHotkey; }

	void setUseEraserHotkey(bool useEraserHotkey) { this->useEraserHotkey = useEraserHotkey; }
	void setEraserHotkey(const QKeySequence &eraserHotkey) { this->eraserHotkey = eraserHotkey; }

	void setUseDeleteAllHotkey(bool useDeleteAllHotkey) { this->useDeleteAllHotkey = useDeleteAllHotkey; }
	void setDeleteAllHotkey(const QKeySequence &deleteAllHotkey) { this->deleteAllHotkey = deleteAllHotkey; }

public:
	inline bool getUseCursorHotkey() const { return this->useCursorHotkey; }
	inline const QKeySequence& getCursorHotkey() const { return this->cursorHotkey; }

	inline bool getUsePencilHotkey() const { return this->usePencilHotkey; }
	inline const QKeySequence& getPencilHotkey() const { return this->pencilHotkey; }

	inline bool getUseHighlightHotkey() const { return this->useHighlightHotkey; }
	inline const QKeySequence& getHighlightHotkey() const { return this->highlightHotkey; }

	inline bool getUseLineHotkey() const { return this->useLineHotkey; }
	inline const QKeySequence& getLineHotkey() const { return this->lineHotkey; }

	inline bool getUseArrowLineHotkey() const { return this->useArrowLineHotkey; }
	inline const QKeySequence& getArrowLineHotkey() const { return this->arrowLineHotkey; }

	inline bool getUseNumberingHotkey() const { return this->useNumberingHotkey; }
	inline const QKeySequence& getNumberingHotkey() const { return this->numberingHotkey; }

	inline bool getUseEraserHotkey() const { return this->useEraserHotkey; }
	inline const QKeySequence& getEraserHotkey() const { return this->eraserHotkey; }

	inline bool getUseDeleteAllHotkey() const { return this->useDeleteAllHotkey; }
	inline const QKeySequence& getDeleteAllHotkey() const { return this->deleteAllHotkey; }
};

//////////////////////////////////////////////////////////

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
	TimeLimitSetting timeLimitSetting;
	WatermarkSetting watermarkSetting;
	WritingSetting writingSetting;
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
	inline TimeLimitSetting* getTimeLimitSetting() { return &(this->timeLimitSetting); }
	inline WatermarkSetting* getWatermarkSetting() { return &(this->watermarkSetting); }
	inline WritingSetting* getWritingSetting() { return &(this->writingSetting); }
	inline LanguageSetting* getLanguageSetting() { return &(this->languageSetting); }

	
};

//////////////////////////////////////////////////////////////


#endif //_SETTINGMANAGER_H
