

#ifndef _VISITOR_H
#define _VISITOR_H

class EntityList;
class FreeCurve;

class Visitor {

public:
	Visitor();
	virtual ~Visitor() = 0;

	virtual void visit(EntityList *entityList) {}
	virtual void visit(FreeCurve *freeCurve) = 0;


};

#endif //_VISITOR_H