
#include "RecordVideoDialog.h"
#include <qpainter.h>
#include <QResizeEvent>
#include "ControllerWidget.h"
#include "RecordVideo/Chain/RecordVideoRequestStrategyFactory.h"
#include "RecordVideo/Chain/RecordVideoRequestStrategy.h"
#include "RecordVideo/Mode/RecordStatusMode/RecordStatusMode.h"
#include "RecordVideo/Mode/RecordStatusMode/RecordStatusModeFactory.h"
#include "RecordVideo/NotifyEvent/RecordVideoNotifyEvent.h"
#include "RecordVideo/ResizeRecordRectDelegate.h"
#include "RecordVideo/CaptureImageDelegate.h"
#include "RecordVideo/Chain/RecordVideoRequest.h"
#include <qsettings.h>
#include <qscreen.h>

#include "RecordVideo/Mode/WritingMode/WritingModeFactory.h"
#include "RecordVideo/Mode/WritingMode/WritingMode.h"

#include "RecordVideo/Entity/Visitor/Drawer.h"

#include "lib/ffmpeg/VideoRecorder.h"
#include "Base/Time.h"
#include "Base/SettingManager.h"
#include "Base/DefaultNameByDateCreator.h"

#include "Base/LanguageManager.h"

RecordVideoDialog::RecordVideoDialog(QWidget *parent)
	:QDialog(parent, Qt::FramelessWindowHint), recordStatusMode(nullptr), writingMode(nullptr), videoRecorder(nullptr) {

	this->setMinimumSize(600, 400);

	this->setMouseTracking(true);
	this->setAttribute(Qt::WA_TranslucentBackground);
	this->setWindowFlag(Qt::WindowStaysOnTopHint);

	this->loadGeometry();

	this->controllerWidget = new ControllerWidget(this);
	this->controllerWidget->show();
	this->controllerWidget->loadGeometry();

	this->writingData.load();

	this->changeRecordStatusMode(RecordStatus::NotRecording);
	this->changeWritingMode(WritingStatus::Cursor);

	this->resizeRecordRectDelegate = new ResizeRecordRectDelegate(this);
	this->captureImageDelegate = new CaptureImageDelegate(this);


	RecordVideoUnredoStackCountChangedEvent event(this->unredoStack.getUndoStackSize(),
		this->unredoStack.getRedoStackSize());
	this->controllerWidget->update(&event);
}

RecordVideoDialog::~RecordVideoDialog() {

	if (this->controllerWidget != nullptr)
		delete this->controllerWidget;

	if (this->recordStatusMode != nullptr)
		delete this->recordStatusMode;

	if (this->writingMode != nullptr)
		delete this->writingMode;

	if (this->resizeRecordRectDelegate != nullptr)
		delete this->resizeRecordRectDelegate;

	if (this->captureImageDelegate != nullptr)
		delete this->captureImageDelegate;
}

void RecordVideoDialog::hide() {

	this->saveGeometry();
	this->controllerWidget->saveGeometry();

	this->writingData.save();

	QDialog::hide();
}

void RecordVideoDialog::addCommand(WritingCommand *command) {

	this->unredoStack.pushToUndoStack(command);
	
	RecordVideoUnredoStackCountChangedEvent event(this->unredoStack.getUndoStackSize(),
		this->unredoStack.getRedoStackSize());
	this->controllerWidget->update(&event);
}

void RecordVideoDialog::changeRecordStatusMode(RecordStatus recordStatus) {

	if (this->recordStatusMode != nullptr)
		delete this->recordStatusMode;

	this->recordStatusMode = RecordStatusModeFactory::create(this, recordStatus);

	RecordVideoStatusChangedEvent event(recordStatus);
	this->controllerWidget->update(&event);

	this->update();
}

void RecordVideoDialog::changeWritingMode(WritingStatus writingStatus) {

	if (this->writingMode != nullptr) {

		if (writingStatus == this->writingMode->getStatus())
			return;

		delete this->writingMode;
	}

	this->writingMode = WritingModeFactory::create(this, writingStatus);

	this->setCursor(this->writingMode->getCursor());

	RecordVideoWritingModeChangedEvent event(writingStatus,
		this->writingData.getColor(writingStatus), this->writingData.getWidth(writingStatus));
	this->controllerWidget->update(&event);

	this->update();
}


void RecordVideoDialog::request(RecordVideoRequest *request) {

	RecordVideoRequestStrategy *strategy = RecordVideoRequestStrategyFactory::create(this, request);
	
	if (strategy != nullptr) {
		strategy->response();
		delete strategy;
	}
}
#include <qdebug.h>
void RecordVideoDialog::record() {

	if (this->videoRecorder != nullptr)
		delete this->videoRecorder;

	this->videoRecorder = new VideoRecorder;
	connect(this->videoRecorder, SIGNAL(timePassed(Time&)), this, SLOT(timePassed(Time&)));
	connect(this->videoRecorder, &VideoRecorder::started, this, &RecordVideoDialog::started);
	connect(this->videoRecorder, &VideoRecorder::stopped, this, &RecordVideoDialog::stopped);
	connect(this->videoRecorder, &VideoRecorder::paused, this, &RecordVideoDialog::paused);
	connect(this->videoRecorder, &VideoRecorder::resumed, this, &RecordVideoDialog::resumed);

	VideoCodecInfo videoCodecInfo;
	videoCodecInfo.bitrate = SettingManager::getInstance()->getVideoSetting()->getVideoBitrate();
	videoCodecInfo.fps = SettingManager::getInstance()->getVideoSetting()->getFps();
	if (SettingManager::getInstance()->getVideoSetting()->getUseHwEncoder() == true) {

		auto str = SettingManager::getInstance()->getVideoSetting()->getHwEncoder();

		if (str != "") {
			videoCodecInfo.useHwAccels = true;
			videoCodecInfo.hwAccelsName = str;
		}
	}

	QRect rect = this->getRecordAreaRect();
	
	if (rect.width() % 2 != 0)
		rect.setWidth(rect.width() - 1);
	
	if (rect.height() % 2 != 0)
		rect.setHeight(rect.height() - 1);

	videoCodecInfo.width = rect.width();
	videoCodecInfo.height = rect.height();

	VideoParameter videoParameter;
	videoParameter.drawCursor = SettingManager::getInstance()->getVideoSetting()->getIncludeCursor();
	QPoint point = this->mapToGlobal(rect.topLeft());
	videoParameter.x = point.x();
	videoParameter.y = point.y();
	videoParameter.width = rect.width();
	videoParameter.height = rect.height();

	this->videoRecorder->setVideoCodecInfo(videoCodecInfo);
	this->videoRecorder->setVideoParameter(videoParameter);

	
	this->videoRecorder->setFilePath(SettingManager::getInstance()->getGeneralSetting()->getSavePath() +
		"/" + DefaultNameByDateCreator::create() + ".mp4");

	QList<AudioParameter> list;
	if (SettingManager::getInstance()->getAudioSetting()->getSpeakerDevice() != 
		getLanUiValue("MenuAudio/Not used")) {
	
		AudioParameter param;
		param.muted = SettingManager::getInstance()->getAudioSetting()->getSpeakerMuted();
		param.deviceName = SettingManager::getInstance()->getAudioSetting()->getSpeakerDevice();
		param.type = eRender;
		list.append(param);
	}

	if (SettingManager::getInstance()->getAudioSetting()->getMicDevice() !=
		getLanUiValue("MenuAudio/Not used")) {

		AudioParameter param;
		param.muted = SettingManager::getInstance()->getAudioSetting()->getMicMuted();
		param.deviceName = SettingManager::getInstance()->getAudioSetting()->getMicDevice();
		param.type = eCapture;
		list.append(param);
	}
	
	this->videoRecorder->setAudioParameter(list);

	this->videoRecorder->start();
}

void RecordVideoDialog::quit() {

	RecordVideoDialogAboutToFinishEvent event;
	this->controllerWidget->update(&event);

	emit this->recordVideoDialogClosed();
}

void RecordVideoDialog::pause() {

	this->videoRecorder->pause();
}

void RecordVideoDialog::stop() {

	this->videoRecorder->stop();
	
}

void RecordVideoDialog::resume() {

	this->videoRecorder->resume();
}

void RecordVideoDialog::capture() {

	QRect rect = this->recordAreaRect;
	QPoint point = this->mapToGlobal(rect.topLeft());
	this->captureImageDelegate->capture(point.x(), point.y(), rect.width(), rect.height());
}

void RecordVideoDialog::undo() {

	this->unredoStack.undo();

	RecordVideoUnredoStackCountChangedEvent event(this->unredoStack.getUndoStackSize(),
		this->unredoStack.getRedoStackSize());
	this->controllerWidget->update(&event);
}

void RecordVideoDialog::redo() {


	this->unredoStack.redo();

	RecordVideoUnredoStackCountChangedEvent event(this->unredoStack.getUndoStackSize(),
		this->unredoStack.getRedoStackSize());
	this->controllerWidget->update(&event);
}

void RecordVideoDialog::muteAudio(const QString &deviceName, bool muted) {

	if (SettingManager::getInstance()->getAudioSetting()->getSpeakerDevice() == deviceName)
		SettingManager::getInstance()->getAudioSetting()->setSpeakerMuted(muted);

	else if (SettingManager::getInstance()->getAudioSetting()->getMicDevice() == deviceName)
		SettingManager::getInstance()->getAudioSetting()->setMicMuted(muted);


	if (this->recordStatusMode->getStatus() != RecordStatus::NotRecording) {
		this->videoRecorder->setAudioMuted(deviceName, muted);
	}
	
	AudioMutedChangedEvent event(deviceName, muted);
	this->controllerWidget->update(&event);
}

void RecordVideoDialog::started() {

	this->changeRecordStatusMode(RecordStatus::Recording);
}

void RecordVideoDialog::paused() {

	this->changeRecordStatusMode(RecordStatus::Paused);
}

void RecordVideoDialog::stopped() {

	delete this->videoRecorder;
	this->videoRecorder = nullptr;

	this->quit();
}

void RecordVideoDialog::resumed() {

	this->changeRecordStatusMode(RecordStatus::Recording);
}


void RecordVideoDialog::timePassed(Time &time) {

	if (SettingManager::getInstance()->getTimeLimitSetting()->getUseTimeLimit() == true) {

		int hour = SettingManager::getInstance()->getTimeLimitSetting()->getHour();
		int minute = SettingManager::getInstance()->getTimeLimitSetting()->getMinute();
		int second = SettingManager::getInstance()->getTimeLimitSetting()->getSecond();
		uint64_t millisecond = 0;

		minute += hour * 60;
		second += minute * 60;
		millisecond += (second * 1000);

		Time temp = Time::convertTime(millisecond);
		if (time >= temp) {
		
			disconnect(this->videoRecorder, SIGNAL(timePassed(Time&)), this, SLOT(timePassed(Time&)));

			RecordTimePassedEvent event(time);
			this->controllerWidget->update(&event);

			this->stop();
			return;
		}
	}
	
	RecordTimePassedEvent event(time);
	this->controllerWidget->update(&event);
}

void RecordVideoDialog::keyPressEvent(QKeyEvent *event) {

	RecordVideoRequestKeyEvent request(event);
	this->request(&request);
}

void RecordVideoDialog::paintEvent(QPaintEvent *event) {

	QPainter painter(this);

	QPen pen(QColor("#FFB513"));
	pen.setWidth(4);

	QPen oldPen = painter.pen();
	painter.setPen(pen);

	QRect rect = this->getRecordBorderRect();

	QPoint start, end;

	start = QPoint(rect.topLeft());
	end = QPoint(rect.topRight());
	painter.drawLine(start, end);

	start = end;
	end = QPoint(rect.bottomRight());
	painter.drawLine(start, end);

	start = end;
	end = QPoint(rect.bottomLeft());
	painter.drawLine(start, end);

	start = end;
	end = QPoint(rect.topLeft());
	painter.drawLine(start, end);

	painter.setPen(oldPen);



	Drawer drawer(painter);
	auto itr = this->entityList.begin();
	for (itr; itr != this->entityList.end(); ++itr)
		(*itr)->accept(&drawer);
	





	this->captureImageDelegate->paintEvent(painter);

	if (this->captureImageDelegate->isShowFlash() == false &&
		this->writingMode->getStatus() == WritingStatus::Cursor)
		this->recordStatusMode->paintEvent(painter);

	this->resizeRecordRectDelegate->paintEvent(painter);
}


void RecordVideoDialog::resizeEvent(QResizeEvent *event) {

	QDialog::resizeEvent(event);

	this->recordAreaRect.setRect(4, 4, event->size().width() - 8, event->size().height() - 8);

	if (this->recordStatusMode->getStatus() == RecordStatus::Paused) {

		QRect rect = this->getRecordAreaRect();

		if (rect.width() % 2 != 0)
			rect.setWidth(rect.width() - 1);

		if (rect.height() % 2 != 0)
			rect.setHeight(rect.height() - 1);

		VideoParameter videoParameter;
		videoParameter.drawCursor = SettingManager::getInstance()->getVideoSetting()->getIncludeCursor();
		QPoint point = this->mapToGlobal(rect.topLeft());
		videoParameter.x = point.x();
		videoParameter.y = point.y();
		videoParameter.width = rect.width();
		videoParameter.height = rect.height();

		this->videoRecorder->changeVideoParameter(videoParameter);

	}
}

void RecordVideoDialog::moveEvent(QMoveEvent *event) {

	if (this->recordStatusMode->getStatus() == RecordStatus::Paused) {

		QRect rect = this->getRecordAreaRect();

		if (rect.width() % 2 != 0)
			rect.setWidth(rect.width() - 1);

		if (rect.height() % 2 != 0)
			rect.setHeight(rect.height() - 1);

		VideoParameter videoParameter;
		videoParameter.drawCursor = SettingManager::getInstance()->getVideoSetting()->getIncludeCursor();
		QPoint point = this->mapToGlobal(rect.topLeft());
		videoParameter.x = point.x();
		videoParameter.y = point.y();
		videoParameter.width = rect.width();
		videoParameter.height = rect.height();

		this->videoRecorder->changeVideoParameter(videoParameter);

	}
}

void RecordVideoDialog::mouseMoveEvent(QMouseEvent *event) {

	if (this->recordStatusMode->getStatus() == RecordStatus::NotRecording ||
		this->recordStatusMode->getStatus() == RecordStatus::Paused) {
	
		if (this->writingMode->getStatus() == WritingStatus::Cursor)
			this->resizeRecordRectDelegate->mouseMoveEvent(event);
	}

	this->writingMode->mouseMoveEvent(event);
}

void RecordVideoDialog::mousePressEvent(QMouseEvent *event) {

	if (this->recordStatusMode->getStatus() == RecordStatus::NotRecording ||
		this->recordStatusMode->getStatus() == RecordStatus::Paused) {

		if (this->writingMode->getStatus() == WritingStatus::Cursor)
			this->resizeRecordRectDelegate->mousePressEvent(event);
	}

	this->writingMode->mousePressEvent(event);
}

void RecordVideoDialog::mouseReleaseEvent(QMouseEvent *event) {

	if (this->recordStatusMode->getStatus() == RecordStatus::NotRecording ||
		this->recordStatusMode->getStatus() == RecordStatus::Paused) {

		if (this->writingMode->getStatus() == WritingStatus::Cursor)
			this->resizeRecordRectDelegate->mouseReleaseEvent(event);
	}

	this->writingMode->mouseReleaseEvent(event);

	this->controllerWidget->activateWindow();
}

void RecordVideoDialog::closeEvent(QCloseEvent *event) {

	event->ignore();
}

QRect RecordVideoDialog::getRecordBorderRect() {

	return QRect(this->recordAreaRect.x() - 2, this->recordAreaRect.y() - 2,
		this->recordAreaRect.width() + 5, this->recordAreaRect.height() + 5);
}


RecordStatus RecordVideoDialog::getRecordStatus() {

	return this->recordStatusMode->getStatus();
}

WritingStatus RecordVideoDialog::getCurrentWritingMode() {

	return this->writingMode->getStatus();
}

void RecordVideoDialog::setColor(WritingStatus status, const QColor &color) {

	this->writingData.setColor(status, color);

	RecordVideoWritingDataChangedEvent event(color);
	this->controllerWidget->update(&event);
}

void RecordVideoDialog::setWidth(WritingStatus status, int width) {

	this->writingData.setWidth(status, width);

	RecordVideoWritingDataChangedEvent event(width);
	this->controllerWidget->update(&event);
}

void RecordVideoDialog::loadGeometry() {

	QSettings settings("Adora", "Adora");
	settings.beginGroup("RecordVideo");

	bool existGeometrySetting = settings.contains("recordVideoDialogGeomeotry");
	bool isValidGeometrySetting = false;

	if (existGeometrySetting == true) {

		QRect rect = settings.value("recordVideoDialogGeomeotry").toRect();

		this->setGeometry(settings.value("recordVideoDialogGeomeotry").toRect());

		QList<QScreen*> screens = QGuiApplication::screens();
		QRect screenRect;

		for (int i = 0; i < screens.size(); i++) {

			screenRect = screenRect.united(screens.at(i)->geometry());
		}

		rect = QRect(rect.topLeft().x() + 4,
			rect.topLeft().y() + 4,
			rect.width() - 8,
			rect.height() - 8);

		if (screenRect.contains(rect) == true) {

			isValidGeometrySetting = true;
		}
	}


	if (isValidGeometrySetting == true) {

		this->setGeometry(settings.value("recordVideoDialogGeomeotry").toRect());
	}
	else {


		QList<QScreen*> screens = QGuiApplication::screens();

		QScreen *screen = nullptr;

		for (int i = 0; i < screens.size(); i++) {

			if (screens.at(i)->geometry().contains(QCursor::pos(), true)) {

				screen = screens.at(i);
				break;
			}
		}

		if (screen != nullptr) {

			this->setGeometry(screen->availableGeometry());
		}
		else {

			this->setGeometry(QGuiApplication::primaryScreen()->availableGeometry());
		}
	}

	settings.endGroup();
}

void RecordVideoDialog::saveGeometry() {

	QSettings settings("Adora", "Adora");
	settings.beginGroup("RecordVideo");

	settings.setValue("recordVideoDialogGeomeotry", this->geometry());

	settings.endGroup();
}