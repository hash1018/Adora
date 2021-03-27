

#include "RectangleMode.h"
#include "Ui/Record/RecordVideoDialog.h"
#include "RecordVideo/Entity/Rectangle.h"
#include "RecordVideo/Unredo/AddEntityCommand.h"
#include <QMouseEvent>
#include <qpainter.h>

RectangleMode::RectangleMode(RecordVideoDialog *recordVideoDialog)
	:WritingMode(recordVideoDialog), rect(nullptr), mousePressed(false) {

	this->createWritingLayer();
}

RectangleMode::~RectangleMode() {

	this->deleteWritingLayer();
}

void RectangleMode::mousePressEvent(QMouseEvent *event) {

	this->mousePressed = true;
	this->first = event->pos();
	this->rect = new Rect(this->recordVideoDialog->getColor(this->getStatus()), 2, QRect(event->pos(), event->pos()));
	this->recordVideoDialog->getEntityList()->add(this->rect);
	this->recordVideoDialog->addCommand(new AddEntityCommand(this->recordVideoDialog, this->rect));
	this->recordVideoDialog->update();
}

void RectangleMode::mouseMoveEvent(QMouseEvent *event) {

	if (this->mousePressed == true) {
	
		QPoint topLeft, bottomRight;
		this->getTopLeftAndBottomRight(this->first, event->pos(), topLeft, bottomRight);
		this->rect->setRect(QRect(topLeft, bottomRight));
		this->recordVideoDialog->update();
	}
}

void RectangleMode::mouseReleaseEvent(QMouseEvent *event) {

	this->mousePressed = false;
	this->rect = nullptr;
}


void RectangleMode::getTopLeftAndBottomRight(const QPoint &first, const QPoint &second, QPoint &topLeft, QPoint &bottomRight) {

	if (first.x() > second.x() && first.y() > second.y()) {
		
		topLeft.setX(second.x());
		topLeft.setY(first.y());
		bottomRight.setX(first.x());
		bottomRight.setY(second.y());
	}
	else if (first.x() <= second.x() && first.y() > second.y()) {
		
		topLeft.setX(first.x());
		topLeft.setY(first.y());
		bottomRight.setX(second.x());
		bottomRight.setY(second.y());
	}
	else if (first.x() > second.x() && first.y() <= second.y()) {
		
		topLeft.setX(second.x());
		topLeft.setY(second.y());
		bottomRight.setX(first.x());
		bottomRight.setY(first.y());
	}
	else if (first.x() <= second.x() && first.y() <= second.y()) {
		
		topLeft.setX(first.x());
		topLeft.setY(second.y());
		bottomRight.setX(second.x());
		bottomRight.setY(first.y());
	}
}

QCursor RectangleMode::getCursor() {

	return QCursor(Qt::CursorShape::CrossCursor);
}