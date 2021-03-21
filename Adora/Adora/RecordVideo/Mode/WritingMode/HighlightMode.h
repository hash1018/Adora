

#ifndef _HIGHLIGHTMODE_H
#define _HIGHLIGHTMODE_H

#include "WritingMode.h"

class HighlightedFreeCurve;

class HighlightMode : public WritingMode {


private:
	bool mousePressed;
	HighlightedFreeCurve *highlightedFreeCurve;

public:
	HighlightMode(RecordVideoDialog *recordVideoDialog);
	~HighlightMode();

	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);

	virtual WritingStatus getStatus() { return WritingStatus::Highlight; }
	//virtual QCursor getCursor();

};


#endif //_HIGHLIGHTMODE_H