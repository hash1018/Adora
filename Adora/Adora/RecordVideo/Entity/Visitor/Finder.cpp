

#include "Finder.h"
#include "RecordVideo/Entity/FreeCurve.h"
#include <qrect.h>
#include "Base/Math.h"
#include "RecordVideo/Entity/HighlightedFreeCurve.h"
#include "RecordVideo/Entity/LineSegment.h"
#include "RecordVideo/Entity/ArrowLineSegment.h"
#include "RecordVideo/Entity/Number.h"
#include "RecordVideo/Entity/Rectangle.h"
#include "RecordVideo/Entity/Circle.h"
#include "RecordVideo/Entity/Triangle.h"


Finder::Finder(const QPoint &point, bool &foundEntity)
	:point(point), foundEntity(foundEntity) {

}

Finder::~Finder() {

}

void Finder::visit(FreeCurve *freeCurve) {

	int width = freeCurve->getWidth();

	if (freeCurve->getSize() == 0)
		return;

	else if (freeCurve->getSize() == 1) {
	
		QRect rect(QPoint(this->point.x() - width, this->point.y() - width),
			QPoint(point.x() + width, point.y() + width));

		if (math::checkPointLiesInsideRect(*freeCurve->getPoint(0), QPoint(point.x() - width, point.y() - width),
			QPoint(point.x() + width, point.y() + width), width) == true) {
		
			this->foundEntity = true;
			return;
		}
	}
	else {
	
		QPoint temp = *freeCurve->getPoint(0);

		for (int i = 1; i < freeCurve->getSize(); i++) {

			if (math::checkPointLiesOnLine(point, temp, *freeCurve->getPoint(i), width) == true) {

				this->foundEntity = true;
				return;
			}

			temp = *freeCurve->getPoint(i);
		}
	}

	this->foundEntity = false;
}



void Finder::visit(HighlightedFreeCurve *highlightedFreeCurve) {

	this->visit((FreeCurve*)highlightedFreeCurve);
}

void Finder::visit(LineSegment *lineSegment) {

	if (math::checkPointLiesOnLine(point, lineSegment->getStart(), lineSegment->getEnd(), lineSegment->getWidth()) == true) {

		this->foundEntity = true;
		return;
	}

	this->foundEntity = false;
}


void Finder::visit(ArrowLineSegment *arrowLineSegment) {

	if (math::checkPointLiesOnLine(point, arrowLineSegment->getStart(), arrowLineSegment->getEnd(), 
		arrowLineSegment->getWidth()) == true) {

		this->foundEntity = true;
		return;
	}

	QPoint p1, p2, p3;
	arrowLineSegment->getArrowPoints(p1, p2, p3);

	if (math::checkPointLiesOnLine(point, p1, p2,
		arrowLineSegment->getWidth()) == true) {

		this->foundEntity = true;
		return;
	}

	if (math::checkPointLiesOnLine(point, p1, p3,
		arrowLineSegment->getWidth()) == true) {

		this->foundEntity = true;
		return;
	}

	this->foundEntity = false;
}

void Finder::visit(Number *number) {

	if (math::checkPointLiesInsideCircle(this->point, number->getPoint(), number->getWidth() / 2) == true) {
	
		this->foundEntity = true;
		return;
	}

	this->foundEntity = false;
}


void Finder::visit(Rect *rectangle) {

	QRect rect = rectangle->getRect();
	int tolerance = rectangle->getWidth() / 2;

	if (math::checkPointLiesOnLine(this->point, rect.topLeft(), rect.topRight(), tolerance) == true) {
		this->foundEntity = true;
		return;
	}

	if (math::checkPointLiesOnLine(this->point, rect.topRight(), rect.bottomRight(), tolerance) == true) {
		this->foundEntity = true;
		return;
	}

	if (math::checkPointLiesOnLine(this->point, rect.bottomRight(), rect.bottomLeft(), tolerance) == true) {
		this->foundEntity = true;
		return;
	}

	if (math::checkPointLiesOnLine(this->point, rect.bottomLeft(), rect.topLeft(), tolerance) == true) {
		this->foundEntity = true;
		return;
	}

	this->foundEntity = false;
}

void Finder::visit(Circle *circle) {

	if (math::checkPointLiesOnCircleBoundary(this->point, circle->getCenter(), circle->getRadius(), circle->getWidth() / 2) == true) {
		this->foundEntity = true;
		return;
	}

	this->foundEntity = false;
}

void Finder::visit(Triangle *triangle) {

	int tolerance = triangle->getWidth() / 2;

	if (math::checkPointLiesOnLine(this->point, triangle->getVertex1(), triangle->getVertex2(), tolerance) == true) {
		this->foundEntity = true;
		return;
	}

	if (math::checkPointLiesOnLine(this->point, triangle->getVertex2(), triangle->getVertex3(), tolerance) == true) {
		this->foundEntity = true;
		return;
	}

	if (math::checkPointLiesOnLine(this->point, triangle->getVertex3(), triangle->getVertex1(), tolerance) == true) {
		this->foundEntity = true;
		return;
	}

	this->foundEntity = false;
}