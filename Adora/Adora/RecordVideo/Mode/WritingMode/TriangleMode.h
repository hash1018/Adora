

#ifndef _TRIANGLEMODE_H
#define _TRIANGLEMODE_H

#include "WritingMode.h"
#include <qpoint.h>

class Triangle;
class TriangleMode : public WritingMode {

private:
	Triangle *triangle;
	bool mousePressed;
	QPoint first;

public:
	TriangleMode(RecordVideoDialog *recordVideoDialog);
	~TriangleMode();

	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);

	virtual WritingStatus getStatus() { return WritingStatus::WritingStatus_Triangle; }

	void getTopLeftAndBottomRight(const QPoint &first, const QPoint &second, QPoint &topLeft, QPoint &bottomRight);


	virtual QCursor getCursor();

};

#endif //_TRIANGLEMODE_H