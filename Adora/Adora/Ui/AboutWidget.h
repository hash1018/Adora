

#ifndef _ABOUTWIDGET_H
#define _ABOUTWIDGET_H

#include <qwidget.h>
#include "ui_AboutWidget.h"

class AboutWidget : public QWidget {

private:
	Ui::AboutWidget ui;

public:
	AboutWidget(QWidget *parent = nullptr);
	~AboutWidget();

protected:
	virtual void paintEvent(QPaintEvent *event);


	
};


#endif //_ABOUTWIDGET_H