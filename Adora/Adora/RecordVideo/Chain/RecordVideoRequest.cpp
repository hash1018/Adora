

#include "RecordVideoRequest.h"

RecordVideoRequest::RecordVideoRequest(RequestType type)
	:type(type) {

}

RecordVideoRequest::~RecordVideoRequest() {

}


/////////////////////////////////////////



RecordVideoRequestChangeRecordStatus::RecordVideoRequestChangeRecordStatus(RecordStatus status)
	:RecordVideoRequest(RequestType::RequestChangeRecordStatus), status(status) {

}

RecordVideoRequestChangeRecordStatus::~RecordVideoRequestChangeRecordStatus() {


}


///////////////////////////////////////////

RecordVideoRequestKeyEvent::RecordVideoRequestKeyEvent(QKeyEvent *event)
	:RecordVideoRequest(RequestType::RequestKeyEvent), event(event) {

}

RecordVideoRequestKeyEvent::~RecordVideoRequestKeyEvent() {

}


//////////////////////////////////////////////

RecordVideoRequestChangeWritingMode::RecordVideoRequestChangeWritingMode(Mode mode)
	:RecordVideoRequest(RequestType::RequestChangeWritingMode), mode(mode) {

}

RecordVideoRequestChangeWritingMode::~RecordVideoRequestChangeWritingMode() {


}



//////////////////////////////////////////////////////////////////


RecordVideoRequestUnredo::RecordVideoRequestUnredo(Type type)
	:RecordVideoRequest(RequestType::RequestUnredo), type(type) {

}

RecordVideoRequestUnredo::~RecordVideoRequestUnredo() {


}


///////////////////////////////////////////////////////////////////

RecordVideoRequestWritingDeleteAll::RecordVideoRequestWritingDeleteAll()
	:RecordVideoRequest(RequestType::RequestWritingDeleteAll) {

}

RecordVideoRequestWritingDeleteAll::~RecordVideoRequestWritingDeleteAll() {


}