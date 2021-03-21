

#include "RemoveEntityCommand.h"
#include "Ui/Record/RecordVideoDialog.h"

RemoveEntityCommand::RemoveEntityCommand(RecordVideoDialog *recordVideoDialog, const QLinkedList<Entity*> &list)
	:recordVideoDialog(recordVideoDialog), list(list), mustDeleteEntity(true) {

}

RemoveEntityCommand::~RemoveEntityCommand() {

	if (this->mustDeleteEntity == true) {

		while (!this->list.isEmpty())
			delete this->list.takeFirst();
	}
}

void RemoveEntityCommand::undo() {

	auto itr = this->list.begin();

	for (itr; itr != this->list.end(); ++itr)
		this->recordVideoDialog->getEntityList()->add((*itr));

	this->mustDeleteEntity = false;
	this->recordVideoDialog->update();
}

void RemoveEntityCommand::redo() {

	auto itr = this->list.begin();

	for (itr; itr != this->list.end(); ++itr)
		this->recordVideoDialog->getEntityList()->remove((*itr));

	this->mustDeleteEntity = true;

	this->recordVideoDialog->update();
}