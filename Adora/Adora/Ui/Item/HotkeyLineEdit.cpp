

#include "HotkeyLineEdit.h"
#include <QKeyEvent>
#include "Base/Hotkey.h"

HotkeyLineEdit::HotkeyLineEdit(QWidget *parent)
	:QLineEdit(parent) {

	this->setReadOnly(true);
}

HotkeyLineEdit::~HotkeyLineEdit() {
	

}

void HotkeyLineEdit::load(Hotkey *hotkey) {

	QKeySequence temp = hotkey->getKeySequence();

	if (HotkeyList::getInstance()->indexOf(temp) == -1) {
	
		this->keySequence = temp;
		HotkeyList::getInstance()->append(hotkey);
		this->setText(keySequence.toString());
	}
	else {
	
		delete hotkey;
	}
}

void HotkeyLineEdit::keyPressEvent(QKeyEvent *event) {

	if (event->key() >= Qt::Key_Space && event->key() <= Qt::Key_AsciiTilde) {

		int index = HotkeyList::getInstance()->indexOf(QKeySequence(event->modifiers() + event->key()));

		if (index == -1) {
		
			HotkeyList::getInstance()->append(new Hotkey(QKeySequence(event->modifiers() + event->key())));
			
			if (HotkeyList::getInstance()->indexOf(this->keySequence) != -1)
				HotkeyList::getInstance()->removeAt(HotkeyList::getInstance()->indexOf(this->keySequence));

			this->keySequence = QKeySequence(event->modifiers() + event->key());

			this->setText(QKeySequence(event->modifiers() + event->key()).toString());

			emit this->hotkeyEmitted(this->keySequence);
		}
	}
}