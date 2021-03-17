

#ifndef _HOTKEYLINEEDIT_H
#define _HOTKEYLINEEDIT_H

#include <qlineedit.h>

#include <qlist.h>

class HotkeyLineEdit : public QLineEdit {

	Q_OBJECT

private:
	static QList<QKeySequence> lists;

	QKeySequence keySequence;

public:
	HotkeyLineEdit(QWidget *parent = nullptr);
	~HotkeyLineEdit();

signals:
	void hotkeyEmitted(Qt::KeyboardModifiers modifiers, int key);
	void hotkeyEmitted(Qt::KeyboardModifiers modifiers);

protected:
	virtual void keyPressEvent(QKeyEvent *event);

};

#endif //_HOTKEYLINEEDIT_H