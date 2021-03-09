

#ifndef _TIMELIMITSETTINGWIDGET_H
#define _TIMELIMITSETTINGWIDGET_H

#include <qwidget.h>
#include "ui_TimeLimitSettingWidget.h"

class TimeLimitSettingWidget : public QWidget {

	Q_OBJECT

private:
	Ui::TimeLimitSettingWidget ui;

public:
	TimeLimitSettingWidget(QWidget *parent = nullptr);
	~TimeLimitSettingWidget();

protected:
	virtual void paintEvent(QPaintEvent *event);

	private slots:
	void useTimeLimitCheckBoxToggled(bool checked);
	void hourSpinBoxValueChanged(int value);
	void minuteSpinBoxValueChanged(int value);
	void secondSpinBoxValueChanged(int value);
};

#endif //_TIMELIMITSETTINGWIDGET_H