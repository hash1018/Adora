

#include "SoundPanel.h"
#include "Base/LanguageManager.h"
#include "Base/SettingManager.h"
#include "RecordVideo/Chain/RecordVideoRequest.h"
#include "RecordVideo/NotifyEvent/RecordVideoNotifyEvent.h"
#include "lib/multimedia/VolumeLevelGetter.h"

SoundPanel::SoundPanel(QWidget *parent)
	:QWidget(parent), speakerVolumeGetter(nullptr), micVolumeGetter(nullptr) {

	ui.setupUi(this);


	connect(ui.micButton, &QPushButton::clicked, this, &SoundPanel::micButtonClicked);
	connect(ui.speakerButton, &QPushButton::clicked, this, &SoundPanel::speakerButtonClicked);

	if (SettingManager::getInstance()->getAudioSetting()->getMicDevice() == getLanUiValue("MenuAudio/Not used")) {
		ui.micButton->setDisabled(true);
		ui.micAmplitudeRenderWidget->setDisabled(true);
	}
	else {
		ui.micButton->setDisabled(false);

		this->micVolumeGetter = new VolumeLevelGetter(this);
		this->micVolumeGetter->init(eCapture, SettingManager::getInstance()->getAudioSetting()->getMicDevice());

		connect(this->micVolumeGetter, &VolumeLevelGetter::amplitudeChanged, this, &SoundPanel::micAmplitudeChanged);
		this->micVolumeGetter->start();

		ui.micButton->updateSelected(SettingManager::getInstance()->getAudioSetting()->getMicMuted());
		ui.micButton->setToolTip(SettingManager::getInstance()->getAudioSetting()->getMicDevice());

		ui.micAmplitudeRenderWidget->setDisabled(SettingManager::getInstance()->getAudioSetting()->getMicMuted());
	}

	

	if (SettingManager::getInstance()->getAudioSetting()->getSpeakerDevice() == getLanUiValue("MenuAudio/Not used")) {
		ui.speakerButton->setDisabled(true);
		ui.speakerAmplitudeRenderWidget->setDisabled(true);
	}
	else {
		ui.speakerButton->setDisabled(false);

		this->speakerVolumeGetter = new VolumeLevelGetter(this);
		connect(this->speakerVolumeGetter, &VolumeLevelGetter::amplitudeChanged, this, &SoundPanel::speakerAmplitudeChanged);

		this->speakerVolumeGetter->init(eRender, SettingManager::getInstance()->getAudioSetting()->getSpeakerDevice());
		this->speakerVolumeGetter->start();

		ui.speakerButton->updateSelected(SettingManager::getInstance()->getAudioSetting()->getSpeakerMuted());
		ui.speakerButton->setToolTip(SettingManager::getInstance()->getAudioSetting()->getSpeakerDevice());

		ui.speakerAmplitudeRenderWidget->setDisabled(SettingManager::getInstance()->getAudioSetting()->getSpeakerMuted());
	}

	

}

SoundPanel::~SoundPanel() {

	
}


void SoundPanel::update(RecordVideoNotifyEvent *event) {

	if (event->getType() == RecordVideoNotifyEvent::EventType::AudioMutedChanged) {
	
		QString deviceName = dynamic_cast<AudioMutedChangedEvent*>(event)->getDeviceName();
		bool muted = dynamic_cast<AudioMutedChangedEvent*>(event)->getMuted();

		if (SettingManager::getInstance()->getAudioSetting()->getMicDevice() == deviceName) {
			ui.micButton->updateSelected(muted);
			ui.micAmplitudeRenderWidget->setDisabled(muted);
		}
		else if (SettingManager::getInstance()->getAudioSetting()->getSpeakerDevice() == deviceName) {
			ui.speakerButton->updateSelected(muted);
			ui.speakerAmplitudeRenderWidget->setDisabled(muted);
		}
	}
	else if (event->getType() == RecordVideoNotifyEvent::EventType::AboutToFinished) {

		
		if (this->speakerVolumeGetter != nullptr) {
		
			this->speakerVolumeGetter->quit();
			this->speakerVolumeGetter->wait();
		}

		if (this->micVolumeGetter != nullptr) {
		
			this->micVolumeGetter->quit();
			this->micVolumeGetter->wait();
		}
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


void SoundPanel::speakerAmplitudeChanged(float level) {

	ui.speakerAmplitudeRenderWidget->setAmplitude(level);
}

void SoundPanel::micAmplitudeChanged(float level) {

	ui.micAmplitudeRenderWidget->setAmplitude(level);
}