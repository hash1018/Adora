

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


///////////////////////////////////////////////////////

class RecordVideoRequestUnredoStrategy : public RecordVideoRequestStrategy {

public:
	RecordVideoRequestUnredoStrategy(RecordVideoDialog *recordVideoDialog, RecordVideoRequest *request);
	~RecordVideoRequestUnredoStrategy();

	virtual bool response();

};

///////////////////////////////////////////////////////

class RecordVideoRequestWritingDeleteAllStrategy : public RecordVideoRequestStrategy {

public:
	RecordVideoRequestWritingDeleteAllStrategy(RecordVideoDialog *recordVideoDialog, RecordVideoRequest *request);
	~RecordVideoRequestWritingDeleteAllStrategy();

	virtual bool response();
};

////////////////////////////////////////////////////////

class RecordVideoRequestChangeWritingDataStrategy : public RecordVideoRequestStrategy {


public:
	RecordVideoRequestChangeWritingDataStrategy(RecordVideoDialog *recordVideoDialog, RecordVideoRequest *request);
	~RecordVideoRequestChangeWritingDataStrategy();

	virtual bool response();

};

/////////////////////////////////////////////////////////

class RecordVideoRequestMuteAudioStrategy : public RecordVideoRequestStrategy {

public:
	RecordVideoRequestMuteAudioStrategy(RecordVideoDialog *recordVideoDialog, RecordVideoRequest *request);
	~RecordVideoRequestMuteAudioStrategy();

	virtual bool response();

};

#endif //_RECORDVIDEOREQUESTSTRATEGY_H
