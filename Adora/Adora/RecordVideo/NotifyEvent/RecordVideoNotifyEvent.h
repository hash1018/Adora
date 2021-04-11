

#ifndef _RECORDVIDEONOTIFYEVENT_H
#define _RECORDVIDEONOTIFYEVENT_H

#include "Base/Namespace.h"
#include <qcolor.h>
#include "Base\Time.h"

class RecordVideoNotifyEvent {

public:
	enum EventType {
		RecordStatusChanged,
		WritingModeChanged,
		UnredoStackCountChanged,
		WritingDataChanged,
		RecordTimePassed,
		AudioMutedChanged,
		AboutToFinished,
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

////////////////////////////////////////////////

class RecordVideoWritingDataChangedEvent : public RecordVideoNotifyEvent {

public:
	enum ChangedType {

		ChangedType_Color,
		ChangedType_Width,
	};

private:
	ChangedType changedType;
	QColor color;
	int width;

public:
	RecordVideoWritingDataChangedEvent(const QColor &color);
	RecordVideoWritingDataChangedEvent(int width);
	~RecordVideoWritingDataChangedEvent();

	inline ChangedType getChangedType() const { return this->changedType; }
	inline const QColor& getColor() const { return this->color; }
	inline int getWidth() const { return this->width; }
	
};

/////////////////////////////////////////////////////////////////////////

class RecordTimePassedEvent : public RecordVideoNotifyEvent {

private:
	Time time;

public:
	RecordTimePassedEvent(const Time &time);
	~RecordTimePassedEvent();

	inline const Time& getTime() const { return this->time; }

};

///////////////////////////////////////////////////////////////////////

class AudioMutedChangedEvent : public RecordVideoNotifyEvent {

private:
	QString deviceName;
	bool muted;

public:
	AudioMutedChangedEvent(const QString &deviceName, bool muted);
	~AudioMutedChangedEvent();

	inline const QString& getDeviceName() const { return this->deviceName; }
	inline bool getMuted() const { return this->muted; }

};

/////////////////////////////////////////////////////////////////////////

class RecordVideoDialogAboutToFinishEvent : public RecordVideoNotifyEvent {

public:
	RecordVideoDialogAboutToFinishEvent();
	~RecordVideoDialogAboutToFinishEvent();

};

#endif //_RECORDVIDEONOTIFYEVENT_H