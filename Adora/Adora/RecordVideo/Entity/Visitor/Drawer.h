

#ifndef _DRAWER_H
#define _DRAWER_H

#include "Visitor.h"

class QPainter;

class Drawer : public Visitor {


private:
	QPainter &painter;

public:
	Drawer(QPainter &painter);
	~Drawer();

	virtual void visit(FreeCurve *freeCurve);
	virtual void visit(HighlightedFreeCurve *highlightedFreeCurve);
	virtual void visit(LineSegment *lineSegment);
	virtual void visit(ArrowLineSegment *arrowLineSegment);
	virtual void visit(Number *number);
	virtual void visit(Rect *rectangle);
	virtual void visit(Circle *circle);
	virtual void visit(Triangle *triangle);
};

#endif //_DRAWER_H
