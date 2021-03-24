

#ifndef _RECORDVIDEOREQUEST_H
#define _RECORDVIDEOREQUEST_H


class QKeyEvent;
#include <qcolor.h>

class RecordVideoRequest {

public:
	enum RequestType {

		RequestChangeRecordStatus,
		RequestKeyEvent,
		RequestChangeWritingMode,
		RequestUnredo,
		RequestWritingDeleteAll,
		RequestChangeWritingData,
	};

protected:
	RequestType type;

public:
	RecordVideoRequest(RequestType type);
	virtual ~RecordVideoRequest() = 0;

	inline RequestType getType() const { return this->type; }
};


////////////////////////////////////////////


class RecordVideoRequestChangeRecordStatus : public RecordVideoRequest {

public:
	enum RecordStatus {
		Quit,
		Pause,
		Record,
		Stop,
		Resume,
		Capture,
	};

private:
	RecordStatus status;

public:
	RecordVideoRequestChangeRecordStatus(RecordStatus status);
	~RecordVideoRequestChangeRecordStatus();

	inline RecordStatus getRecordStatus() const { return this->status; }
};


//////////////////////////////////////////////////////

class RecordVideoRequestKeyEvent : public RecordVideoRequest {

private:
	QKeyEvent *event;

public:
	RecordVideoRequestKeyEvent(QKeyEvent *event);
	~RecordVideoRequestKeyEvent();

	inline QKeyEvent* getKeyEvent() const { return this->event; }

};

////////////////////////////////////////////////////////

class RecordVideoRequestChangeWritingMode : public RecordVideoRequest {

public:
	enum Mode {
		Cursor,
		Pencil,
		Eraser,
		Highlight,
		Line,
		ArrowLine,
		Numbering,
	};

private:
	Mode mode;

public:
	RecordVideoRequestChangeWritingMode(Mode mode);
	~RecordVideoRequestChangeWritingMode();

	inline Mode getMode() const { return this->mode; }

};

///////////////////////////////////////////////////////////////


class RecordVideoRequestUnredo : public RecordVideoRequest {

public:
	enum Type {
		Undo,
		Redo,
	};

private:
	Type type;

public:
	RecordVideoRequestUnredo(Type type);
	~RecordVideoRequestUnredo();

	inline Type getType() const { return this->type; }

};

///////////////////////////////////////////////////////////////


class RecordVideoRequestWritingDeleteAll : public RecordVideoRequest {

public:
	RecordVideoRequestWritingDeleteAll();
	~RecordVideoRequestWritingDeleteAll();
};

///////////////////////////////////////////////////////////////

class RecordVideoRequestChangeWritingData : public RecordVideoRequest {

public:
	enum Type {
		ChangeColor,
		ChangeWidth,
	};

private:
	Type type;
	QColor color;
	int width;

public:
	RecordVideoRequestChangeWritingData(const QColor &color);
	RecordVideoRequestChangeWritingData(int width);
	~RecordVideoRequestChangeWritingData();

public:
	inline Type getType() const { return this->type; }
	inline const QColor& getColor() const { return this->color; }
	inline int getWidth() const { return this->width; }
};

#endif //_RECORDVIDEOREQUEST_H