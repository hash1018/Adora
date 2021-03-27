

#ifndef _CIRCLEMODE_H
#define _CIRCLEMODE_H

#include "WritingMode.h"
#include <qpoint.h>

class Circle;
class CircleMode : public WritingMode {

private:
	Circle *circle;
	bool mousePressed;
	QPoint center;

public:
	CircleMode(RecordVideoDialog *recordVideoDialog);
	~CircleMode();

	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);

	virtual WritingStatus getStatus() { return WritingStatus::WritingStatus_Circle; }
	
	virtual QCursor getCursor();

};

#endif //_CIRCLEMODE_H