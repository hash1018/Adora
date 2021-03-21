

#ifndef _WRITINGMODE_H
#define _WRITINGMODE_H

#include "Base/Namespace.h"
#include <qcursor.h>

class WritingMode;
class RecordVideoDialog;
class QMouseEvent;
class WritingLayer;

class WritingMode {

protected:
	RecordVideoDialog *recordVideoDialog;

private:
	WritingLayer *writingLayer;

public:
	WritingMode(RecordVideoDialog *recordVideoDialog);
	virtual ~WritingMode() = 0;


	virtual void mousePressEvent(QMouseEvent *event) {}
	virtual void mouseMoveEvent(QMouseEvent *event) {}
	virtual void mouseReleaseEvent(QMouseEvent *event) {}

	virtual WritingStatus getStatus() = 0;
	virtual QCursor getCursor() { return QCursor(Qt::CursorShape::ArrowCursor); }


protected:
	void createWritingLayer();
	void deleteWritingLayer();
};


#endif //_WRITINGMODE_H
