

#include "Rectangle.h"
#include "Visitor/Visitor.h"

Rect::Rect(const QColor &color, int width, const QRect &rect)
	:Entity(color, width), rect(rect) {

}

Rect::~Rect() {

}

void Rect::accept(Visitor *visitor) {

	visitor->visit(this);
}