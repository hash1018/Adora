

#ifndef _ERASERMODE_H
#define _ERASERMODE_H

#include "WritingMode.h"

class EraserMode : public WritingMode {

private:
	bool mousePressed;

public:
	EraserMode(RecordVideoDialog *recordVideoDialog);
	~EraserMode();

	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);

	virtual WritingStatus getStatus() { return WritingStatus::Eraser; }

	virtual QCursor getCursor();

};

#endif //_ERASERMODE_H
