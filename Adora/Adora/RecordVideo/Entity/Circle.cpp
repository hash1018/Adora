

#include "Circle.h"
#include "Visitor/Visitor.h"

Circle::Circle(const QColor &color, int width, const QPoint &center, int radius)
	:Entity(color, width), center(center), radius(radius) {

}

Circle::~Circle() {

}

void Circle::accept(Visitor *visitor) {

	visitor->visit(this);
}