

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
