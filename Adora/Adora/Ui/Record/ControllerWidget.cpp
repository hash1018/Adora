

#include "ControllerWidget.h"
#include <QCloseEvent>
#include <qpainter.h>
#include "RecordVideo/Chain/RecordVideoRequest.h"
#include <qsettings.h>
#include <qscreen.h>

ControllerWidget::ControllerWidget(RecordVideoChain *chain)
	:QWidget(nullptr), RecordVideoChain(chain), mousePressed(false) {

	ui.setupUi(this);

	this->setMouseTracking(true);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	this->setAttribute(Qt::WA_TranslucentBackground);
	this->setFocusPolicy(Qt::FocusPolicy::StrongFocus);

	ui.recordPanel->setChain(this);
	ui.writingPanel->setChain(this);
	ui.unredoPanel->setChain(this);
	ui.soundPanel->setChain(this);

	this->loadGeometry();
}

ControllerWidget::~ControllerWidget() {


}

void ControllerWidget::update(RecordVideoNotifyEvent *event) {

	ui.recordPanel->update(event);
	ui.writingPanel->update(event);
	ui.unredoPanel->update(event);
	ui.soundPanel->update(event);
}

void ControllerWidget::loadGeometry() {

	QSettings settings("Adora", "Adora");
	settings.beginGroup("RecordVideo");

	bool existGeometrySetting = settings.contains("controlloerGeometry");
	bool isValidGeometrySetting = false;

	if (existGeometrySetting == true) {

		QRect rect = settings.value("controlloerGeometry").toRect();

		this->setGeometry(settings.value("controlloerGeometry").toRect());

		QList<QScreen*> screens = QGuiApplication::screens();
		QRect screenRect;

		for (int i = 0; i < screens.size(); i++) {

			screenRect = screenRect.united(screens.at(i)->geometry());
		}

		if (screenRect.contains(rect) == true) {

			isValidGeometrySetting = true;
		}
	}


	if (isValidGeometrySetting == true) {

		this->setGeometry(settings.value("controlloerGeometry").toRect());
	}
	else {

		this->move(0, 0);
	}


	settings.endGroup();
}

void ControllerWidget::saveGeometry() {

	QSettings settings("Adora", "Adora");
	settings.beginGroup("RecordVideo");

	settings.setValue("controlloerGeometry", this->geometry());

	settings.endGroup();
}

void ControllerWidget::closeEvent(QCloseEvent *event) {
	event->ignore();
}

void ControllerWidget::mousePressEvent(QMouseEvent *event) {

	if (event->button() == Qt::LeftButton) {
	
		this->mousePressed = true;
		this->prev = event->globalPos();
	}
}

void ControllerWidget::mouseMoveEvent(QMouseEvent *event) {

	if (this->mousePressed == true) {
	
		QPoint delta = event->globalPos() - this->prev;
		this->move(this->x() + delta.x(), this->y() + delta.y());

		this->prev = event->globalPos();
	}
}

void ControllerWidget::mouseReleaseEvent(QMouseEvent *event) {

	this->mousePressed = false;
}

void ControllerWidget::paintEvent(QPaintEvent *event) {

	QPainter painter(this);

	painter.setRenderHint(QPainter::Antialiasing);
	QPainterPath path;

	path.addRoundedRect(this->rect(), 15, 15);
	painter.fillPath(path, QColor("#EAEAEA"));

	QPainterPath path2;
	path2.addRoundedRect(this->rect(), 15, 15);

	painter.drawPath(path2);
}

void ControllerWidget::keyPressEvent(QKeyEvent *event) {

	RecordVideoRequestKeyEvent request(event);
	this->request(&request);
}