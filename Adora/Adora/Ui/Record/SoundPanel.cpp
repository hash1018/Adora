

#include "SoundPanel.h"
#include "Base/LanguageManager.h"
#include "Base/SettingManager.h"
#include "RecordVideo/Chain/RecordVideoRequest.h"
#include "RecordVideo/NotifyEvent/RecordVideoNotifyEvent.h"

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


void SoundPanel::update(RecordVideoNotifyEvent *event) {

	if (event->getType() == RecordVideoNotifyEvent::EventType::AudioMutedChanged) {
	
		QString deviceName = dynamic_cast<AudioMutedChangedEvent*>(event)->getDeviceName();
		bool muted = dynamic_cast<AudioMutedChangedEvent*>(event)->getMuted();

		if (SettingManager::getInstance()->getAudioSetting()->getMicDevice() == deviceName)
			ui.micButton->updateSelected(muted);
		else if (SettingManager::getInstance()->getAudioSetting()->getSpeakerDevice() == deviceName)
			ui.speakerButton->updateSelected(muted);
	}
}

void SoundPanel::speakerButtonClicked() {

	RecordVideoRequestMuteAudio request(SettingManager::getInstance()->getAudioSetting()->getSpeakerDevice(),
		!SettingManager::getInstance()->getAudioSetting()->getSpeakerMuted());
	this->request(&request);
}

void SoundPanel::micButtonClicked() {

	RecordVideoRequestMuteAudio request(SettingManager::getInstance()->getAudioSetting()->getMicDevice(),
		!SettingManager::getInstance()->getAudioSetting()->getMicMuted());
	this->request(&request);
}