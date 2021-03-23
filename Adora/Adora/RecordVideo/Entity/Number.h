

#ifndef _NUMBER_H
#define _NUMBER_H

#include "Entity.h"
#include <qpoint.h>

class Number : public Entity {

private:
	QPoint point;
	int number;

public:
	Number(const QColor &color, int width, const QPoint &point, int number);
	~Number();

	virtual void accept(Visitor *visitor);

	void setPoint(const QPoint &point) { this->point = point; }
	void setNumber(int number) { this->number = number; }

	inline const QPoint& getPoint() const { return this->point; }
	inline int getNumber() const { return this->number; }
};


#endif //_NUMBER_H