

#include "AddEntityCommand.h"
#include "RecordVideo/Entity/Entity.h"
#include "Ui/Record/RecordVideoDialog.h"

AddEntityCommand::AddEntityCommand(RecordVideoDialog *recordVideoDialog, Entity *entity)
	:recordVideoDialog(recordVideoDialog), entity(entity), mustDeleteEntity(false) {

}

AddEntityCommand::~AddEntityCommand() {

	if (this->mustDeleteEntity == true) {
		delete this->entity;
	}
}


void AddEntityCommand::redo() {

	this->recordVideoDialog->getEntityList()->add(this->entity);
	this->mustDeleteEntity = false;

	this->recordVideoDialog->update();
}

void AddEntityCommand::undo() {

	this->recordVideoDialog->getEntityList()->remove(this->entity);
	this->mustDeleteEntity = true;

	this->recordVideoDialog->update();
}