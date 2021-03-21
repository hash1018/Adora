

#ifndef _CURSORMODE_H
#define _CURSORMODE_H

#include "WritingMode.h"

class CursorMode : public WritingMode {

public:
	CursorMode(RecordVideoDialog *recordVideoDialog);
	~CursorMode();

	virtual WritingStatus getStatus() { return WritingStatus::Cursor; }

};

#endif //_CURSORMODE_H