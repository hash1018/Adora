
#include "RecordVideoRequestStrategyFactory.h"
#include "RecordVideo/Chain/RecordVideoRequest.h"
#include "RecordVideo/Chain/RecordVideoRequestStrategy.h"

RecordVideoRequestStrategyFactory::RecordVideoRequestStrategyFactory() {

}

RecordVideoRequestStrategyFactory::~RecordVideoRequestStrategyFactory() {


}

RecordVideoRequestStrategy* RecordVideoRequestStrategyFactory::create(RecordVideoDialog *recordVideoDialog, 
	RecordVideoRequest *request) {

	RecordVideoRequestStrategy *strategy = nullptr;

	if (request->getType() == RecordVideoRequest::RequestChangeRecordStatus)
		strategy = new RecordVideoRequestChangeRecordStatusStrategy(recordVideoDialog, request);

	else if (request->getType() == RecordVideoRequest::RequestKeyEvent)
		strategy = new RecordVideoRequestKeyEventStrategy(recordVideoDialog, request);

	else if (request->getType() == RecordVideoRequest::RequestChangeWritingMode)
		strategy = new RecordVideoRequestChangeWritingModeStrategy(recordVideoDialog, request);
	

	return strategy;
}