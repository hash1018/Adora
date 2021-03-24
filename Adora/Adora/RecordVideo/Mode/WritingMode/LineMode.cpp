

#include "LineMode.h"

#include "Ui/Record/RecordVideoDialog.h"
#include "RecordVideo/Entity/LineSegment.h"
#include "RecordVideo/Unredo/AddEntityCommand.h"
#include <QMouseEvent>

LineMode::LineMode(RecordVideoDialog *recordVideoDialog)
	:WritingMode(recordVideoDialog), mousePressed(false), lineSegment(nullptr) {

	this->createWritingLayer();
}

LineMode::~LineMode() {

	this->deleteWritingLayer();
}

void LineMode::mousePressEvent(QMouseEvent *event) {

	this->mousePressed = true;
	this->lineSegment = new LineSegment(this->recordVideoDialog->getColor(this->getStatus()), 2, event->pos(), event->pos());
	this->recordVideoDialog->getEntityList()->add(this->lineSegment);
	this->recordVideoDialog->addCommand(new AddEntityCommand(this->recordVideoDialog, this->lineSegment));
	this->recordVideoDialog->update();
}

void LineMode::mouseMoveEvent(QMouseEvent *event) {

	if (this->mousePressed == true) {
	
		this->lineSegment->setEnd(event->pos());
		this->recordVideoDialog->update();
	}
}

void LineMode::mouseReleaseEvent(QMouseEvent *event) {

	this->mousePressed = false;
	this->lineSegment = nullptr;
}