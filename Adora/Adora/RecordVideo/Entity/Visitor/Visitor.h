

#ifndef _VISITOR_H
#define _VISITOR_H

class EntityList;
class FreeCurve;
class HighlightedFreeCurve;
class LineSegment;
class ArrowLineSegment;

class Visitor {

public:
	Visitor();
	virtual ~Visitor() = 0;

	virtual void visit(EntityList *entityList) {}
	virtual void visit(FreeCurve *freeCurve) = 0;
	virtual void visit(HighlightedFreeCurve *highlightedFreeCurve) = 0;
	virtual void visit(LineSegment *lineSegment) = 0;
	virtual void visit(ArrowLineSegment *arrowLineSegment) = 0;


};

#endif //_VISITOR_H