

#include "EraserMode.h"
#include "Ui/Record/RecordVideoDialog.h"
#include "RecordVideo/Entity/Visitor/Finder.h"
#include <QMouseEvent>
#include "RecordVideo/Unredo/RemoveEntityCommand.h"

EraserMode::EraserMode(RecordVideoDialog *recordVideoDialog)
	:WritingMode(recordVideoDialog) {

	this->createWritingLayer();
}

EraserMode::~EraserMode() {

	this->deleteWritingLayer();
}


void EraserMode::mousePressEvent(QMouseEvent *event) {

	this->mousePressed = true;

	auto list = this->recordVideoDialog->getEntityList();

	auto itr = list->begin();

	bool foundEntity = false;
	Finder finder(event->pos(), foundEntity);
	Entity *entity = nullptr;

	for (itr; itr != list->end(); ++itr) {
	
		(*itr)->accept(&finder);
		if (foundEntity == true) {
			entity = (*itr);
			break;
		}
	}

	if (entity != nullptr) {
	
		list->remove(entity);

		QLinkedList<Entity*> list;
		list.append(entity);

		this->recordVideoDialog->addCommand(new RemoveEntityCommand(this->recordVideoDialog, list));

		this->recordVideoDialog->update();
	}
}

void EraserMode::mouseMoveEvent(QMouseEvent *event) {

	if (this->mousePressed == true) {
	
		auto list = this->recordVideoDialog->getEntityList();

		auto itr = list->begin();

		bool foundEntity = false;
		Finder finder(event->pos(), foundEntity);
		Entity *entity = nullptr;

		for (itr; itr != list->end(); ++itr) {

			(*itr)->accept(&finder);
			if (foundEntity == true) {
				entity = (*itr);
				break;
			}
		}

		if (entity != nullptr) {

			list->remove(entity);

			QLinkedList<Entity*> list;
			list.append(entity);

			this->recordVideoDialog->addCommand(new RemoveEntityCommand(this->recordVideoDialog, list));

			this->recordVideoDialog->update();
		}
	}
}

void EraserMode::mouseReleaseEvent(QMouseEvent *event) {

	this->mousePressed = false;
}


QCursor EraserMode::getCursor() {

	return WritingMode::getCursor();
}