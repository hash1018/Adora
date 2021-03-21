

#include "Hotkey.h"


Hotkey::Hotkey(QKeySequence keySequence)
	:keySequence(keySequence), type(None) {

}

Hotkey::~Hotkey() {


}

////////////////////////////////////////////


HotkeyList::HotkeyList() {

	Hotkey *hotkey = new Hotkey(QKeySequence("Ctrl+Z"));
	hotkey->setType(HotkeyType::Undo);
	this->list.append(hotkey);

	hotkey = new Hotkey(QKeySequence("Ctrl+Y"));
	hotkey->setType(HotkeyType::Redo);
	this->list.append(hotkey);
}

HotkeyList::~HotkeyList() {

	for (int i = 0; i < this->list.size(); i++) {
	
		delete this->list.at(i);
	}
}

int HotkeyList::indexOf(const QKeySequence &keySequence) {

	for (int i = 0; i < this->list.size(); i++) {
	
		if (this->list.at(i)->getKeySequence() == keySequence) {
		
			return i;
		}
	}

	return -1;
}


QKeySequence HotkeyList::getKeySequence(HotkeyType type) {

	for (int i = 0; i < this->list.size(); i++) {
	
		if (this->list.at(i)->getType() == type)
			return this->list.at(i)->getKeySequence();
	}

	return QKeySequence();
}