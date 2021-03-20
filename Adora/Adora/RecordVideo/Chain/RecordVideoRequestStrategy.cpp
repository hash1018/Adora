

#include "RecordVideoRequestStrategy.h"
#include "RecordVideoRequest.h"
#include "Ui/Record/RecordVideoDialog.h"
#include "Base/Hotkey.h"
#include <QKeyEvent>

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


//////////////////////////////////////////////////////////////////////


RecordVideoRequestKeyEventStrategy::RecordVideoRequestKeyEventStrategy(RecordVideoDialog *recordVideoDialog, RecordVideoRequest *request)
	:RecordVideoRequestStrategy(recordVideoDialog, request) {

}

RecordVideoRequestKeyEventStrategy::~RecordVideoRequestKeyEventStrategy() {

}


bool RecordVideoRequestKeyEventStrategy::response() {

	QKeyEvent *event = dynamic_cast<RecordVideoRequestKeyEvent*>(this->request)->getKeyEvent();

	QKeySequence keySequence(QKeySequence(event->modifiers() + event->key()));

	int index = HotkeyList::getInstance()->indexOf(keySequence);
	if (index != -1) {

		HotkeyType type = HotkeyList::getInstance()->at(index)->getType();

		if (type == HotkeyType::ImageCapture) {
			this->recordVideoDialog->capture();
		}
		else if (type == HotkeyType::VideoStartAndStop) {

			if (this->recordVideoDialog->getRecordStatus() == RecordStatus::NotRecording) {
				this->recordVideoDialog->record();
			}
			else if (this->recordVideoDialog->getRecordStatus() == RecordStatus::Recording) {
				this->recordVideoDialog->stop();
			}
			else if (this->recordVideoDialog->getRecordStatus() == RecordStatus::Paused) {
				this->recordVideoDialog->stop();
			}
		}
		else if (type == HotkeyType::VideoPauseAndResume) {

			if (this->recordVideoDialog->getRecordStatus() == RecordStatus::Recording) {
				this->recordVideoDialog->pause();
			}
			else if (this->recordVideoDialog->getRecordStatus() == RecordStatus::Paused) {
				this->recordVideoDialog->resume();
			}
		}
	}


	return true;
}