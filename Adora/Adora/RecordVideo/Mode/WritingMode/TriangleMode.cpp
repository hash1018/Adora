

#include "TriangleMode.h"
#include "Ui/Record/RecordVideoDialog.h"
#include "RecordVideo/Entity/Triangle.h"
#include "RecordVideo/Unredo/AddEntityCommand.h"
#include <QMouseEvent>

TriangleMode::TriangleMode(RecordVideoDialog *recordVideoDialog)
	:WritingMode(recordVideoDialog), triangle(nullptr), mousePressed(false) {

	this->createWritingLayer();
}

TriangleMode::~TriangleMode() {

	this->deleteWritingLayer();
}

void TriangleMode::mousePressEvent(QMouseEvent *event) {

	this->mousePressed = true;
	this->first = event->pos();
	this->triangle = new Triangle(this->recordVideoDialog->getColor(this->getStatus()), 2, event->pos(), event->pos(), event->pos());
	this->recordVideoDialog->getEntityList()->add(this->triangle);
	this->recordVideoDialog->addCommand(new AddEntityCommand(this->recordVideoDialog, this->triangle));
	this->recordVideoDialog->update();
}

void TriangleMode::mouseMoveEvent(QMouseEvent *event) {

	if (this->mousePressed == true) {

		QPoint v1, v2, v3;
		QPoint topLeft, bottomRight;

		this->getTopLeftAndBottomRight(this->first, event->pos(), topLeft, bottomRight);

		int width = bottomRight.x() - topLeft.x();

		v1.setX(topLeft.x() + width / 2);
		v1.setY(topLeft.y());
		v2.setX(topLeft.x());
		v2.setY(bottomRight.y());
		v3.setX(bottomRight.x());
		v3.setY(bottomRight.y());

		this->triangle->setVertex1(v1);
		this->triangle->setVertex2(v2);
		this->triangle->setVertex3(v3);
		
		this->recordVideoDialog->update();
	}
}

void TriangleMode::mouseReleaseEvent(QMouseEvent *event) {

	this->mousePressed = false;
	this->triangle = nullptr;
}

QCursor TriangleMode::getCursor() {

	return QCursor(Qt::CursorShape::CrossCursor);
}

void TriangleMode::getTopLeftAndBottomRight(const QPoint &first, const QPoint &second, QPoint &topLeft, QPoint &bottomRight) {

	if (first.x() <= second.x() && first.y() <= second.y()) {

		topLeft.setX(second.x());
		topLeft.setY(first.y());
		bottomRight.setX(first.x());
		bottomRight.setY(second.y());
	}
	else if (first.x() > second.x() && first.y() <= second.y()) {

		topLeft.setX(first.x());
		topLeft.setY(first.y());
		bottomRight.setX(second.x());
		bottomRight.setY(second.y());
	}
	else if (first.x() <= second.x() && first.y() > second.y()) {

		topLeft.setX(second.x());
		topLeft.setY(second.y());
		bottomRight.setX(first.x());
		bottomRight.setY(first.y());
	}
	else if (first.x() > second.x() && first.y() > second.y()) {

		topLeft.setX(first.x());
		topLeft.setY(second.y());
		bottomRight.setX(second.x());
		bottomRight.setY(first.y());
	}
}
