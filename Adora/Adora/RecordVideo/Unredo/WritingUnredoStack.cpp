
#include "WritingUnredoStack.h"
#include "WritingCommand.h"

WritingUnredoStack::WritingUnredoStack()
	:max(50) {


}

WritingUnredoStack::~WritingUnredoStack() {

	while (!this->redoStack.isEmpty())
		delete this->redoStack.pop();

	while (!this->undoStack.isEmpty())
		delete this->undoStack.pop();
}

void WritingUnredoStack::undo() {

	if (!this->undoStack.isEmpty()) {

		WritingCommand *command = this->undoStack.pop();
		command->undo();

		if (this->redoStack.size() > this->max) {

			delete this->redoStack[0];
			this->redoStack.pop_front();
		}

		this->redoStack.push(command);
	}
}

void WritingUnredoStack::redo() {

	if (!this->redoStack.isEmpty()) {

		WritingCommand *command = this->redoStack.pop();
		command->redo();

		if (this->undoStack.size() > this->max) {

			delete this->undoStack[0];
			this->undoStack.pop_front();

		}
		this->undoStack.push(command);
	}
}

void WritingUnredoStack::pushToUndoStack(WritingCommand *command) {

	if (this->undoStack.size() > this->max) {

		delete this->undoStack[0];
		this->undoStack.pop_front();
	}

	this->undoStack.push(command);

	if (!this->redoStack.isEmpty()) {

		while (!this->redoStack.isEmpty())
			delete this->redoStack.pop();
	}
}