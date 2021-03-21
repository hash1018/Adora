

#ifndef _FREECURVE_H
#define _FREECURVE_H

#include "Entity.h"
#include <qlist.h>
#include <qpoint.h>

class FreeCurve : public Entity {

protected:
	QList<QPoint*> points;

public:
	FreeCurve(const QColor &color, int width);
	~FreeCurve();

	virtual void accept(Visitor *visitor);

public:
	void append(const QPoint &point);

public:
	inline const QPoint* getPoint(int index) { return this->points.at(index); }
	inline int getSize() const { return this->points.size(); }
};

#endif //_FREECURVE_H