

#include "RecordStatusModeFactory.h"
#include "RecordVideo/Mode/RecordStatusMode/RecordStatusMode.h"

RecordStatusModeFactory::RecordStatusModeFactory() {

}

RecordStatusModeFactory::~RecordStatusModeFactory() {

}

RecordStatusMode* RecordStatusModeFactory::create(RecordVideoDialog *recordVideoDialog, RecordStatus recordStatus) {

	if (recordStatus == RecordStatus::NotRecording)
		return new RecordStatusNotRecordingMode(recordVideoDialog);

	if (recordStatus == RecordStatus::Recording)
		return new RecordStatusRecordingMode(recordVideoDialog);

	return new RecordStatusPausedMode(recordVideoDialog);
}