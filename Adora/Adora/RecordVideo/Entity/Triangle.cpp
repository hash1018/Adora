

#include "Triangle.h"
#include "Visitor/Visitor.h"

Triangle::Triangle(const QColor &color, int width, const QPoint &vertex1, const QPoint &vertex2, const QPoint &vertex3)
	:Entity(color, width), vertex1(vertex1), vertex2(vertex2), vertex3(vertex3) {

}

Triangle::~Triangle() {


}

void Triangle::accept(Visitor *visitor) {

	visitor->visit(this);
}