

#ifndef _RECORDVIDEOREQUESTSTRATEGY_H
#define _RECORDVIDEOREQUESTSTRATEGY_H


class RecordVideoDialog;
class RecordVideoRequest;


class RecordVideoRequestStrategy {

protected:
	RecordVideoDialog *recordVideoDialog;
	RecordVideoRequest *request;

public:
	RecordVideoRequestStrategy(RecordVideoDialog *recordVideoDialog, RecordVideoRequest *request);
	virtual ~RecordVideoRequestStrategy() = 0;

	virtual bool response() = 0;

};


////////////////////////////////////////////////////

class RecordVideoRequestChangeRecordStatusStrategy : public RecordVideoRequestStrategy {

public:
	RecordVideoRequestChangeRecordStatusStrategy(RecordVideoDialog *recordVideoDialog, RecordVideoRequest *request);
	~RecordVideoRequestChangeRecordStatusStrategy();

	virtual bool response();
};

////////////////////////////////////////////////////

class RecordVideoRequestKeyEventStrategy : public RecordVideoRequestStrategy {

public:
	RecordVideoRequestKeyEventStrategy(RecordVideoDialog *recordVideoDialog, RecordVideoRequest *request);
	~RecordVideoRequestKeyEventStrategy();

	virtual bool response();

};

/////////////////////////////////////////////////////

class RecordVideoRequestChangeWritingModeStrategy : public RecordVideoRequestStrategy {

public:
	RecordVideoRequestChangeWritingModeStrategy(RecordVideoDialog *recordVideoDialog, RecordVideoRequest *request);
	~RecordVideoRequestChangeWritingModeStrategy();

	virtual bool response();

};

#endif //_RECORDVIDEOREQUESTSTRATEGY_H
