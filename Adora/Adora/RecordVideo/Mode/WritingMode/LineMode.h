

#ifndef _LINEMODE_H
#define _LINEMODE_H

#include "WritingMode.h"

class LineSegment;

class LineMode : public WritingMode {

private:
	LineSegment *lineSegment;
	bool mousePressed;

public:
	LineMode(RecordVideoDialog *recordVideoDialog);
	~LineMode();

	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);

	virtual WritingStatus getStatus() { return WritingStatus::Line; }

	virtual QCursor getCursor();
};


#endif //_LINEMODE_H