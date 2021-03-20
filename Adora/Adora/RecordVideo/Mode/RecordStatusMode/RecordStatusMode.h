

#ifndef _RECORDSTATUSMODE_H
#define _RECORDSTATUSMODE_H

#include "Base/Namespace.h"
class RecordVideoDialog;

class RecordStatusMode {

protected:
	RecordVideoDialog *recordVideoDialog;

public:
	RecordStatusMode(RecordVideoDialog *recordVideoDialog);
	virtual ~RecordStatusMode() = 0;

	virtual RecordStatus getStatus() = 0;
};


///////////////////////////////////////////////////////////

class RecordStatusNotRecordingMode : public RecordStatusMode {

public:
	RecordStatusNotRecordingMode(RecordVideoDialog *recordVideoDialog);
	~RecordStatusNotRecordingMode();

	virtual RecordStatus getStatus() { return RecordStatus::NotRecording; }

};

///////////////////////////////////////////////////////////

class RecordStatusRecordingMode : public RecordStatusMode {

public:
	RecordStatusRecordingMode(RecordVideoDialog *recordVideoDialog);
	~RecordStatusRecordingMode();

	virtual RecordStatus getStatus() { return RecordStatus::Recording; }

};


/////////////////////////////////////////////////////////////

class RecordStatusPausedMode : public RecordStatusMode {

public:
	RecordStatusPausedMode(RecordVideoDialog *recordVideoDialog);
	~RecordStatusPausedMode();

	virtual RecordStatus getStatus() { return RecordStatus::Paused; }

};

#endif //_RECORDSTATUSMODE_H