

#include "ControllerWidget.h"
#include <QCloseEvent>

ControllerWidget::ControllerWidget()
	:QWidget(nullptr), mousePressed(false) {

	this->setMouseTracking(true);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
}

ControllerWidget::~ControllerWidget() {


}

void ControllerWidget::closeEvent(QCloseEvent *event) {
	event->ignore();
}

void ControllerWidget::mousePressEvent(QMouseEvent *event) {

	if (event->button() == Qt::LeftButton) {
	
		this->mousePressed = true;
		this->prev = event->globalPos();
	}
}

void ControllerWidget::mouseMoveEvent(QMouseEvent *event) {

	if (this->mousePressed == true) {
	
		QPoint delta = event->globalPos() - this->prev;
		this->move(this->x() + delta.x(), this->y() + delta.y());

		this->prev = event->globalPos();
	}
}

void ControllerWidget::mouseReleaseEvent(QMouseEvent *event) {

	this->mousePressed = false;
}