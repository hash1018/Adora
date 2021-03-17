

#include "HotkeyLineEdit.h"
#include <QKeyEvent>

HotkeyLineEdit::HotkeyLineEdit(QWidget *parent)
	:QLineEdit(parent) {

	this->setReadOnly(true);
}

HotkeyLineEdit::~HotkeyLineEdit() {


}

void HotkeyLineEdit::keyPressEvent(QKeyEvent *event) {

	if (event->key() >= Qt::Key_Space && event->key() <= Qt::Key_AsciiTilde) {
		this->setText(QKeySequence(event->modifiers() + event->key()).toString());

		emit this->hotkeyEmitted(event->modifiers(), event->key());

	}
	else {
		QString str = QKeySequence(event->modifiers()).toString();
		int pos = str.lastIndexOf('+');
		str = str.left(pos);
		
		this->setText(str);

		emit this->hotkeyEmitted(event->modifiers());
	}
	
}