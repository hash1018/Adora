

#ifndef _CONTROLLERWIDGET_H
#define _CONTROLLERWIDGET_H

#include <qwidget.h>
#include "ui_ControllerWidget.h"
#include "RecordVideo/Chain/RecordVideoChain.h"

class RecordVideoNotifyEvent;

class ControllerWidget : public QWidget , public RecordVideoChain {

private:
	Ui::ControllerWidget ui;

private:
	QPoint prev;
	bool mousePressed;

public:
	ControllerWidget(RecordVideoChain *chain);
	~ControllerWidget();
	
	void update(RecordVideoNotifyEvent *event);

protected:
	virtual void closeEvent(QCloseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void paintEvent(QPaintEvent *event);
	virtual void keyPressEvent(QKeyEvent *event);
};

#endif //_CONTROLLERWIDGET_H
