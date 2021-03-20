

#ifndef _RECORDVIDEOREQUEST_H
#define _RECORDVIDEOREQUEST_H


class QKeyEvent;

class RecordVideoRequest {

public:
	enum RequestType {

		RequestChangeRecordStatus,
		RequestKeyEvent,

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

class RecordVideoRequestKeyEvent : public RecordVideoRequest {

private:
	QKeyEvent *event;

public:
	RecordVideoRequestKeyEvent(QKeyEvent *event);
	~RecordVideoRequestKeyEvent();

	inline QKeyEvent* getKeyEvent() const { return this->event; }

};

#endif //_RECORDVIDEOREQUEST_H