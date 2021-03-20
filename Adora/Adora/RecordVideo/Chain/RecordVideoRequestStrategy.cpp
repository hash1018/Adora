

#include "RecordVideoRequestStrategy.h"
#include "RecordVideoRequest.h"
#include "Ui/Record/RecordVideoDialog.h"

RecordVideoRequestStrategy::RecordVideoRequestStrategy(RecordVideoDialog *recordVideoDialog, RecordVideoRequest *request)
	:recordVideoDialog(recordVideoDialog), request(request) {

}

RecordVideoRequestStrategy::~RecordVideoRequestStrategy() {


}


////////////////////////////////////////////////////////


RecordVideoRequestChangeRecordStatusStrategy::RecordVideoRequestChangeRecordStatusStrategy(RecordVideoDialog *recordVideoDialog,
	RecordVideoRequest *request)
	:RecordVideoRequestStrategy(recordVideoDialog, request) {

}

RecordVideoRequestChangeRecordStatusStrategy::~RecordVideoRequestChangeRecordStatusStrategy() {


}

bool RecordVideoRequestChangeRecordStatusStrategy::response() {

	RecordVideoRequestChangeRecordStatus *request = dynamic_cast<RecordVideoRequestChangeRecordStatus*>(this->request);

	if (request->getRecordStatus() == RecordVideoRequestChangeRecordStatus::Record) {
	
		this->recordVideoDialog->record();
	}

	else if (request->getRecordStatus() == RecordVideoRequestChangeRecordStatus::Pause) {

		this->recordVideoDialog->pause();
	}

	else if (request->getRecordStatus() == RecordVideoRequestChangeRecordStatus::Quit) {

		this->recordVideoDialog->quit();
	}


	else if (request->getRecordStatus() == RecordVideoRequestChangeRecordStatus::Resume) {

		this->recordVideoDialog->resume();
	}

	else if (request->getRecordStatus() == RecordVideoRequestChangeRecordStatus::Capture) {

		this->recordVideoDialog->capture();
	}
	else if (request->getRecordStatus() == RecordVideoRequestChangeRecordStatus::Stop) {
		
		this->recordVideoDialog->stop();
	}

	return true;
}