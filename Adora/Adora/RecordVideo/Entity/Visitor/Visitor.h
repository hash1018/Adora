

#ifndef _VISITOR_H
#define _VISITOR_H


class EntityList;
class FreeCurve;
class HighlightedFreeCurve;
class LineSegment;
class ArrowLineSegment;
class Number;
class Rect;
class Circle;
class Triangle;


class Visitor {

public:
	Visitor();
	virtual ~Visitor() = 0;

	virtual void visit(EntityList *entityList) {}
	virtual void visit(FreeCurve *freeCurve) = 0;
	virtual void visit(HighlightedFreeCurve *highlightedFreeCurve) = 0;
	virtual void visit(LineSegment *lineSegment) = 0;
	virtual void visit(ArrowLineSegment *arrowLineSegment) = 0;
	virtual void visit(Number *number) = 0;
	virtual void visit(Rect *rectangle) = 0;
	virtual void visit(Circle *circle) = 0;
	virtual void visit(Triangle *triangle) = 0;


};

#endif //_VISITOR_H