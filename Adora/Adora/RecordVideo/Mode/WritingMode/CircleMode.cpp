

#include "CircleMode.h"
#include "Ui/Record/RecordVideoDialog.h"
#include "RecordVideo/Entity/Circle.h"
#include "RecordVideo/Unredo/AddEntityCommand.h"
#include <QMouseEvent>
#include "Base/Math.h"


CircleMode::CircleMode(RecordVideoDialog *recordVideoDialog)
	:WritingMode(recordVideoDialog), circle(nullptr), mousePressed(false) {

	this->createWritingLayer();
}

CircleMode::~CircleMode() {

	this->deleteWritingLayer();
}

void CircleMode::mousePressEvent(QMouseEvent *event) {

	this->mousePressed = true;
	this->center = event->pos();
	this->circle = new Circle(this->recordVideoDialog->getColor(this->getStatus()),
		this->recordVideoDialog->getWidth(this->getStatus()), event->pos(), 0);
	this->recordVideoDialog->getEntityList()->add(this->circle);
	this->recordVideoDialog->addCommand(new AddEntityCommand(this->recordVideoDialog, this->circle));
	this->recordVideoDialog->update();
}

void CircleMode::mouseMoveEvent(QMouseEvent *event) {

	if (this->mousePressed == true) {
	
		int dis = math::getDistance(this->center.x(), this->center.y(), event->pos().x(), event->pos().y());
		this->circle->setRadius(dis);
		this->recordVideoDialog->update();
	}
}

void CircleMode::mouseReleaseEvent(QMouseEvent *event) {

	this->mousePressed = false;
	this->circle = nullptr;
}

QCursor CircleMode::getCursor() {

	return QCursor(Qt::CursorShape::CrossCursor);
}