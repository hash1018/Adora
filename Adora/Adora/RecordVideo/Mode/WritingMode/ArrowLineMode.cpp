

#include "ArrowLineMode.h"

#include "Ui/Record/RecordVideoDialog.h"
#include "RecordVideo/Entity/ArrowLineSegment.h"
#include "RecordVideo/Unredo/AddEntityCommand.h"
#include <QMouseEvent>

ArrowLineMode::ArrowLineMode(RecordVideoDialog *recordVideoDialog)
	:WritingMode(recordVideoDialog), mousePressed(false), arrowLineSegment(nullptr) {

	this->createWritingLayer();
}

ArrowLineMode::~ArrowLineMode() {

	this->deleteWritingLayer();
}

void ArrowLineMode::mousePressEvent(QMouseEvent *event) {

	this->mousePressed = true;
	this->arrowLineSegment = new ArrowLineSegment(this->recordVideoDialog->getColor(this->getStatus()),
		this->recordVideoDialog->getWidth(this->getStatus()), event->pos(), event->pos());
	this->recordVideoDialog->getEntityList()->add(this->arrowLineSegment);
	this->recordVideoDialog->addCommand(new AddEntityCommand(this->recordVideoDialog, this->arrowLineSegment));
	this->recordVideoDialog->update();
}

void ArrowLineMode::mouseMoveEvent(QMouseEvent *event) {

	if (this->mousePressed == true) {

		this->arrowLineSegment->setEnd(event->pos());
		this->recordVideoDialog->update();
	}
}

void ArrowLineMode::mouseReleaseEvent(QMouseEvent *event) {

	this->mousePressed = false;
	this->arrowLineSegment = nullptr;
}

QCursor ArrowLineMode::getCursor() {

	return QCursor(Qt::CursorShape::CrossCursor);
}