
#include "Adora.h"
#include <QMouseEvent>
#include "Base/SettingManager.h"

Adora::Adora(QWidget *parent)
	: QMainWindow(parent), mousePressed(false) {

	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint);

	connect(ui.adoraFrameWidget, &AdoraFrameWidget::closeButtonClicked, this, &Adora::closeButtonClicked);
	connect(ui.adoraFrameWidget, &AdoraFrameWidget::minimizeButtonClicked, this, &Adora::minimizeButtonClicked);

	SettingManager::getInstance()->load();

	this->initPosition();
}

Adora::~Adora() {

}

void Adora::closeEvent(QCloseEvent *event) {

	QMainWindow::closeEvent(event);

	SettingManager::getInstance()->setAdoraPosition(this->pos());
	SettingManager::getInstance()->save();
}


void Adora::mousePressEvent(QMouseEvent *event) {

	this->mousePressed = true;
	this->prev = event->globalPos();
}

void Adora::mouseMoveEvent(QMouseEvent *event) {

	if (this->mousePressed == true) {
	
		QPoint current = event->globalPos();

		QPoint delta = current - this->prev;

		this->move(this->x() + delta.x(), this->y() + delta.y());

		this->prev = current;
	}
}

void Adora::mouseReleaseEvent(QMouseEvent *event) {

	this->mousePressed = false;
}

void Adora::closeButtonClicked() {

	this->close();
	
}

void Adora::minimizeButtonClicked() {

	this->showMinimized();
}

#include <qscreen.h>
void Adora::initPosition() {

	QPoint position = SettingManager::getInstance()->getAdoraPosition();

	QRect rect = QRect(position.x(), position.y(), this->minimumWidth(), this->minimumHeight());

	QList<QScreen*> screens = QGuiApplication::screens();
	QRect screenRect;

	for (int i = 0; i < screens.size(); i++) {
		screenRect = screenRect.united(screens.at(i)->geometry());
	}

	if (screenRect.contains(rect) == true) {
		this->setGeometry(rect);
	}
	else {
		this->setGeometry(0, 0, this->minimumWidth(), this->minimumHeight());
	}
}