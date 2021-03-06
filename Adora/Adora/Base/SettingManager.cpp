
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
	this->languageSetting.load();
}

void SettingManager::save() {

	QSettings settings("Adora", "Adora");

	settings.setValue("AdoraPosition", this->adoraPosition);

	this->generalSetting.save();
	this->languageSetting.save();
}