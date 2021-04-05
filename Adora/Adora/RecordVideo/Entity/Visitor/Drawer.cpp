

#include "Drawer.h"
#include <qpainter.h>
#include "RecordVideo/Entity/FreeCurve.h"
#include "RecordVideo/Entity/HighlightedFreeCurve.h"
#include "RecordVideo/Entity/LineSegment.h"
#include "RecordVideo/Entity/ArrowLineSegment.h"
#include "RecordVideo/Entity/Number.h"
#include "RecordVideo/Entity/Rectangle.h"
#include "RecordVideo/Entity/Circle.h"
#include "RecordVideo/Entity/Triangle.h"
#include "Base/Math.h"

Drawer::Drawer(QPainter &painter)
	:painter(painter) {

}

Drawer::~Drawer() {

}

void Drawer::visit(FreeCurve *freeCurve) {

	QPen pen(freeCurve->getColor());
	pen.setWidth(freeCurve->getWidth());
	
	QPen oldPen = painter.pen();

	painter.setPen(pen);

	if (freeCurve->getSize() == 0) {
	
		painter.setPen(oldPen);
		return;
	}
	else if (freeCurve->getSize() == 1) {
	
		painter.drawPoint(*freeCurve->getPoint(0));
	}
	else {
	
		QPainterPath path;
		path.moveTo(*freeCurve->getPoint(0));

		for (int i = 1; i < freeCurve->getSize(); i++) {

			path.lineTo(*freeCurve->getPoint(i));
		}

		painter.drawPath(path);
	}

	painter.setPen(oldPen);
}


void Drawer::visit(HighlightedFreeCurve *highlightedFreeCurve) {
	
	QColor color = highlightedFreeCurve->getColor();
	color.setAlpha(highlightedFreeCurve->getAlpha());

	QPen pen(color);
	pen.setWidth(highlightedFreeCurve->getWidth());

	QPen oldPen = painter.pen();

	painter.setPen(pen);

	if (highlightedFreeCurve->getSize() == 0) {

		painter.setPen(oldPen);
		return;
	}
	else if (highlightedFreeCurve->getSize() == 1) {

		painter.drawPoint(*highlightedFreeCurve->getPoint(0));
	}
	else {

		QPainterPath path;
		path.moveTo(*highlightedFreeCurve->getPoint(0));

		for (int i = 1; i < highlightedFreeCurve->getSize(); i++) {

			path.lineTo(*highlightedFreeCurve->getPoint(i));
		}

		painter.drawPath(path);
	}

	painter.setPen(oldPen);
}


void Drawer::visit(LineSegment *lineSegment) {

	QPen pen(lineSegment->getColor());
	pen.setWidth(lineSegment->getWidth());

	QPen oldPen = painter.pen();

	painter.setPen(pen);


	painter.drawLine(lineSegment->getStart(), lineSegment->getEnd());

	painter.setPen(oldPen);
}

void Drawer::visit(ArrowLineSegment *arrowLineSegment) {


	QPen pen(arrowLineSegment->getColor());
	pen.setWidth(arrowLineSegment->getWidth());

	QPen oldPen = painter.pen();

	painter.setPen(pen);

	double angle = math::getAbsAngle(arrowLineSegment->getStart().x(), arrowLineSegment->getStart().y(),
		arrowLineSegment->getEnd().x(), arrowLineSegment->getEnd().y());
	double dis = math::getDistance(arrowLineSegment->getStart().x(), arrowLineSegment->getStart().y(),
		arrowLineSegment->getEnd().x(), arrowLineSegment->getEnd().y()) - (3 * arrowLineSegment->getWidth());

	double newEndX, newEndY;
	math::rotate(angle, arrowLineSegment->getStart().x(), arrowLineSegment->getStart().y(),
		arrowLineSegment->getStart().x() + dis, arrowLineSegment->getStart().y(), newEndX, newEndY);

	painter.drawLine(arrowLineSegment->getStart(), QPoint(newEndX, newEndY));

	QPoint p1, p2, p3;
	arrowLineSegment->getArrowPoints(p1, p2, p3);

	QPainterPath path;
	path.moveTo(p1);
	path.lineTo(p2);
	path.lineTo(p3);

	painter.fillPath(path, QBrush(arrowLineSegment->getColor()));
	

	painter.setPen(oldPen);
}

void Drawer::visit(Number *number) {

	QColor color = number->getColor();
	color.setAlpha(125);

	QBrush brush(color);
	QBrush oldBrush = painter.brush();
	painter.setBrush(brush);

	QPen pen(color);
	QPen oldPen = painter.pen();
	painter.setPen(pen);
	

	painter.drawEllipse(number->getPoint(), number->getWidth() / 2, number->getWidth() / 2);
	painter.setBrush(oldBrush);
	painter.setPen(oldPen);

	QFont font = painter.font();
	font.setPointSize(number->getWidth() / 2);
	painter.setFont(font);
	painter.setPen(QColor(255, 255, 255));
	painter.drawText(number->getPoint().x() - number->getWidth() / 2, number->getPoint().y() - number->getWidth() / 2,
		number->getWidth(), number->getWidth(), Qt::AlignVCenter | Qt::AlignHCenter, QString::number(number->getNumber()));
}


void Drawer::visit(Rect *rectangle) {

	QPen pen(rectangle->getColor());
	pen.setWidth(rectangle->getWidth());

	QPen oldPen = painter.pen();

	painter.setPen(pen);


	painter.drawRect(rectangle->getRect());

	painter.setPen(oldPen);
}

void Drawer::visit(Circle *circle) {

	QPen pen(circle->getColor());
	pen.setWidth(circle->getWidth());

	QPen oldPen = painter.pen();

	painter.setPen(pen);


	painter.drawEllipse(circle->getCenter(), circle->getRadius(), circle->getRadius());

	painter.setPen(oldPen);
}

void Drawer::visit(Triangle *triangle) {

	QPen pen(triangle->getColor());
	pen.setWidth(triangle->getWidth());

	QPen oldPen = painter.pen();

	painter.setPen(pen);


	painter.drawLine(triangle->getVertex1(), triangle->getVertex2());
	painter.drawLine(triangle->getVertex2(), triangle->getVertex3());
	painter.drawLine(triangle->getVertex3(), triangle->getVertex1());

	painter.setPen(oldPen);
}