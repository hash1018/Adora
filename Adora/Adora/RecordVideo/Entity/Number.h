

#ifndef _NUMBER_H
#define _NUMBER_H

#include "Entity.h"
#include <qpoint.h>

class Number : public Entity {

private:
	QPoint point;

public:
	Number(const QColor &color, int width, const QPoint &point);
	~Number();

	virtual void accept(Visitor *visitor);

	void setPoint(const QPoint &point) { this->point = point; }
	inline const QPoint& getPoint() const { return this->point; }
};


#endif //_NUMBER_H