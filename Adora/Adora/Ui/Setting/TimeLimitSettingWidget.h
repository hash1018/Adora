

#ifndef _TIMELIMITSETTINGWIDGET_H
#define _TIMELIMITSETTINGWIDGET_H

#include <qwidget.h>

class TimeLimitSettingWidget : public QWidget {

public:
	TimeLimitSettingWidget(QWidget *parent = nullptr);
	~TimeLimitSettingWidget();

protected:
	virtual void paintEvent(QPaintEvent *event);

};

#endif //_TIMELIMITSETTINGWIDGET_H