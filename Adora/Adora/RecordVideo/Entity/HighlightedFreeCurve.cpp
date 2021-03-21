

#include "HighlightedFreeCurve.h"
#include "Visitor/Visitor.h"

HighlightedFreeCurve::HighlightedFreeCurve(const QColor &color, int width, int alpha)
	:FreeCurve(color, width), alpha(alpha) {


}

HighlightedFreeCurve::~HighlightedFreeCurve() {

}

void HighlightedFreeCurve::accept(Visitor *visitor) {

	visitor->visit(this);
}