

#ifndef _NUMBERINGMODE_H
#define _NUMBERINGMODE_H

#include "WritingMode.h"

class NumberingMode : public WritingMode {

public:
	NumberingMode(RecordVideoDialog *recordVideoDialog);
	~NumberingMode();

	virtual void mousePressEvent(QMouseEvent *event);

	virtual WritingStatus getStatus() { return WritingStatus::Numbering; }


	virtual QCursor getCursor();
};


#endif //_NUMBERINGMODE_H