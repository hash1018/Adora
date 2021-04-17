

#include "AudioSettingWidget.h"
#include "Base/SettingManager.h"
#include "lib/multimedia/AudioDeviceList.h"
#include "Base/LanguageManager.h"
#include <qdebug.h>
AudioSettingWidget::AudioSettingWidget(QWidget *parent)
	:AbstractStackWidget(parent) {

	ui.setupUi(this);


	QString str = "<b>" + getLanUiValue("MenuAudio/Audio Device Setting") + "</b>";
	ui.audioDeviceSettingLabel->setTextFormat(Qt::RichText);
	ui.audioDeviceSettingLabel->setText(str);

	ui.speakerLabel->setText(getLanUiValue("MenuAudio/Speaker"));
	ui.micLabel->setText(getLanUiValue("MenuAudio/Microphone"));

	ui.speakerComboBox->addItem(getLanUiValue("MenuAudio/Not used"));
	ui.speakerComboBox->addItems(AudioDeviceList::getDeviceList(eRender));
	
	if (ui.speakerComboBox->findText(SettingManager::getInstance()->getAudioSetting()->getSpeakerDevice()) == -1) {
	
		ui.speakerComboBox->setCurrentIndex(0);
		SettingManager::getInstance()->getAudioSetting()->setSpeakerDevice(getLanUiValue("MenuAudio/Not used"));
	}
	else {
	
		ui.speakerComboBox->setCurrentText(SettingManager::getInstance()->getAudioSetting()->getSpeakerDevice());
	}

	ui.micComboBox->addItem(getLanUiValue("MenuAudio/Not used"));
	ui.micComboBox->addItems(AudioDeviceList::getDeviceList(eCapture));

	if (ui.micComboBox->findText(SettingManager::getInstance()->getAudioSetting()->getMicDevice()) == -1) {

		ui.micComboBox->setCurrentIndex(0);
		SettingManager::getInstance()->getAudioSetting()->setMicDevice(getLanUiValue("MenuAudio/Not used"));
	}
	else {

		ui.micComboBox->setCurrentText(SettingManager::getInstance()->getAudioSetting()->getMicDevice());
	}

	connect(ui.speakerComboBox, SIGNAL(currentTextChanged(const QString&)), this, SLOT(speakerComboBoxCurrentTextChanged(const QString&)));
	connect(ui.micComboBox, SIGNAL(currentTextChanged(const QString&)), this, SLOT(micComboBoxCurrentTextChanged(const QString&)));
	
}

AudioSettingWidget::~AudioSettingWidget() {

}

void AudioSettingWidget::speakerComboBoxCurrentTextChanged(const QString &text) {

	SettingManager::getInstance()->getAudioSetting()->setSpeakerDevice(text);
}

void AudioSettingWidget::micComboBoxCurrentTextChanged(const QString &text) {

	SettingManager::getInstance()->getAudioSetting()->setMicDevice(text);
}