

#include "ControllerWidget.h"
#include <QCloseEvent>
#include <qpainter.h>

ControllerWidget::ControllerWidget(RecordVideoChain *chain)
	:QWidget(nullptr), RecordVideoChain(chain), mousePressed(false) {

	ui.setupUi(this);

	this->setMouseTracking(true);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	this->setAttribute(Qt::WA_TranslucentBackground);

	ui.recordPanel->setChain(this);
}

ControllerWidget::~ControllerWidget() {


}

void ControllerWidget::update(RecordVideoNotifyEvent *event) {

	ui.recordPanel->update(event);
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

void ControllerWidget::paintEvent(QPaintEvent *event) {

	QPainter painter(this);

	painter.setRenderHint(QPainter::Antialiasing);
	QPainterPath path;

	path.addRoundedRect(this->rect(), 15, 15);
	painter.fillPath(path, QColor("#EAEAEA"));

	QPainterPath path2;
	path2.addRoundedRect(this->rect(), 15, 15);

	painter.drawPath(path2);
}