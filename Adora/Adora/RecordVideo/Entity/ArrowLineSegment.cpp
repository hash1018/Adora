

#include "ArrowLineSegment.h"
#include "Visitor/Visitor.h"
#include "Base/Math.h"

ArrowLineSegment::ArrowLineSegment(const QColor &color, int width, const QPoint &start, const QPoint &end)
	:LineSegment(color, width, start, end) {

}

ArrowLineSegment::~ArrowLineSegment() {

}

void ArrowLineSegment::accept(Visitor *visitor) {

	visitor->visit(this);
}

void ArrowLineSegment::getArrowPoints(QPoint &point1, QPoint &point2, QPoint &point3) {

	double x1, x2, x3, y1, y2, y3;
	double angle = math::getAbsAngle(start.x(), start.y(), end.x(), end.y());
	double arrowHeight = 3*this->width;
	double arrowBaseSize = 3 * this->width;


	math::rotate(angle, end.x(), end.y(), end.x(), end.y(), x1, y1);
	math::rotate(angle, end.x(), end.y(), end.x() - arrowHeight, end.y() + arrowBaseSize / 2.0, x2, y2);
	math::rotate(angle, end.x(), end.y(), end.x() - arrowHeight, end.y() - arrowBaseSize / 2.0, x3, y3);

	point1.setX(x1);
	point1.setY(y1);
	point2.setX(x2);
	point2.setY(y2);
	point3.setX(x3);
	point3.setY(y3);

}