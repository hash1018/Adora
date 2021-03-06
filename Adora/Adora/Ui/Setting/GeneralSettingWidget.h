

#ifndef _GENERALSETTINGWIDGET_H
#define _GENERALSETTINGWIDGET_H

#include <qwidget.h>

class GeneralSettingWidget : public QWidget {

public:
	GeneralSettingWidget(QWidget *parent = nullptr);
	~GeneralSettingWidget();

protected:
	virtual void paintEvent(QPaintEvent *event);

};

#endif //_GENERALSETTINGWIDGET_H
