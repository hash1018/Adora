

#ifndef _ARROWLINEMODE_H
#define _ARROWLINEMODE_H

#include "WritingMode.h"

class ArrowLineSegment;

class ArrowLineMode : public WritingMode {

private:
	ArrowLineSegment *arrowLineSegment;
	bool mousePressed;

public:
	ArrowLineMode(RecordVideoDialog *recordVideoDialog);
	~ArrowLineMode();

	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);

	virtual WritingStatus getStatus() { return WritingStatus::ArrowLine; }
};


#endif //_ARROWLINEMODE_H