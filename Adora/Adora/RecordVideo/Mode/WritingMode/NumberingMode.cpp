

#include "NumberingMode.h"
#include "Ui/Record/RecordVideoDialog.h"
#include "RecordVideo/Entity/Number.h"
#include "RecordVideo/Unredo/AddEntityCommand.h"
#include <QMouseEvent>

NumberingMode::NumberingMode(RecordVideoDialog *recordVideoDialog)
	:WritingMode(recordVideoDialog) {

	this->createWritingLayer();
}

NumberingMode::~NumberingMode() {

	this->deleteWritingLayer();
}

void NumberingMode::mousePressEvent(QMouseEvent *event) {

	Number *number = new Number(QColor(0, 0, 0), 10, event->pos());
	this->recordVideoDialog->getEntityList()->add(number);
	this->recordVideoDialog->addCommand(new AddEntityCommand(this->recordVideoDialog, number));
	this->recordVideoDialog->update();
}
