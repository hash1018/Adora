
#include "RecordVideoDialog.h"
#include <qpainter.h>
#include <QResizeEvent>
#include "ControllerWidget.h"
#include "RecordVideo/Chain/RecordVideoRequestStrategyFactory.h"
#include "RecordVideo/Chain/RecordVideoRequestStrategy.h"
#include "RecordVideo/Mode/RecordStatusMode/RecordStatusMode.h"
#include "RecordVideo/Mode/RecordStatusMode/RecordStatusModeFactory.h"
#include "RecordVideo/NotifyEvent/RecordVideoNotifyEvent.h"

RecordVideoDialog::RecordVideoDialog(QWidget *parent)
	:QDialog(parent, Qt::FramelessWindowHint), recordStatusMode(nullptr) {

	this->setMouseTracking(true);
	this->setAttribute(Qt::WA_TranslucentBackground);
	this->setWindowFlag(Qt::WindowStaysOnTopHint);


	this->controllerWidget = new ControllerWidget(this);
	this->controllerWidget->show();
	this->controllerWidget->move(100, 100);



	this->changeRecordStatusMode(RecordStatus::NotRecording);
}

RecordVideoDialog::~RecordVideoDialog() {

	if (this->controllerWidget != nullptr)
		delete this->controllerWidget;

	if (this->recordStatusMode != nullptr)
		delete this->recordStatusMode;
}

void RecordVideoDialog::changeRecordStatusMode(RecordStatus recordStatus) {

	if (this->recordStatusMode != nullptr)
		delete this->recordStatusMode;

	this->recordStatusMode = RecordStatusModeFactory::create(this, recordStatus);

	RecordVideoStatusChangedEvent event(recordStatus);
	this->controllerWidget->update(&event);
}


void RecordVideoDialog::request(RecordVideoRequest *request) {

	RecordVideoRequestStrategy *strategy = RecordVideoRequestStrategyFactory::create(this, request);
	
	if (strategy != nullptr)
		strategy->response();
}

void RecordVideoDialog::record() {

	this->changeRecordStatusMode(RecordStatus::Recording);
}

void RecordVideoDialog::quit() {

	this->close();
}

void RecordVideoDialog::pause() {

	this->changeRecordStatusMode(RecordStatus::Paused);
}

void RecordVideoDialog::stop() {

	this->close();
}

void RecordVideoDialog::resume() {

	this->changeRecordStatusMode(RecordStatus::Recording);
}

void RecordVideoDialog::capture() {


}

void RecordVideoDialog::keyPressEvent(QKeyEvent *event) {


}

void RecordVideoDialog::paintEvent(QPaintEvent *event) {

	QPainter painter(this);

	QPen pen(QColor("#FFB513"));
	pen.setWidth(5);

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

	
}


void RecordVideoDialog::resizeEvent(QResizeEvent *event) {

	QDialog::resizeEvent(event);

	this->recordAreaRect.setRect(4, 4, event->size().width() - 8, event->size().height() - 8);
}

void RecordVideoDialog::mouseMoveEvent(QMouseEvent *event) {

}

void RecordVideoDialog::mousePressEvent(QMouseEvent *event) {

}

void RecordVideoDialog::mouseReleaseEvent(QMouseEvent *event) {


}

void RecordVideoDialog::closeEvent(QCloseEvent *event) {

	event->ignore();

	emit this->recordVideoDialogClosed();
}



QRect RecordVideoDialog::getRecordBorderRect() {

	return QRect(this->recordAreaRect.x() - 2, this->recordAreaRect.y() - 2,
		this->recordAreaRect.width() + 5, this->recordAreaRect.height() + 5);
}