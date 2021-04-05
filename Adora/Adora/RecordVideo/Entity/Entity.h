
#ifndef _ENTITY_H
#define _ENTITY_H

#include <qcolor.h>
class Visitor;

class Entity {
	
protected:
	QColor color;
	int width;
	
public:
	Entity(const QColor &color, int width);
	virtual ~Entity() = 0;

	virtual void accept(Visitor *visitor) = 0;

public:
	void setColor(const QColor &color) { this->color = color; }
	void setWidth(int width) { this->width = width; }

public:
	inline const QColor& getColor() const { return this->color; }
	inline int getWidth() const { return this->width; }
};

#endif //_ENTITY_H