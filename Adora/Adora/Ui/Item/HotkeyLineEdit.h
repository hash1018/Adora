

#ifndef _HOTKEYLINEEDIT_H
#define _HOTKEYLINEEDIT_H

#include <qlineedit.h>
class Hotkey;

class HotkeyLineEdit : public QLineEdit {

	Q_OBJECT

private:
	QKeySequence keySequence;

public:
	HotkeyLineEdit(QWidget *parent = nullptr);
	~HotkeyLineEdit();

	void load(Hotkey *hotkey);

signals:
	void hotkeyEmitted(const QKeySequence &sequence);

protected:
	virtual void keyPressEvent(QKeyEvent *event);

};

#endif //_HOTKEYLINEEDIT_H