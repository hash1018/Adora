

#include "HotkeyLineEdit.h"
#include <QKeyEvent>

QList<QKeySequence> HotkeyLineEdit::lists;

HotkeyLineEdit::HotkeyLineEdit(QWidget *parent)
	:QLineEdit(parent) {

	this->setReadOnly(true);
}

HotkeyLineEdit::~HotkeyLineEdit() {


}

void HotkeyLineEdit::keyPressEvent(QKeyEvent *event) {

	if (event->key() >= Qt::Key_Space && event->key() <= Qt::Key_AsciiTilde) {

		int index = HotkeyLineEdit::lists.indexOf(QKeySequence(event->modifiers() + event->key()));

		if (index == -1) {
		
			HotkeyLineEdit::lists.append(QKeySequence(event->modifiers() + event->key()));
			
			if (HotkeyLineEdit::lists.indexOf(this->keySequence) != -1)
				HotkeyLineEdit::lists.removeAt(HotkeyLineEdit::lists.indexOf(this->keySequence));

			this->keySequence = QKeySequence(event->modifiers() + event->key());
		}
		else {
		
			return;
		}

		this->setText(QKeySequence(event->modifiers() + event->key()).toString());

		emit this->hotkeyEmitted(event->modifiers(), event->key());

	}
	else {

		int index = HotkeyLineEdit::lists.indexOf(QKeySequence(event->modifiers()));

		if (index == -1) {

			HotkeyLineEdit::lists.append(QKeySequence(event->modifiers()));

			if (HotkeyLineEdit::lists.indexOf(this->keySequence) != -1)
				HotkeyLineEdit::lists.removeAt(HotkeyLineEdit::lists.indexOf(this->keySequence));

			this->keySequence = QKeySequence(event->modifiers());
		}
		else {

			return;
		}

		QString str = QKeySequence(event->modifiers()).toString();
		int pos = str.lastIndexOf('+');
		str = str.left(pos);
		
		this->setText(str);

		emit this->hotkeyEmitted(event->modifiers());
	}
	
}