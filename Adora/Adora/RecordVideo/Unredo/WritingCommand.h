

#ifndef _WRITINGCOMMAND_H
#define _WRITINGCOMMAND_H

class WritingCommand {

	friend class WritingUnredoStack;

public:
	WritingCommand();

	virtual void redo() = 0;
	virtual void undo() = 0;

protected:
	virtual ~WritingCommand() = 0;

};

#endif //_WRITINGCOMMAND_H
