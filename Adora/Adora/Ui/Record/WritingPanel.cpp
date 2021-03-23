

#include "WritingPanel.h"
#include "RecordVideo/Chain/RecordVideoRequest.h"
#include "RecordVideo/NotifyEvent/RecordVideoNotifyEvent.h"
#include "Base/SettingManager.h"
#include "Base/LanguageManager.h"

WritingPanel::WritingPanel(QWidget *parent)
	:QWidget(parent) {

	ui.setupUi(this);

	connect(ui.cursorButton, &QPushButton::clicked, this, &WritingPanel::cursorButtonClicked);
	connect(ui.pencilButton, &QPushButton::clicked, this, &WritingPanel::pencilButtonClicked);
	connect(ui.eraserButton, &QPushButton::clicked, this, &WritingPanel::eraserButtonClicked);
	connect(ui.deleteAllButton, &QPushButton::clicked, this, &WritingPanel::deleteAllButtonClicked);
	connect(ui.highlightButton, &QPushButton::clicked, this, &WritingPanel::highlightButtonClicked);
	connect(ui.lineButton, &QPushButton::clicked, this, &WritingPanel::lineButtonClicked);
	connect(ui.arrowLineButton, &QPushButton::clicked, this, &WritingPanel::arrowLineButtonClicked);
	connect(ui.numberingButton, &QPushButton::clicked, this, &WritingPanel::numberingButtonClicked);

	this->items.append(ui.cursorButton);
	this->items.append(ui.pencilButton);
	this->items.append(ui.eraserButton);
	this->items.append(ui.highlightButton);
	this->items.append(ui.lineButton);
	this->items.append(ui.arrowLineButton);
	this->items.append(ui.numberingButton);


	//////////
	QString str = getLanUiValue("WritingPanel/Cursor");
	if (SettingManager::getInstance()->getWritingSetting()->getCursorHotkey().isEmpty() == false &&
		SettingManager::getInstance()->getWritingSetting()->getUseCursorHotkey() == true) {
		str += " " + SettingManager::getInstance()->getWritingSetting()->getCursorHotkey().toString();
	}
	ui.cursorButton->setToolTip(str);

	///////////

	str = getLanUiValue("WritingPanel/Pencil");
	if (SettingManager::getInstance()->getWritingSetting()->getPencilHotkey().isEmpty() == false &&
		SettingManager::getInstance()->getWritingSetting()->getUsePencilHotkey() == true) {
		str += " " + SettingManager::getInstance()->getWritingSetting()->getPencilHotkey().toString();
	}
	ui.pencilButton->setToolTip(str);

	//////////

	str = getLanUiValue("WritingPanel/Highlighter");
	if (SettingManager::getInstance()->getWritingSetting()->getHighlightHotkey().isEmpty() == false &&
		SettingManager::getInstance()->getWritingSetting()->getUseHighlightHotkey() == true) {
		str += " " + SettingManager::getInstance()->getWritingSetting()->getHighlightHotkey().toString();
	}
	ui.highlightButton->setToolTip(str);

	/////////

	str = getLanUiValue("WritingPanel/Line");
	if (SettingManager::getInstance()->getWritingSetting()->getLineHotkey().isEmpty() == false &&
		SettingManager::getInstance()->getWritingSetting()->getUseLineHotkey() == true) {
		str += " " + SettingManager::getInstance()->getWritingSetting()->getLineHotkey().toString();
	}
	ui.lineButton->setToolTip(str);

	//////////

	str = getLanUiValue("WritingPanel/ArrowLine");
	if (SettingManager::getInstance()->getWritingSetting()->getArrowLineHotkey().isEmpty() == false &&
		SettingManager::getInstance()->getWritingSetting()->getUseArrowLineHotkey() == true) {
		str += " " + SettingManager::getInstance()->getWritingSetting()->getArrowLineHotkey().toString();
	}
	ui.arrowLineButton->setToolTip(str);


	///////////

	str = getLanUiValue("WritingPanel/Numbering");
	if (SettingManager::getInstance()->getWritingSetting()->getNumberingHotkey().isEmpty() == false &&
		SettingManager::getInstance()->getWritingSetting()->getUseNumberingHotkey() == true) {
		str += " " + SettingManager::getInstance()->getWritingSetting()->getNumberingHotkey().toString();
	}
	ui.numberingButton->setToolTip(str);

	///////////

	str = getLanUiValue("WritingPanel/Eraser");
	if (SettingManager::getInstance()->getWritingSetting()->getEraserHotkey().isEmpty() == false &&
		SettingManager::getInstance()->getWritingSetting()->getUseEraserHotkey() == true) {
		str += " " + SettingManager::getInstance()->getWritingSetting()->getEraserHotkey().toString();
	}
	ui.eraserButton->setToolTip(str);



}

WritingPanel::~WritingPanel() {


}

void WritingPanel::update(RecordVideoNotifyEvent *event) {

	if (event->getType() == RecordVideoNotifyEvent::EventType::WritingModeChanged) {
	
		for (int i = 0; i < this->items.size(); i++) {
			this->items.at(i)->updateSelected(false);
		}

		WritingStatus status = dynamic_cast<RecordVideoWritingModeChangedEvent*>(event)->getStatus();

		if (status == WritingStatus::Cursor)
			ui.cursorButton->updateSelected(true);
		else if (status == WritingStatus::Pencil)
			ui.pencilButton->updateSelected(true);
		else if (status == WritingStatus::Eraser)
			ui.eraserButton->updateSelected(true);
		else if (status == WritingStatus::Highlight)
			ui.highlightButton->updateSelected(true);
		else if (status == WritingStatus::Line)
			ui.lineButton->updateSelected(true);
		else if (status == WritingStatus::ArrowLine)
			ui.arrowLineButton->updateSelected(true);
		else if (status == WritingStatus::Numbering)
			ui.numberingButton->updateSelected(true);
	}
}

void WritingPanel::cursorButtonClicked() {

	RecordVideoRequestChangeWritingMode request(RecordVideoRequestChangeWritingMode::Mode::Cursor);
	this->request(&request);

}

void WritingPanel::pencilButtonClicked() {

	RecordVideoRequestChangeWritingMode request(RecordVideoRequestChangeWritingMode::Mode::Pencil);
	this->request(&request);
}

void WritingPanel::eraserButtonClicked() {

	RecordVideoRequestChangeWritingMode request(RecordVideoRequestChangeWritingMode::Mode::Eraser);
	this->request(&request);
}

void WritingPanel::deleteAllButtonClicked() {

	RecordVideoRequestWritingDeleteAll request;
	this->request(&request);
}

void WritingPanel::highlightButtonClicked() {

	RecordVideoRequestChangeWritingMode request(RecordVideoRequestChangeWritingMode::Mode::Highlight);
	this->request(&request);
}

void WritingPanel::lineButtonClicked() {

	RecordVideoRequestChangeWritingMode request(RecordVideoRequestChangeWritingMode::Mode::Line);
	this->request(&request);
}

void WritingPanel::arrowLineButtonClicked() {

	RecordVideoRequestChangeWritingMode request(RecordVideoRequestChangeWritingMode::Mode::ArrowLine);
	this->request(&request);
}

void WritingPanel::numberingButtonClicked() {

	RecordVideoRequestChangeWritingMode request(RecordVideoRequestChangeWritingMode::Mode::Numbering);
	this->request(&request);
}