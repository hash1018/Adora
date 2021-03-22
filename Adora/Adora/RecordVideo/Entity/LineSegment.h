

#ifndef _LINESEGMENT_H
#define _LINESEGMENT_H

#include "Entity.h"
#include <qpoint.h>
class LineSegment : public Entity {

protected:
	QPoint start;
	QPoint end;

public:
	LineSegment(const QColor &color, int width, const QPoint &start, const QPoint &end);
	~LineSegment();

	virtual void accept(Visitor *visitor);

	void setStart(const QPoint &start) { this->start = start; }
	void setEnd(const QPoint &end) { this->end = end; }

	inline const QPoint& getStart() const { return this->start; }
	inline const QPoint& getEnd() const { return this->end; }

};


#endif //_LINESEGMENT_H