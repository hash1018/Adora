
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


/////////////////////////////////////////////////////////////


RecordVideoWritingDataChangedEvent::RecordVideoWritingDataChangedEvent(const QColor &color)
	:RecordVideoNotifyEvent(EventType::WritingDataChanged), changedType(ChangedType::ChangedType_Color),
	color(color) {

}

RecordVideoWritingDataChangedEvent::RecordVideoWritingDataChangedEvent(int width)
	: RecordVideoNotifyEvent(EventType::WritingDataChanged), changedType(ChangedType::ChangedType_Width),
	width(width) {

}

RecordVideoWritingDataChangedEvent::~RecordVideoWritingDataChangedEvent() {


}


///////////////////////////////////////////////////////////


RecordTimePassedEvent::RecordTimePassedEvent(const Time &time)
	:RecordVideoNotifyEvent(EventType::RecordTimePassed), time(time) {

}

RecordTimePassedEvent::~RecordTimePassedEvent() {


}


////////////////////////////////////////////////////////////

AudioMutedChangedEvent::AudioMutedChangedEvent(const QString &deviceName, bool muted)
	:RecordVideoNotifyEvent(EventType::AudioMutedChanged), deviceName(deviceName), muted(muted) {

}

AudioMutedChangedEvent::~AudioMutedChangedEvent() {


}