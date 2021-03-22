

#include "WritingPanel.h"
#include "RecordVideo/Chain/RecordVideoRequest.h"
#include "RecordVideo/NotifyEvent/RecordVideoNotifyEvent.h"

WritingPanel::WritingPanel(QWidget *parent)
	:QWidget(parent) {

	ui.setupUi(this);

	connect(ui.cursorButton, &QPushButton::clicked, this, &WritingPanel::cursorButtonClicked);
	connect(ui.pencilButton, &QPushButton::clicked, this, &WritingPanel::pencilButtonClicked);
	connect(ui.eraserButton, &QPushButton::clicked, this, &WritingPanel::eraserButtonClicked);
	connect(ui.deleteAllButton, &QPushButton::clicked, this, &WritingPanel::deleteAllButtonClicked);
	connect(ui.highlightButton, &QPushButton::clicked, this, &WritingPanel::highlightButtonClicked);
	connect(ui.lineButton, &QPushButton::clicked, this, &WritingPanel::lineButtonClicked);

	this->items.append(ui.cursorButton);
	this->items.append(ui.pencilButton);
	this->items.append(ui.eraserButton);
	this->items.append(ui.highlightButton);
	this->items.append(ui.lineButton);
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