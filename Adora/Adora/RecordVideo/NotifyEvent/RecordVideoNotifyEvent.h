

#ifndef _RECORDVIDEONOTIFYEVENT_H
#define _RECORDVIDEONOTIFYEVENT_H

#include "Base/Namespace.h"
#include <qcolor.h>

class RecordVideoNotifyEvent {

public:
	enum EventType {
		RecordStatusChanged,
		WritingModeChanged,
		UnredoStackCountChanged,
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
	QColor color;
	int width;

public:
	RecordVideoWritingModeChangedEvent(WritingStatus writingStatus, const QColor &color, int width);
	~RecordVideoWritingModeChangedEvent();

	inline WritingStatus getStatus() { return this->writingStatus; }
	inline const QColor& getColor() const { return this->color; }
	inline int getWidth() const { return this->width; }

};


/////////////////////////////////////////////

class RecordVideoUnredoStackCountChangedEvent : public RecordVideoNotifyEvent {

private:
	int undoCount;
	int redoCount;

public:
	RecordVideoUnredoStackCountChangedEvent(int undoCount, int redoCount);
	~RecordVideoUnredoStackCountChangedEvent();

	inline int getUndoCount() const { return this->undoCount; }
	inline int getRedoCount() const { return this->redoCount; }
};

#endif //_RECORDVIDEONOTIFYEVENT_H