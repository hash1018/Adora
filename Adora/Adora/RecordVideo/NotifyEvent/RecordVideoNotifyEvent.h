

#ifndef _RECORDVIDEONOTIFYEVENT_H
#define _RECORDVIDEONOTIFYEVENT_H

#include "Base/Namespace.h"

class RecordVideoNotifyEvent {

public:
	enum EventType {
		RecordStatusChanged,
		WritingModeChanged,
	};

protected:
	EventType type;

public:
	RecordVideoNotifyEvent(EventType type);
	virtual ~RecordVideoNotifyEvent() = 0;

	inline EventType getType() const { return this->type; }
};

///////////////////////////////////////

class RecordVideoStatusChangedEvent : public RecordVideoNotifyEvent {

private:
	RecordStatus recordStatus;

public:
	RecordVideoStatusChangedEvent(RecordStatus recordStatus);
	~RecordVideoStatusChangedEvent();

	inline RecordStatus getStatus() { return this->recordStatus; }
};



//////////////////////////////////////////

class RecordVideoWritingModeChangedEvent : public RecordVideoNotifyEvent {

private:
	WritingStatus writingStatus;

public:
	RecordVideoWritingModeChangedEvent(WritingStatus writingStatus);
	~RecordVideoWritingModeChangedEvent();

	inline WritingStatus getStatus() { return this->writingStatus; }

};

#endif //_RECORDVIDEONOTIFYEVENT_H