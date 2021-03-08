

#ifndef _AUDIOSETTINGWIDGET_H
#define _AUDIOSETTINGWIDGET_H

#include <qwidget.h>
#include "ui_AudioSettingWidget.h"

class AudioSettingWidget : public QWidget {

private:
	Ui::AudioSettingWidget ui;

public:
	AudioSettingWidget(QWidget *parent = nullptr);
	~AudioSettingWidget();

protected:
	virtual void paintEvent(QPaintEvent *event);

	private slots:
	void audioVolumeSliderValueChanged(int value);
	void audioVolume2SliderValueChanged(int value);


};

#endif //_AUDIOSETTINGWIDGET_H