

#include "RecordPanel.h"
#include "RecordVideo/Chain/RecordVideoRequest.h"
#include "RecordVideo/NotifyEvent/RecordVideoNotifyEvent.h"
#include "Base/LanguageManager.h"
#include "Base/SettingManager.h"

RecordPanel::RecordPanel(QWidget *parent)
	:QWidget(parent) {

	ui.setupUi(this);

	this->items.append(ui.timeLabel);
	this->items.append(ui.resumeButton);
	this->items.append(ui.pauseButton);
	this->items.append(ui.stopButton);
	this->items.append(ui.recordButton);
	this->items.append(ui.quitButton);
	


	QString str = getLanUiValue("RecordPanel/Record Video");
	if (SettingManager::getInstance()->getVideoSetting()->getStartStopHotkey().isEmpty() == false &&
		SettingManager::getInstance()->getVideoSetting()->getUseStartAndStopHotkey()==true) {
		str += " " + SettingManager::getInstance()->getVideoSetting()->getStartStopHotkey().toString();
	}
	ui.recordButton->setToolTip(str);


	str = getLanUiValue("RecordPanel/Resume Video");
	if (SettingManager::getInstance()->getVideoSetting()->getPauseResumeHotkey().isEmpty() == false &&
		SettingManager::getInstance()->getVideoSetting()->getUsePauseAndResumeHotkey() == true) {
		str += " " + SettingManager::getInstance()->getVideoSetting()->getPauseResumeHotkey().toString();
	}
	ui.resumeButton->setToolTip(str);

	str = getLanUiValue("RecordPanel/Pause Video");
	if (SettingManager::getInstance()->getVideoSetting()->getPauseResumeHotkey().isEmpty() == false &&
		SettingManager::getInstance()->getVideoSetting()->getUsePauseAndResumeHotkey() == true) {
		str += " " + SettingManager::getInstance()->getVideoSetting()->getPauseResumeHotkey().toString();
	}
	ui.pauseButton->setToolTip(str);

	str = getLanUiValue("RecordPanel/Stop Video");
	if (SettingManager::getInstance()->getVideoSetting()->getStartStopHotkey().isEmpty() == false &&
		SettingManager::getInstance()->getVideoSetting()->getUseStartAndStopHotkey() == true) {
		str += " " + SettingManager::getInstance()->getVideoSetting()->getStartStopHotkey().toString();
	}
	ui.stopButton->setToolTip(str);


	str = getLanUiValue("RecordPanel/Capture Screen");
	if (SettingManager::getInstance()->getImageSetting()->getImageCaptureHotkey().isEmpty() == false &&
		SettingManager::getInstance()->getImageSetting()->getUseImageCaptureHotkey()==true) {
		str += " " + SettingManager::getInstance()->getImageSetting()->getImageCaptureHotkey().toString();
	}
	ui.captureButton->setToolTip(str);

	ui.quitButton->setToolTip(getLanUiValue("RecordPanel/Quit"));
	
	connect(ui.recordButton, &QPushButton::clicked, this, &RecordPanel::recordButtonClicked);
	connect(ui.quitButton, &QPushButton::clicked, this, &RecordPanel::quitButtonClicked);
	connect(ui.captureButton, &QPushButton::clicked, this, &RecordPanel::captureButtonClicked);
	connect(ui.pauseButton, &QPushButton::clicked, this, &RecordPanel::pauseButtonClicked);
	connect(ui.resumeButton, &QPushButton::clicked, this, &RecordPanel::resumeButtonClicked);
	connect(ui.stopButton, &QPushButton::clicked, this, &RecordPanel::stopButtonClicked);

	ui.timeLabel->setText("00:00");
	
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
	else if (event->getType() == RecordVideoNotifyEvent::EventType::RecordTimePassed) {
	
		RecordTimePassedEvent *event2 = dynamic_cast<RecordTimePassedEvent*>(event);

		Time time = event2->getTime();

		QString timeText;
		int hours = time.getHours();
		int minutes = time.getMinutes();
		int seconds = time.getSeconds();

		if (hours >= 1)
			timeText = QString::number(hours) + ":";


		if (minutes >= 10) {

			timeText += QString::number(minutes) + ":";
		}
		else {
			timeText += "0" + QString::number(minutes) + ":";
		}

		if (seconds >= 10) {

			timeText += QString::number(seconds);
		}
		else {
			timeText += "0" + QString::number(seconds);
		}

		ui.timeLabel->setText(timeText);
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