

#include "Number.h"
#include "Visitor/Visitor.h"

Number::Number(const QColor &color, int width, const QPoint &point, int number)
	:Entity(color, width), point(point), number(number) {

}

Number::~Number() {


}

void Number::accept(Visitor *visitor) {

	visitor->visit(this);
}

