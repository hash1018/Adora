

#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "Entity.h"
#include <qrect.h>
class Rect : public Entity {

protected:
	QRect rect;

public:
	Rect(const QColor &color, int width, const QRect &rect);
	~Rect();

	virtual void accept(Visitor *visitor);

public:
	void setRect(const QRect &rect) { this->rect = rect; }

	inline const QRect& getRect() const { return this->rect; }
};


#endif //_RECTANGLE_H