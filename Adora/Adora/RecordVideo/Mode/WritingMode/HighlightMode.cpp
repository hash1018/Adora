



#include "HighlightMode.h"
#include <QMouseEvent>
#include "RecordVideo/Entity/HighlightedFreeCurve.h"
#include "Ui/Record/RecordVideoDialog.h"
#include "RecordVideo/Unredo/AddEntityCommand.h"

HighlightMode::HighlightMode(RecordVideoDialog *recordVideoDialog)
	:WritingMode(recordVideoDialog), mousePressed(false), highlightedFreeCurve(nullptr) {

	this->createWritingLayer();
}

HighlightMode::~HighlightMode() {

	this->deleteWritingLayer();
}

void HighlightMode::mousePressEvent(QMouseEvent *event) {

	this->mousePressed = true;
	this->highlightedFreeCurve = new HighlightedFreeCurve(this->recordVideoDialog->getColor(this->getStatus()), 2, 125);
	this->recordVideoDialog->getEntityList()->add(this->highlightedFreeCurve);
	this->recordVideoDialog->addCommand(new AddEntityCommand(this->recordVideoDialog, this->highlightedFreeCurve));
	this->recordVideoDialog->update();
}

void HighlightMode::mouseMoveEvent(QMouseEvent *event) {

	if (this->mousePressed == true) {

		this->highlightedFreeCurve->append(event->pos());
		this->recordVideoDialog->update();
	}
}

void HighlightMode::mouseReleaseEvent(QMouseEvent *event) {

	this->mousePressed = false;
	this->highlightedFreeCurve = nullptr;
}