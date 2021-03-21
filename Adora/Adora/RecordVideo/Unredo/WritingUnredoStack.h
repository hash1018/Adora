

#ifndef _WRITINGUNREDOSTACK_H
#define _WRITINGUNREDOSTACK_H

#include <qstack.h>

class WritingCommand;

class WritingUnredoStack {

private:
	QStack<WritingCommand*> undoStack;
	QStack<WritingCommand*> redoStack;
	int max;

public:
	WritingUnredoStack();
	~WritingUnredoStack();


	void undo();
	void redo();

	void pushToUndoStack(WritingCommand *command);

public:
	inline int getUndoStackSize() const { return this->undoStack.size(); }
	inline int getRedoStackSize() const { return this->redoStack.size(); }

};

#endif //_WRITINGUNREDOSTACK_H