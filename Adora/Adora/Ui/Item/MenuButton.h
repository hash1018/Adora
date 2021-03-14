

#ifndef _MENUBUTTON_H
#define _MENUBUTTON_H

#include <qpushbutton.h>
#include <qicon.h>
class MenuButton : public QPushButton {

private:
	QIcon icon;
	bool selected;
	QString text;

public:
	MenuButton(QWidget *parent = nullptr);
	~MenuButton();

	void setIcon(const QIcon &icon);
	void setSelected(bool selected);
	void setText(const QString &text);

protected:
	virtual void paintEvent(QPaintEvent *event);


};

#endif //_MENUBUTTON_H
