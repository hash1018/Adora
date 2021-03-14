

#ifndef _TIMELIMITSETTINGWIDGET_H
#define _TIMELIMITSETTINGWIDGET_H

#include "Ui/AbstractStackWidget.h"
#include "ui_TimeLimitSettingWidget.h"

class TimeLimitSettingWidget : public AbstractStackWidget {

	Q_OBJECT

private:
	Ui::TimeLimitSettingWidget ui;

public:
	TimeLimitSettingWidget(QWidget *parent = nullptr);
	~TimeLimitSettingWidget();

protected:

	private slots:
	void useTimeLimitCheckBoxToggled(bool checked);
	void hourSpinBoxValueChanged(int value);
	void minuteSpinBoxValueChanged(int value);
	void secondSpinBoxValueChanged(int value);
};

#endif //_TIMELIMITSETTINGWIDGET_H