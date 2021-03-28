

#include "SoundPanel.h"
#include "Base/LanguageManager.h"
#include "Base/SettingManager.h"


SoundPanel::SoundPanel(QWidget *parent)
	:QWidget(parent) {

	ui.setupUi(this);


	connect(ui.micButton, &QPushButton::clicked, this, &SoundPanel::micButtonClicked);
	connect(ui.speakerButton, &QPushButton::clicked, this, &SoundPanel::speakerButtonClicked);

	if (SettingManager::getInstance()->getAudioSetting()->getMicDevice() == getLanUiValue("MenuAudio/Not used")) {
		ui.micButton->setDisabled(true);
	}
	else {
		ui.micButton->setDisabled(false);
	}

	ui.micButton->updateSelected(SettingManager::getInstance()->getAudioSetting()->getMicMuted());
	ui.micButton->setToolTip(SettingManager::getInstance()->getAudioSetting()->getMicDevice());

	if (SettingManager::getInstance()->getAudioSetting()->getSpeakerDevice() == getLanUiValue("MenuAudio/Not used")) {
		ui.speakerButton->setDisabled(true);
	}
	else {
		ui.speakerButton->setDisabled(false);
	}

	ui.speakerButton->updateSelected(SettingManager::getInstance()->getAudioSetting()->getSpeakerMuted());
	ui.speakerButton->setToolTip(SettingManager::getInstance()->getAudioSetting()->getSpeakerDevice());

}

SoundPanel::~SoundPanel() {

}


void SoundPanel::speakerButtonClicked() {
	
	bool checked = ui.speakerButton->isChecked();

	ui.speakerButton->updateSelected(!checked);
	SettingManager::getInstance()->getAudioSetting()->setSpeakerMuted(!checked);
}

void SoundPanel::micButtonClicked() {

	bool checked = ui.micButton->isChecked();
	ui.micButton->updateSelected(!checked);
	SettingManager::getInstance()->getAudioSetting()->setMicMuted(!checked);
}