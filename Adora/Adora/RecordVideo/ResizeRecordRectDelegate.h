

#ifndef _RESIZERECORDRECTDELEGATE_H
#define _RESIZERECORDRECTDELEGATE_H

#include <qobject.h>
#include "Base/Namespace.h"
#include <qpoint.h>

class RecordVideoDialog;
class QMouseEvent;
class QTimer;
class QPainter;

class ResizeRecordRectDelegate : public QObject {

private:
	RecordVideoDialog *recordVideoDialog;

private:
	bool mousePressed;
	QPoint prev;

protected:
	QTimer *timer;
	bool showReiszedRect;

private:
	ResizeBehavior resizeBehavior;

public:
	ResizeRecordRectDelegate(RecordVideoDialog *recordVideoDialog);
	~ResizeRecordRectDelegate();

	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void paintEvent(QPainter &painter);


	private slots:
	void timePassed();


private:
	bool resize(const QPoint &prev, const QPoint &current);
	void getResizeBehavior(const QRect &rect, QMouseEvent *event);
	bool containsInScreen(const QRect &rect);

};

#endif //_RESIZERECORDRECTDELEGATE_H
