

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

};

#endif //_DRAWER_H
