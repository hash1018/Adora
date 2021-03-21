

#ifndef _PENCILMODE_H
#define _PENCILMODE_H

#include "WritingMode.h"

class PencilMode : public WritingMode {

public:
	PencilMode(RecordVideoDialog *recordVideoDialog);
	~PencilMode();

	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);

	virtual WritingStatus getStatus() { return WritingStatus::Pencil; }
	//virtual QCursor getCursor();
};


#endif //_PENCILMODE_H