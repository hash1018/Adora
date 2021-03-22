

#include "ArrowLineSegment.h"
#include "Visitor/Visitor.h"

ArrowLineSegment::ArrowLineSegment(const QColor &color, int width, const QPoint &start, const QPoint &end)
	:LineSegment(color, width, start, end) {

}

ArrowLineSegment::~ArrowLineSegment() {

}

void ArrowLineSegment::accept(Visitor *visitor) {

	visitor->visit(this);
}