

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

	int num = 0;

	auto itr = this->recordVideoDialog->getEntityList()->begin();
	for (itr; itr != this->recordVideoDialog->getEntityList()->end(); ++itr) {
	
		if (dynamic_cast<Number*>(*itr)) {
			
			if (dynamic_cast<Number*>(*itr)->getNumber() >= num) {
				num = dynamic_cast<Number*>(*itr)->getNumber() + 1;
			}
		}
	}

	if (num == 0)
		num++;


	Number *number = new Number(this->recordVideoDialog->getColor(this->getStatus()), 20, event->pos(), num);
	this->recordVideoDialog->getEntityList()->add(number);
	this->recordVideoDialog->addCommand(new AddEntityCommand(this->recordVideoDialog, number));
	this->recordVideoDialog->update();
}



QCursor NumberingMode::getCursor() {

	return QCursor(Qt::CursorShape::CrossCursor);
}