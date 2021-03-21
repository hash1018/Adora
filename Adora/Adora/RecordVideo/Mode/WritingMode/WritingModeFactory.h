

#ifndef _WRITINGMODEFACTORY_H
#define _WRITINGMODEFACTORY_H

#include "Base/Namespace.h"

class RecordVideoDialog;
class WritingMode;

class WritingModeFactory {

public:
	WritingModeFactory();
	~WritingModeFactory();

	static WritingMode* create(RecordVideoDialog *recordVideoDialog, WritingStatus writingStatus);
};

#endif //_WRITINGMODEFACTORY_H