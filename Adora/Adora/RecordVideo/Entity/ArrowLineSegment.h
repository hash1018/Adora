

#ifndef _ARROWLINESEGMENT_H
#define _ARROWLINESEGMENT_H

#include "LineSegment.h"

class ArrowLineSegment : public LineSegment {

public:
	ArrowLineSegment(const QColor &color, int width, const QPoint &start, const QPoint &end);
	~ArrowLineSegment();

	virtual void accept(Visitor *visitor);

	void getArrowPoints(QPoint &point1, QPoint &point2, QPoint &point3);

};

#endif //_ARROWLINESEGMENT_H