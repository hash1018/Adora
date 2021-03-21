

#ifndef _REMOVEENTITYCOMMAND_H
#define _REMOVEENTITYCOMMAND_H

#include "WritingCommand.h"
#include <qlinkedlist.h>

class RecordVideoDialog;
class Entity;

class RemoveEntityCommand : public WritingCommand {

private:
	RecordVideoDialog *recordVideoDialog;
	QLinkedList<Entity*> list;
	bool mustDeleteEntity;

public:
	RemoveEntityCommand(RecordVideoDialog *recordVideoDialog, const QLinkedList<Entity*> &list);
	~RemoveEntityCommand();

	virtual void redo();
	virtual void undo();
};


#endif //_REMOVEENTITYCOMMAND_H