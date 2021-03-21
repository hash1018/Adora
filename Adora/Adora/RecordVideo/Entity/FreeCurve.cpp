

#include "FreeCurve.h"
#include "Visitor/Visitor.h"

FreeCurve::FreeCurve(const QColor &color, int width)
	:Entity(color, width) {

}

FreeCurve::~FreeCurve() {

	while (!this->points.isEmpty())
		delete this->points.takeFirst();
}

void FreeCurve::accept(Visitor *visitor) {

	visitor->visit(this);
}


void FreeCurve::append(const QPoint &point) {

	QPoint *appendedPoint = new QPoint(point);

	this->points.append(appendedPoint);
}