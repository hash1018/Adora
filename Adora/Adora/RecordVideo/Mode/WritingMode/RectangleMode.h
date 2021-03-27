

#ifndef _RECTANGLEMODE_H
#define _RECTANGLEMODE_H

#include "WritingMode.h"
#include <qpoint.h>
class Rect;
class RectangleMode : public WritingMode {

private:
	Rect *rect;
	bool mousePressed;
	QPoint first;

public:
	RectangleMode(RecordVideoDialog *recordVideoDialog);
	~RectangleMode();

	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);

	virtual WritingStatus getStatus() { return WritingStatus::WritingStatus_Rectangle; }


	void getTopLeftAndBottomRight(const QPoint &first, const QPoint &second, QPoint &topLeft, QPoint &bottomRight);

	virtual QCursor getCursor();
};

#endif //_RECTANGLEMODE_H
