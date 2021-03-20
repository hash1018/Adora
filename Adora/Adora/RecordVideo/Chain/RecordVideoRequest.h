

#ifndef _RECORDVIDEOREQUEST_H
#define _RECORDVIDEOREQUEST_H


class RecordVideoRequest {

public:
	enum RequestType {

		RequestChangeRecordStatus,

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

#endif //_RECORDVIDEOREQUEST_H