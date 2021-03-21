

#include "PencilMode.h"

PencilMode::PencilMode(RecordVideoDialog *recordVideoDialog)
	:WritingMode(recordVideoDialog) {

	this->createWritingLayer();
}

PencilMode::~PencilMode() {

	this->deleteWritingLayer();
}

void PencilMode::mousePressEvent(QMouseEvent *event) {
	
}

void PencilMode::mouseMoveEvent(QMouseEvent *event) {

}

void PencilMode::mouseReleaseEvent(QMouseEvent *event) {

}