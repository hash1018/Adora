

#include "Hotkey.h"


Hotkey::Hotkey(QKeySequence keySequence)
	:keySequence(keySequence), type(None) {

}

Hotkey::~Hotkey() {


}

////////////////////////////////////////////


HotkeyList::HotkeyList() {

}

HotkeyList::~HotkeyList() {

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