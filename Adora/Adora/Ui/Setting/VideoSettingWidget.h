

#ifndef _VIDEOSETTINGWIDGET_H
#define _VIDEOSETTINGWIDGET_H

#include <qwidget.h>
#include "ui_VideoSettingWidget.h"

class VideoSettingWidget : public QWidget {

	Q_OBJECT

private:
	Ui::VideoSettingWidget ui;

public:
	VideoSettingWidget(QWidget *parent = nullptr);
	~VideoSettingWidget();

protected:
	virtual void paintEvent(QPaintEvent *event);

	private slots:
	void startStopCheckBoxToggled(bool checked);
	void pauseResumeCheckBoxToggled(bool checked);
	void includeCursorCheckBoxToggled(bool checked);
	void useHwEncoderCheckBoxToggled(bool checked);
	void fpsComboBoxCurrentTextChanged(const QString &text);
	void videoBitrateSpinBoxValueChanged(int value);
	


};

#endif //_VIDEOSETTINGWIDGET_H