
#include "RecordVideoDialog.h"
#include <qpainter.h>
#include <QResizeEvent>
#include "ControllerWidget.h"

RecordVideoDialog::RecordVideoDialog(QWidget *parent)
	:QDialog(parent,Qt::FramelessWindowHint) {

	this->setMouseTracking(true);
	this->setAttribute(Qt::WA_TranslucentBackground);
	this->setWindowFlag(Qt::WindowStaysOnTopHint);


	this->controllerWidget = new ControllerWidget;
	this->controllerWidget->show();
	this->controllerWidget->move(100, 100);
}

RecordVideoDialog::~RecordVideoDialog() {

	if (this->controllerWidget != nullptr)
		delete this->controllerWidget;

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