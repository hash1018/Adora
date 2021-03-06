
#include "SettingManager.h"
#include <qsettings.h>

SettingManager::SettingManager() {

}

SettingManager::~SettingManager() {


}

void SettingManager::load() {

	QSettings settings("Adora", "Adora");
	
	if (settings.contains("AdoraPosition") == true)
		this->adoraPosition = settings.value("AdoraPosition").toPoint();
}

void SettingManager::save() {

	QSettings settings("Adora", "Adora");

	settings.setValue("AdoraPosition", this->adoraPosition);
}