

#include "RecordStatusMode.h"

RecordStatusMode::RecordStatusMode(RecordVideoDialog *recordVideoDialog)
	:recordVideoDialog(recordVideoDialog) {

}

RecordStatusMode::~RecordStatusMode() {

}


//////////////////////////////////////////////


RecordStatusNotRecordingMode::RecordStatusNotRecordingMode(RecordVideoDialog *recordVideoDialog)
	:RecordStatusMode(recordVideoDialog) {

}

RecordStatusNotRecordingMode::~RecordStatusNotRecordingMode() {

}


////////////////////////////////////////////////


RecordStatusRecordingMode::RecordStatusRecordingMode(RecordVideoDialog *recordVideoDialog)
	:RecordStatusMode(recordVideoDialog) {

}

RecordStatusRecordingMode::~RecordStatusRecordingMode() {


}

//////////////////////////////////////////////////

RecordStatusPausedMode::RecordStatusPausedMode(RecordVideoDialog *recordVideoDialog)
	:RecordStatusMode(recordVideoDialog) {

}

RecordStatusPausedMode::~RecordStatusPausedMode() {


}