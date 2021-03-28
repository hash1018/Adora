

#ifndef _AUDIOSETTINGWIDGET_H
#define _AUDIOSETTINGWIDGET_H

#include "Ui/AbstractStackWidget.h"
#include "ui_AudioSettingWidget.h"

class AudioSettingWidget : public AbstractStackWidget {

	Q_OBJECT

private:
	Ui::AudioSettingWidget ui;

public:
	AudioSettingWidget(QWidget *parent = nullptr);
	~AudioSettingWidget();


	

	private slots :
	void speakerComboBoxCurrentTextChanged(const QString &text);
	void micComboBoxCurrentTextChanged(const QString &text);


};

#endif //_AUDIOSETTINGWIDGET_H