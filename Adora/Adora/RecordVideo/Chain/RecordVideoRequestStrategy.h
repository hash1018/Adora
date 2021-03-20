

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

#endif //_RECORDVIDEOREQUESTSTRATEGY_H
