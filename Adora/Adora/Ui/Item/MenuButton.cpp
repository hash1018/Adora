

#include "MenuButton.h"
#include <qpainter.h>

MenuButton::MenuButton(QWidget *parent)
	:QPushButton(parent), selected(false) {

}

MenuButton::~MenuButton() {

}

void MenuButton::setIcon(const QIcon &icon) {

	this->icon = icon;
	this->update();
}

void MenuButton::setSelected(bool selected) {

	this->selected = selected;
	this->update();
}

void MenuButton::paintEvent(QPaintEvent *event) {

	QPushButton::paintEvent(event);

	QPainter painter(this);

	painter.drawPixmap(0, 0, 34, 34, this->icon.pixmap(34, 34));
	
	if (this->selected == true) {
	
		this->setChecked(true);
	}
	else {
	
		this->setChecked(false);
	}
}