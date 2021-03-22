

#include "LineSegment.h"
#include "Visitor/Visitor.h"

LineSegment::LineSegment(const QColor &color, int width, const QPoint &start, const QPoint &end)
	:Entity(color, width), start(start), end(end) {

}

LineSegment::~LineSegment() {

}


void LineSegment::accept(Visitor *visitor) {

	visitor->visit(this);
}