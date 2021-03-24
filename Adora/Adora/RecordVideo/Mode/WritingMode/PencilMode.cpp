

#include "PencilMode.h"
#include <QMouseEvent>
#include "RecordVideo/Entity/FreeCurve.h"
#include "Ui/Record/RecordVideoDialog.h"
#include "RecordVideo/Unredo/AddEntityCommand.h"

PencilMode::PencilMode(RecordVideoDialog *recordVideoDialog)
	:WritingMode(recordVideoDialog), mousePressed(false), freeCurve(nullptr) {

	this->createWritingLayer();
}

PencilMode::~PencilMode() {

	this->deleteWritingLayer();
}

void PencilMode::mousePressEvent(QMouseEvent *event) {
	
	this->mousePressed = true;
	this->freeCurve = new FreeCurve(this->recordVideoDialog->getColor(this->getStatus()), 2);
	this->recordVideoDialog->getEntityList()->add(this->freeCurve);
	this->recordVideoDialog->addCommand(new AddEntityCommand(this->recordVideoDialog, this->freeCurve));
	this->recordVideoDialog->update();
}

void PencilMode::mouseMoveEvent(QMouseEvent *event) {

	if (this->mousePressed == true) {
	
		this->freeCurve->append(event->pos());
		this->recordVideoDialog->update();
	}
}

void PencilMode::mouseReleaseEvent(QMouseEvent *event) {

	this->mousePressed = false;
	this->freeCurve = nullptr;
}