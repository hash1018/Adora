

#include "AudioSettingWidget.h"
#include "Base/SettingManager.h"

AudioSettingWidget::AudioSettingWidget(QWidget *parent)
	:QWidget(parent) {

	ui.setupUi(this);

	ui.audioVolumeSlider->setValue(SettingManager::getInstance()->getAudioSetting()->getAudioVolume());
	ui.audioVolume2Slider->setValue(SettingManager::getInstance()->getAudioSetting()->getAudioVolume2());

	connect(ui.audioVolumeSlider, &QSlider::valueChanged, this, &AudioSettingWidget::audioVolumeSliderValueChanged);
	connect(ui.audioVolume2Slider, &QSlider::valueChanged, this, &AudioSettingWidget::audioVolume2SliderValueChanged);
}

AudioSettingWidget::~AudioSettingWidget() {

}

//#include <qpainter.h>
void AudioSettingWidget::paintEvent(QPaintEvent *event) {

	//QPainter painter(this);
	//painter.fillRect(this->rect(), QColor(25, 25, 100));
}


void AudioSettingWidget::audioVolumeSliderValueChanged(int value) {

	SettingManager::getInstance()->getAudioSetting()->setAudioVolume(value);
}

void AudioSettingWidget::audioVolume2SliderValueChanged(int value) {

	SettingManager::getInstance()->getAudioSetting()->setAudioVolume2(value);
}
