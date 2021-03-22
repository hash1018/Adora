

#include "RecordVideoRequestStrategy.h"
#include "RecordVideoRequest.h"
#include "Ui/Record/RecordVideoDialog.h"
#include "Base/Hotkey.h"
#include <QKeyEvent>
#include "Base/SettingManager.h"
#include "RecordVideo/Unredo/RemoveEntityCommand.h"

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
			if (SettingManager::getInstance()->getImageSetting()->getUseImageCaptureHotkey() == true)
				this->recordVideoDialog->capture();
		}
		else if (type == HotkeyType::VideoStartAndStop) {

			if (this->recordVideoDialog->getRecordStatus() == RecordStatus::NotRecording) {
				if (SettingManager::getInstance()->getVideoSetting()->getUseStartAndStopHotkey() == true)
					this->recordVideoDialog->record();
			}
			else if (this->recordVideoDialog->getRecordStatus() == RecordStatus::Recording) {
				if (SettingManager::getInstance()->getVideoSetting()->getUseStartAndStopHotkey() == true)
					this->recordVideoDialog->stop();
			}
			else if (this->recordVideoDialog->getRecordStatus() == RecordStatus::Paused) {
				if (SettingManager::getInstance()->getVideoSetting()->getUseStartAndStopHotkey() == true)
					this->recordVideoDialog->stop();
			}
		}
		else if (type == HotkeyType::VideoPauseAndResume) {

			if (this->recordVideoDialog->getRecordStatus() == RecordStatus::Recording) {
				if (SettingManager::getInstance()->getVideoSetting()->getUsePauseAndResumeHotkey() == true)
					this->recordVideoDialog->pause();
			}
			else if (this->recordVideoDialog->getRecordStatus() == RecordStatus::Paused) {
				if (SettingManager::getInstance()->getVideoSetting()->getUsePauseAndResumeHotkey() == true)
					this->recordVideoDialog->resume();
			}
		}
		else if (type == HotkeyType::Undo) {
			this->recordVideoDialog->undo();
		}
		else if (type == HotkeyType::Redo) {
			this->recordVideoDialog->redo();
		}
	}


	return true;
}



//////////////////////////////////////////////////////////////////////////////


RecordVideoRequestChangeWritingModeStrategy::RecordVideoRequestChangeWritingModeStrategy(RecordVideoDialog *recordVideoDialog,
	RecordVideoRequest *request)
	:RecordVideoRequestStrategy(recordVideoDialog, request) {

}

RecordVideoRequestChangeWritingModeStrategy::~RecordVideoRequestChangeWritingModeStrategy() {


}

bool RecordVideoRequestChangeWritingModeStrategy::response() {

	RecordVideoRequestChangeWritingMode::Mode mode = dynamic_cast<RecordVideoRequestChangeWritingMode*>(this->request)->getMode();

	if (mode == RecordVideoRequestChangeWritingMode::Mode::Cursor) {
	
		this->recordVideoDialog->changeWritingMode(WritingStatus::Cursor);
	}
	else if (mode == RecordVideoRequestChangeWritingMode::Mode::Pencil) {
	
		this->recordVideoDialog->changeWritingMode(WritingStatus::Pencil);
	}
	else if (mode == RecordVideoRequestChangeWritingMode::Mode::Eraser) {
	
		this->recordVideoDialog->changeWritingMode(WritingStatus::Eraser);
	}
	else if (mode == RecordVideoRequestChangeWritingMode::Mode::Highlight) {
	
		this->recordVideoDialog->changeWritingMode(WritingStatus::Highlight);
	}
	else if (mode == RecordVideoRequestChangeWritingMode::Mode::Line) {
	
		this->recordVideoDialog->changeWritingMode(WritingStatus::Line);
	}
	else if (mode == RecordVideoRequestChangeWritingMode::Mode::ArrowLine) {
	
		this->recordVideoDialog->changeWritingMode(WritingStatus::ArrowLine);
	}
	else if (mode == RecordVideoRequestChangeWritingMode::Mode::Numbering) {
	
		this->recordVideoDialog->changeWritingMode(WritingStatus::Numbering);
	}


	return true;
}



///////////////////////////////////////////////////////////////////


RecordVideoRequestUnredoStrategy::RecordVideoRequestUnredoStrategy(RecordVideoDialog *recordVideoDialog, RecordVideoRequest *request)
	:RecordVideoRequestStrategy(recordVideoDialog, request) {

}

RecordVideoRequestUnredoStrategy::~RecordVideoRequestUnredoStrategy() {

}

bool RecordVideoRequestUnredoStrategy::response() {

	RecordVideoRequestUnredo::Type type = dynamic_cast<RecordVideoRequestUnredo*>(this->request)->getType();

	if (type == RecordVideoRequestUnredo::Type::Undo)
		this->recordVideoDialog->undo();
	else if (type == RecordVideoRequestUnredo::Type::Redo)
		this->recordVideoDialog->redo();

	return true;
}


////////////////////////////////////////////////////////////////////////


RecordVideoRequestWritingDeleteAllStrategy::RecordVideoRequestWritingDeleteAllStrategy(RecordVideoDialog *recordVideoDialog,
	RecordVideoRequest *request)
	:RecordVideoRequestStrategy(recordVideoDialog, request) {

}

RecordVideoRequestWritingDeleteAllStrategy::~RecordVideoRequestWritingDeleteAllStrategy() {

}


bool RecordVideoRequestWritingDeleteAllStrategy::response() {

	QLinkedList<Entity*> list;

	auto itr = this->recordVideoDialog->getEntityList()->begin();

	for (itr; itr != this->recordVideoDialog->getEntityList()->end(); ++itr) {

		list.append((*itr));
	}

	if (list.size() > 0) {
	
		this->recordVideoDialog->addCommand(new RemoveEntityCommand(this->recordVideoDialog, list));
		this->recordVideoDialog->getEntityList()->clear();
		this->recordVideoDialog->update();
	}

	return true;
}