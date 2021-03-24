
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


RecordVideoWritingModeChangedEvent::RecordVideoWritingModeChangedEvent(WritingStatus writingStatus, const QColor &color, int width)
	:RecordVideoNotifyEvent(EventType::WritingModeChanged), writingStatus(writingStatus), color(color), width(width) {

}

RecordVideoWritingModeChangedEvent::~RecordVideoWritingModeChangedEvent() {


}


//////////////////////////////////////////////////////////////


RecordVideoUnredoStackCountChangedEvent::RecordVideoUnredoStackCountChangedEvent(int undoCount, int redoCount)
	:RecordVideoNotifyEvent(EventType::UnredoStackCountChanged), undoCount(undoCount), redoCount(redoCount) {

}

RecordVideoUnredoStackCountChangedEvent::~RecordVideoUnredoStackCountChangedEvent() {


}