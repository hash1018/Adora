

#ifndef _FINDER_H
#define _FINDER_H

#include "Visitor.h"
#include <qpoint.h>

class Finder : public Visitor {

private:
	QPoint point;
	bool &foundEntity;

public:
	Finder(const QPoint &point, bool &foundEntity);
	~Finder();

	virtual void visit(FreeCurve *freeCurve);

};

#endif //_FINDER_H