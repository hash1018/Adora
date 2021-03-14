

#ifndef _ABSTRACTSTACKWIDGET_H
#define _ABSTRACTSTACKWIDGET_H

#include <qwidget.h>

class AbstractStackWidget : public QWidget {

public:
	AbstractStackWidget(QWidget *parent = nullptr);
	~AbstractStackWidget();

protected:
	virtual void paintEvent(QPaintEvent *event);
};

#endif //_ABSTRACTSTACKWIDGET_H
