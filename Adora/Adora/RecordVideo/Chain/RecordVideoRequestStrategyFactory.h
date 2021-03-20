

#ifndef _RECORDVIDEOREQUESTSTRATEGYFACTORY_H
#define _RECORDVIDEOREQUESTSTRATEGYFACTORY_H

class RecordVideoDialog;
class RecordVideoRequest;
class RecordVideoRequestStrategy;

class RecordVideoRequestStrategyFactory {

public:
	RecordVideoRequestStrategyFactory();
	~RecordVideoRequestStrategyFactory();

	static RecordVideoRequestStrategy* create(RecordVideoDialog *recordVideoDialog, RecordVideoRequest *request);

};

#endif //_RECORDVIDEOREQUESTSTRATEGYFACTORY_H
