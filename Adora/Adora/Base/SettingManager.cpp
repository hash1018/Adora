
#include "SettingManager.h"
#include <qsettings.h>
#include "LanguageManager.h"
#include <qdir.h>

GeneralSetting::GeneralSetting() {

}

GeneralSetting::~GeneralSetting() {

}

void GeneralSetting::load() {

	QSettings settings("Adora", "Adora");

	settings.beginGroup("General");

	this->savePath = settings.value("SavePath").toString();

	settings.endGroup();

	QDir dir(this->savePath);
	dir.mkdir(this->savePath);

	if (dir.exists() == false)
		this->savePath = "";

	if (this->savePath == "") {
	
#ifdef Q_OS_WIN
		QSettings settings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer", QSettings::NativeFormat);

		settings.beginGroup("Shell Folders");
		this->savePath = settings.value("Personal").toString() + QString::fromLocal8Bit("/Adora");
		settings.endGroup();

		this->savePath = this->savePath.replace("\\", "/");
	
#endif 
	}

	dir.mkdir(this->savePath);
}

void GeneralSetting::save() {

	QSettings settings("Adora", "Adora");

	settings.beginGroup("General");
	settings.setValue("SavePath", this->savePath);
	settings.endGroup();
}


////////////////////////////////////////////////////////////////////

VideoSetting::VideoSetting()
	:useStartAndStopHotkey(false), usePauseAndResumeHotkey(false), includeCursor(false), 
	useHwEncoder(false), fps(30), videoBitrate(1000000) {

}

VideoSetting::~VideoSetting() {


}

void VideoSetting::load() {

	QSettings settings("Adora", "Adora");

	settings.beginGroup("Video");

	if (settings.contains("useStartAndStopHotkey") == true)
		this->useStartAndStopHotkey = settings.value("useStartAndStopHotkey").toBool();

	if (settings.contains("startStopHotkey") == true)
		this->startStopHotkey = settings.value("startStopHotkey").toString();

	if (settings.contains("usePauseAndResumeHotkey") == true)
		this->usePauseAndResumeHotkey = settings.value("usePauseAndResumeHotkey").toBool();

	if (settings.contains("pauseResumeHotkey") == true)
		this->pauseResumeHotkey = settings.value("pauseResumeHotkey").toString();

	if (settings.contains("includeCursor") == true)
		this->includeCursor = settings.value("includeCursor").toBool();

	if (settings.contains("useHwEncoder") == true)
		this->useHwEncoder = settings.value("useHwEncoder").toBool();

	if (settings.contains("fps") == true)
		this->fps = settings.value("fps").toInt();

	if (settings.contains("videoBitrate") == true)
		this->videoBitrate = settings.value("videoBitrate").toInt();
	

	settings.endGroup();
}


void VideoSetting::save() {

	QSettings settings("Adora", "Adora");

	settings.beginGroup("Video");

	settings.setValue("useStartAndStopHotkey", this->useStartAndStopHotkey);
	settings.setValue("startStopHotkey", this->startStopHotkey.toString());

	settings.setValue("usePauseAndResumeHotkey", this->usePauseAndResumeHotkey);
	settings.setValue("pauseResumeHotkey", this->pauseResumeHotkey.toString());

	settings.setValue("includeCursor", this->includeCursor);
	settings.setValue("useHwEncoder", this->useHwEncoder);
	settings.setValue("fps", this->fps);
	settings.setValue("videoBitrate", this->videoBitrate);

	settings.endGroup();
}

////////////////////////////////////////////////////////////////////


AudioSetting::AudioSetting()
	:audioDevice(""), audioMuted(false), audioVolume(100), audioDevice2(""), audioMuted2(false), audioVolume2(100) {

}

AudioSetting::~AudioSetting() {

}

void AudioSetting::load() {

	QSettings settings("Adora", "Adora");

	settings.beginGroup("Audio");

	if (settings.contains("audioDevice") == true)
		this->audioDevice = settings.value("audioDevice").toString();

	if (settings.contains("audioMuted") == true)
		this->audioMuted = settings.value("audioMuted").toBool();

	if (settings.contains("audioVolume") == true)
		this->audioVolume = settings.value("audioVolume").toInt();

	if (settings.contains("audioDevice2") == true)
		this->audioDevice2 = settings.value("audioDevice2").toString();

	if (settings.contains("audioMuted2") == true)
		this->audioMuted2 = settings.value("audioMuted2").toBool();

	if (settings.contains("audioVolume2") == true)
		this->audioVolume2 = settings.value("audioVolume2").toInt();

	settings.endGroup();
}

void AudioSetting::save() {

	QSettings settings("Adora", "Adora");

	settings.beginGroup("Audio");

	settings.setValue("audioDevice", this->audioDevice);
	settings.setValue("audioMuted", this->audioMuted);
	settings.setValue("audioVolume", this->audioVolume);
	
	settings.setValue("audioDevice2", this->audioDevice2);
	settings.setValue("audioMuted2", this->audioMuted2);
	settings.setValue("audioVolume2", this->audioVolume2);

	settings.endGroup();
}





/////////////////////////////////////////////////////////////////////

ImageSetting::ImageSetting()
	:includeCursor(false), useImageCaptureHotkey(false), imageFormat("png") {

}

ImageSetting::~ImageSetting() {


}

void ImageSetting::load() {

	QSettings settings("Adora", "Adora");

	settings.beginGroup("Image");

	if (settings.contains("includeCursor") == true)
		this->includeCursor = settings.value("includeCursor").toBool();

	if (settings.contains("useImageCaptureHotkey") == true)
		this->useImageCaptureHotkey = settings.value("useImageCaptureHotkey").toBool();

	if (settings.contains("imageCaptureHotkey") == true)
		this->imageCaptureHotkey = settings.value("imageCaptureHotkey").toString();

	if (settings.contains("imageFormat") == true)
		this->imageFormat = settings.value("imageFormat").toString();

	settings.endGroup();
}

void ImageSetting::save() {

	QSettings settings("Adora", "Adora");

	settings.beginGroup("Image");

	settings.setValue("includeCursor", this->includeCursor);
	settings.setValue("useImageCaptureHotkey", this->useImageCaptureHotkey);
	settings.setValue("imageCaptureHotkey", this->imageCaptureHotkey.toString());
	settings.setValue("imageFormat", this->imageFormat);

	settings.endGroup();
}



/////////////////////////////////////////////////////////////////////

TimeLimitSetting::TimeLimitSetting()
	:useTimeLimit(false), hour(0), minute(0), second(0) {

}

TimeLimitSetting::~TimeLimitSetting() {


}

void TimeLimitSetting::load() {

	QSettings settings("Adora", "Adora");

	settings.beginGroup("Image");

	if (settings.contains("useTimeLimit") == true)
		this->useTimeLimit = settings.value("useTimeLimit").toBool();

	if (settings.contains("hour") == true)
		this->hour = settings.value("hour").toInt();

	if (settings.contains("minute") == true)
		this->minute = settings.value("minute").toInt();

	if (settings.contains("second") == true)
		this->second = settings.value("second").toInt();

	settings.endGroup();
}

void TimeLimitSetting::save() {

	QSettings settings("Adora", "Adora");

	settings.beginGroup("Image");


	settings.setValue("useTimeLimit", this->useTimeLimit);
	settings.setValue("hour", this->hour);
	settings.setValue("minute", this->minute);
	settings.setValue("second", this->second);

	settings.endGroup();
}


/////////////////////////////////////////////////////////////////////

WatermarkSetting::WatermarkSetting()
	:useWatermark(false), opacity(100), layout(Layout::TopCenter) {

}

WatermarkSetting::~WatermarkSetting() {

}

void WatermarkSetting::load() {

	QSettings settings("Adora", "Adora");

	settings.beginGroup("Watermark");

	if (settings.contains("useWatermark") == true)
		this->useWatermark = settings.value("useWatermark").toBool();

	if (settings.contains("imagePath") == true)
		this->imagePath = settings.value("imagePath").toString();

	if (settings.contains("opacity") == true)
		this->opacity = settings.value("opacity").toInt();

	if (settings.contains("layout") == true)
		this->layout = (Layout)settings.value("layout").toInt();

	settings.endGroup();
}

void WatermarkSetting::save() {

	QSettings settings("Adora", "Adora");

	settings.beginGroup("Watermark");

	settings.setValue("useWatermark", this->useWatermark);
	settings.setValue("imagePath", this->imagePath);
	settings.setValue("opacity", this->opacity);
	settings.setValue("layout", (int)this->layout);

	settings.endGroup();
}

/////////////////////////////////////////////////////////////////////

WritingSetting::WritingSetting()
	:useCursorHotkey(false), usePencilHotkey(false), useHighlightHotkey(false), useLineHotkey(false),
	useArrowLineHotkey(false), useNumberingHotkey(false), useEraserHotkey(false) {

}

WritingSetting::~WritingSetting() {

}


void WritingSetting::load() {

	QSettings settings("Adora", "Adora");

	settings.beginGroup("Writing");

	if (settings.contains("useCursorHotkey") == true)
		this->useCursorHotkey = settings.value("useCursorHotkey").toBool();
	if (settings.contains("cursorHotkey") == true)
		this->cursorHotkey = settings.value("cursorHotkey").toString();

	if (settings.contains("usePencilHotkey") == true)
		this->usePencilHotkey = settings.value("usePencilHotkey").toBool();
	if (settings.contains("pencilHotkey") == true)
		this->pencilHotkey = settings.value("pencilHotkey").toString();

	if (settings.contains("useHighlightHotkey") == true)
		this->useHighlightHotkey = settings.value("useHighlightHotkey").toBool();
	if (settings.contains("highlightHotkey") == true)
		this->highlightHotkey = settings.value("highlightHotkey").toString();

	if (settings.contains("useLineHotkey") == true)
		this->useLineHotkey = settings.value("useLineHotkey").toBool();
	if (settings.contains("lineHotkey") == true)
		this->lineHotkey = settings.value("lineHotkey").toString();

	if (settings.contains("useArrowLineHotkey") == true)
		this->useArrowLineHotkey = settings.value("useArrowLineHotkey").toBool();
	if (settings.contains("arrowLineHotkey") == true)
		this->arrowLineHotkey = settings.value("arrowLineHotkey").toString();

	if (settings.contains("useNumberingHotkey") == true)
		this->useNumberingHotkey = settings.value("useNumberingHotkey").toBool();
	if (settings.contains("numberingHotkey") == true)
		this->numberingHotkey = settings.value("numberingHotkey").toString();

	if (settings.contains("useEraserHotkey") == true)
		this->useEraserHotkey = settings.value("useEraserHotkey").toBool();
	if (settings.contains("eraserHotkey") == true)
		this->eraserHotkey = settings.value("eraserHotkey").toString();

	settings.endGroup();
}

void WritingSetting::save() {

	QSettings settings("Adora", "Adora");

	settings.beginGroup("Writing");


	settings.setValue("useCursorHotkey", this->useCursorHotkey);
	settings.setValue("cursorHotkey", this->cursorHotkey.toString());

	settings.setValue("usePencilHotkey", this->usePencilHotkey);
	settings.setValue("pencilHotkey", this->pencilHotkey.toString());

	settings.setValue("useHighlightHotkey", this->useHighlightHotkey);
	settings.setValue("highlightHotkey", this->highlightHotkey.toString());

	settings.setValue("useLineHotkey", this->useLineHotkey);
	settings.setValue("lineHotkey", this->lineHotkey.toString());

	settings.setValue("useArrowLineHotkey", this->useArrowLineHotkey);
	settings.setValue("arrowLineHotkey", this->arrowLineHotkey.toString());

	settings.setValue("useNumberingHotkey", this->useNumberingHotkey);
	settings.setValue("numberingHotkey", this->numberingHotkey.toString());

	settings.setValue("useEraserHotkey", this->useEraserHotkey);
	settings.setValue("eraserHotkey", this->eraserHotkey.toString());

	settings.endGroup();
}

/////////////////////////////////////////////////////////////////////

LanguageSetting::LanguageSetting()
	:language(Language::English) {

}

LanguageSetting::~LanguageSetting() {

}


void LanguageSetting::load() {

	QSettings settings("Adora", "Adora");

	settings.beginGroup("Language");

	if (settings.contains("Language") == true)
		this->language = (Language)(settings.value("Language").toInt());

	LanguageManager::getInstance()->setLanguage((LanguageManager::Language)this->language);

	settings.endGroup();
}

void LanguageSetting::save() {

	QSettings settings("Adora", "Adora");

	settings.beginGroup("Language");

	settings.setValue("Language", int(this->language));

	settings.endGroup();
}


///////////////////////////////////////////////////////////////

SettingManager::SettingManager() {

}

SettingManager::~SettingManager() {


}

void SettingManager::load() {

	QSettings settings("Adora", "Adora");
	
	if (settings.contains("AdoraPosition") == true)
		this->adoraPosition = settings.value("AdoraPosition").toPoint();

	this->generalSetting.load();
	this->videoSetting.load();
	this->audioSetting.load();
	this->imageSetting.load();
	this->timeLimitSetting.load();
	this->watermarkSetting.load();
	this->writingSetting.load();
	this->languageSetting.load();
}

void SettingManager::save() {

	QSettings settings("Adora", "Adora");

	settings.setValue("AdoraPosition", this->adoraPosition);

	this->generalSetting.save();
	this->videoSetting.save();
	this->audioSetting.save();
	this->imageSetting.save();
	this->timeLimitSetting.save();
	this->watermarkSetting.save();
	this->writingSetting.save();
	this->languageSetting.save();
}