
#include "SettingManager.h"
#include <qsettings.h>
#include "LanguageManager.h"

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

	this->languageSetting.load();
}

void SettingManager::save() {

	QSettings settings("Adora", "Adora");

	settings.setValue("AdoraPosition", this->adoraPosition);

	this->languageSetting.save();
}