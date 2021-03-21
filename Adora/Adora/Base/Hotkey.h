

#ifndef _HOTKEY_H
#define _HOTKEY_H

#include <qlist.h>
#include <qkeysequence.h>
#include "Base/Singleton.h"

enum HotkeyType {

	None,
	VideoStartAndStop,
	VideoPauseAndResume,
	ImageCapture,
	Undo,
	Redo,
};


class Hotkey {

private:
	QKeySequence keySequence;
	HotkeyType type;

public:
	Hotkey(QKeySequence keySequence);
	~Hotkey();

	void setType(HotkeyType type) { this->type = type; }
	const QKeySequence& getKeySequence() const { return this->keySequence; }
	HotkeyType getType() const { return this->type; }

};

class HotkeyList {

	DeclareSingleton(HotkeyList)

private:
	QList<Hotkey*> list;

public:
	int indexOf(const QKeySequence &keySequence);
	void append(Hotkey *hotkey) { this->list.append(hotkey); }
	void removeAt(int index) { this->list.removeAt(index); }
	Hotkey* at(int index) { return this->list.at(index); }
	int size() const { return this->list.size(); }

	QKeySequence getKeySequence(HotkeyType type);

};

#endif //_HOTKEY_H
