

#ifndef _ADDENTITYCOMMAND_H
#define _ADDENTITYCOMMAND_H

#include "WritingCommand.h"

class RecordVideoDialog;
class Entity;

class AddEntityCommand : public WritingCommand {

private:
	RecordVideoDialog *recordVideoDialog;
	Entity *entity;
	bool mustDeleteEntity;

public:
	AddEntityCommand(RecordVideoDialog *recordVideoDialog, Entity *entity);
	~AddEntityCommand();

	virtual void undo();
	virtual void redo();
};

#endif //_ADDENTITYCOMMAND_H