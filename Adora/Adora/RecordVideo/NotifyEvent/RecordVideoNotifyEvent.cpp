
#include "RecordVideoNotifyEvent.h"

RecordVideoNotifyEvent::RecordVideoNotifyEvent(EventType type)
	:type(type) {

}

RecordVideoNotifyEvent::~RecordVideoNotifyEvent() {

}


/////////////////////////////////////////////////////////


RecordVideoStatusChangedEvent::RecordVideoStatusChangedEvent(RecordStatus status)
	:RecordVideoNotifyEvent(EventType::RecordStatusChanged), recordStatus(status) {

}

RecordVideoStatusChangedEvent::~RecordVideoStatusChangedEvent() {


}

////////////////////////////////////////////////////////////


RecordVideoWritingModeChangedEvent::RecordVideoWritingModeChangedEvent(WritingStatus writingStatus)
	:RecordVideoNotifyEvent(EventType::WritingModeChanged), writingStatus(writingStatus) {

}

RecordVideoWritingModeChangedEvent::~RecordVideoWritingModeChangedEvent() {


}