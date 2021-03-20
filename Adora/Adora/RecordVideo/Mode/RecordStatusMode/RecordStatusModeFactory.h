

#ifndef _RECORDSTATUSMODEFACTORY_H
#define _RECORDSTATUSMODEFACTORY_H

#include "Base/Namespace.h"

class RecordStatusMode;
class RecordVideoDialog;

class RecordStatusModeFactory {

public:
	RecordStatusModeFactory();
	~RecordStatusModeFactory();

	static RecordStatusMode* create(RecordVideoDialog *recordVideoDialog, RecordStatus recordStatus);


};

#endif //_RECORDSTATUSMODEFACTORY_H