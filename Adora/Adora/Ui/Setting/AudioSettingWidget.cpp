

#include "AudioSettingWidget.h"
#include "Base/SettingManager.h"

AudioSettingWidget::AudioSettingWidget(QWidget *parent)
	:AbstractStackWidget(parent) {

	ui.setupUi(this);

	ui.audioVolumeSlider->setValue(SettingManager::getInstance()->getAudioSetting()->getAudioVolume());
	ui.audioVolume2Slider->setValue(SettingManager::getInstance()->getAudioSetting()->getAudioVolume2());

	ui.audioVolumeSlider->setSubPageColor("#FFB512");
	ui.audioVolumeSlider->setAddPageColor("#D2D2D2");
	ui.audioVolumeSlider->setGrooveHeight(4);
	ui.audioVolumeSlider->setHandleImage(":/Main/slider_indicator");

	ui.audioVolume2Slider->setSubPageColor("#FFB512");
	ui.audioVolume2Slider->setAddPageColor("#D2D2D2");
	ui.audioVolume2Slider->setGrooveHeight(4);
	ui.audioVolume2Slider->setHandleImage(":/Main/slider_indicator");

	connect(ui.audioVolumeSlider, &QSlider::valueChanged, this, &AudioSettingWidget::audioVolumeSliderValueChanged);
	connect(ui.audioVolume2Slider, &QSlider::valueChanged, this, &AudioSettingWidget::audioVolume2SliderValueChanged);
}

AudioSettingWidget::~AudioSettingWidget() {

}

void AudioSettingWidget::audioVolumeSliderValueChanged(int value) {

	SettingManager::getInstance()->getAudioSetting()->setAudioVolume(value);
}

void AudioSettingWidget::audioVolume2SliderValueChanged(int value) {

	SettingManager::getInstance()->getAudioSetting()->setAudioVolume2(value);
}
