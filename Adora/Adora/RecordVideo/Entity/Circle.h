

#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Entity.h"
#include <qpoint.h>

class Circle : public Entity {

protected:
	QPoint center;
	int radius;

public:
	Circle(const QColor &color, int width, const QPoint &center, int radius);
	~Circle();

	virtual void accept(Visitor *visitor);

public:
	void setCenter(const QPoint &center) { this->center = center; }
	void setRadius(int radius) { this->radius = radius; }

	inline const QPoint& getCenter() const { return this->center; }
	inline int getRadius() const { return this->radius; }


};

#endif //_CIRCLE_H