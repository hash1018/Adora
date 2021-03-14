

#ifndef _AUDIOSETTINGWIDGET_H
#define _AUDIOSETTINGWIDGET_H

#include "Ui/AbstractStackWidget.h"
#include "ui_AudioSettingWidget.h"

class AudioSettingWidget : public AbstractStackWidget {

private:
	Ui::AudioSettingWidget ui;

public:
	AudioSettingWidget(QWidget *parent = nullptr);
	~AudioSettingWidget();

protected:
	

	private slots:
	void audioVolumeSliderValueChanged(int value);
	void audioVolume2SliderValueChanged(int value);


};

#endif //_AUDIOSETTINGWIDGET_H