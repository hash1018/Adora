

#include "RecordPanel.h"
#include "RecordVideo/Chain/RecordVideoRequest.h"
#include "RecordVideo/NotifyEvent/RecordVideoNotifyEvent.h"

RecordPanel::RecordPanel(QWidget *parent)
	:QWidget(parent) {

	ui.setupUi(this);

	this->items.append(ui.timeLabel);
	this->items.append(ui.resumeButton);
	this->items.append(ui.pauseButton);
	this->items.append(ui.stopButton);
	this->items.append(ui.recordButton);
	this->items.append(ui.quitButton);
	

	
	

	


	

	connect(ui.recordButton, &QPushButton::clicked, this, &RecordPanel::recordButtonClicked);
	connect(ui.quitButton, &QPushButton::clicked, this, &RecordPanel::quitButtonClicked);
	connect(ui.captureButton, &QPushButton::clicked, this, &RecordPanel::captureButtonClicked);
	connect(ui.pauseButton, &QPushButton::clicked, this, &RecordPanel::pauseButtonClicked);
	connect(ui.resumeButton, &QPushButton::clicked, this, &RecordPanel::resumeButtonClicked);
	connect(ui.stopButton, &QPushButton::clicked, this, &RecordPanel::stopButtonClicked);
	
}

RecordPanel::~RecordPanel() {

}

void RecordPanel::update(RecordVideoNotifyEvent *event) {

	if (event->getType() == RecordVideoNotifyEvent::EventType::RecordStatusChanged) {
	
		RecordVideoStatusChangedEvent *event2 = dynamic_cast<RecordVideoStatusChangedEvent*>(event);

		for (int i = 0; i < this->items.size(); i++)
			this->items.at(i)->show();

		if (event2->getStatus() == RecordStatus::NotRecording) {
		
			// ³ìÈ­Àü
			ui.timeLabel->hide();
			ui.resumeButton->hide();
			ui.pauseButton->hide();
			ui.stopButton->hide();
		}
		else if (event2->getStatus() == RecordStatus::Paused) {

			//ÀÏ½ÃÁ¤Áö
			ui.recordButton->hide();
			ui.quitButton->hide();
			ui.pauseButton->hide();
			
			
		}
		else if (event2->getStatus() == RecordStatus::Recording) {
			// ³ìÈ­Áß
			ui.recordButton->hide();
			ui.quitButton->hide();
			ui.resumeButton->hide();
		}
	}


}


void RecordPanel::recordButtonClicked() {

	RecordVideoRequestChangeRecordStatus request(RecordVideoRequestChangeRecordStatus::RecordStatus::Record);
	this->request(&request);
}

void RecordPanel::quitButtonClicked() {

	RecordVideoRequestChangeRecordStatus request(RecordVideoRequestChangeRecordStatus::RecordStatus::Quit);
	this->request(&request);
}

void RecordPanel::captureButtonClicked() {

	RecordVideoRequestChangeRecordStatus request(RecordVideoRequestChangeRecordStatus::RecordStatus::Capture);
	this->request(&request);
}

void RecordPanel::resumeButtonClicked() {

	RecordVideoRequestChangeRecordStatus request(RecordVideoRequestChangeRecordStatus::RecordStatus::Resume);
	this->request(&request);
}

void RecordPanel::pauseButtonClicked() {

	RecordVideoRequestChangeRecordStatus request(RecordVideoRequestChangeRecordStatus::RecordStatus::Pause);
	this->request(&request);
}

void RecordPanel::stopButtonClicked() {

	RecordVideoRequestChangeRecordStatus request(RecordVideoRequestChangeRecordStatus::RecordStatus::Stop);
	this->request(&request);
}