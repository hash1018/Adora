

#ifndef _CONTROLLERWIDGET_H
#define _CONTROLLERWIDGET_H

#include <qwidget.h>

class ControllerWidget : public QWidget {

private:
	QPoint prev;
	bool mousePressed;

public:
	ControllerWidget();
	~ControllerWidget();
	
protected:
	virtual void closeEvent(QCloseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);


};

#endif //_CONTROLLERWIDGET_H
