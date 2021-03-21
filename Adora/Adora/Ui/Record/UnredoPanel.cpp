

#include "UnredoPanel.h"
#include "RecordVideo/Chain/RecordVideoRequest.h"
#include "RecordVideo/NotifyEvent/RecordVideoNotifyEvent.h"

UnredoPanel::UnredoPanel(QWidget *parent)
	:QWidget(parent) {

	ui.setupUi(this);


	connect(ui.undoButton, &QPushButton::clicked, this, &UnredoPanel::undoButtonClicked);
	connect(ui.redoButton, &QPushButton::clicked, this, &UnredoPanel::redoButtonClicked);
}

UnredoPanel::~UnredoPanel() {


}

void UnredoPanel::update(RecordVideoNotifyEvent *event) {

	if (event->getType() == RecordVideoNotifyEvent::EventType::UnredoStackCountChanged) {
	
		int undoCount = dynamic_cast<RecordVideoUnredoStackCountChangedEvent*>(event)->getUndoCount();
		int redoCount = dynamic_cast<RecordVideoUnredoStackCountChangedEvent*>(event)->getRedoCount();

		if (undoCount == 0)
			ui.undoButton->setDisabled(true);
		else
			ui.undoButton->setDisabled(false);

		if (redoCount == 0)
			ui.redoButton->setDisabled(true);
		else
			ui.redoButton->setDisabled(false);
	}
}

void UnredoPanel::undoButtonClicked() {

	RecordVideoRequestUnredo request(RecordVideoRequestUnredo::Type::Undo);
	this->request(&request);
}

void UnredoPanel::redoButtonClicked() {

	RecordVideoRequestUnredo request(RecordVideoRequestUnredo::Type::Redo);
	this->request(&request);
}