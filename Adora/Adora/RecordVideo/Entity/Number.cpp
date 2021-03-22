

#include "Number.h"
#include "Visitor/Visitor.h"

Number::Number(const QColor &color, int width, const QPoint &point)
	:Entity(color, width), point(point) {

}

Number::~Number() {


}

void Number::accept(Visitor *visitor) {

	visitor->visit(this);
}

