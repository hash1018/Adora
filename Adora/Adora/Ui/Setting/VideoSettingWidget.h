

#ifndef _VIDEOSETTINGWIDGET_H
#define _VIDEOSETTINGWIDGET_H

#include "Ui/AbstractStackWidget.h"
#include "ui_VideoSettingWidget.h"

class VideoSettingWidget : public AbstractStackWidget {

	Q_OBJECT

private:
	Ui::VideoSettingWidget ui;

public:
	VideoSettingWidget(QWidget *parent = nullptr);
	~VideoSettingWidget();

protected:

	private slots:
	void startStopCheckBoxToggled(bool checked);
	void startStopHotkeyEmitted(const QKeySequence &keySequence);

	void pauseResumeCheckBoxToggled(bool checked);
	void pauseResumeHotkeyEmitted(const QKeySequence &keySequence);

	void includeCursorCheckBoxToggled(bool checked);
	void useHwEncoderCheckBoxToggled(bool checked);
	void fpsComboBoxCurrentTextChanged(const QString &text);
	void videoBitrateSpinBoxValueChanged(int value);
	


};

#endif //_VIDEOSETTINGWIDGET_H