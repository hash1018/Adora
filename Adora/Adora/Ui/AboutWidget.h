

#ifndef _ABOUTWIDGET_H
#define _ABOUTWIDGET_H

#include <qwidget.h>

class AboutWidget : public QWidget {

public:
	AboutWidget(QWidget *parent = nullptr);
	~AboutWidget();

protected:
	virtual void paintEvent(QPaintEvent *event);

};


#endif //_ABOUTWIDGET_H