

#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "Entity.h"
#include <qpoint.h>

class Triangle : public Entity {

protected:
	QPoint vertex1;
	QPoint vertex2;
	QPoint vertex3;

public:
	Triangle(const QColor &color, int width, const QPoint &vertex1, const QPoint &vertex2, const QPoint &vertex3);
	~Triangle();

	virtual void accept(Visitor *visitor);

public:
	void setVertex1(const QPoint &vertex1) { this->vertex1 = vertex1; }
	void setVertex2(const QPoint &vertex2) { this->vertex2 = vertex2; }
	void setVertex3(const QPoint &vertex3) { this->vertex3 = vertex3; }

	inline const QPoint& getVertex1() const { return this->vertex1; }
	inline const QPoint& getVertex2() const { return this->vertex2; }
	inline const QPoint& getVertex3() const { return this->vertex3; }

};

#endif //_TRIANGLE_H