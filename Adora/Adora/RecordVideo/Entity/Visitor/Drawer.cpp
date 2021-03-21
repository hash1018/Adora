

#include "Drawer.h"
#include <qpainter.h>
#include "RecordVideo/Entity/FreeCurve.h"

Drawer::Drawer(QPainter &painter)
	:painter(painter) {

}

Drawer::~Drawer() {

}

void Drawer::visit(FreeCurve *freeCurve) {

	QPen pen(freeCurve->getColor());
	pen.setWidth(freeCurve->getWidth());
	
	QPen oldPen = painter.pen();

	painter.setPen(pen);

	if (freeCurve->getSize() == 0) {
	
		painter.setPen(oldPen);
		return;
	}
	else if (freeCurve->getSize() == 1) {
	
		painter.drawPoint(*freeCurve->getPoint(0));
	}
	else {
	
		QPainterPath path;
		path.moveTo(*freeCurve->getPoint(0));

		for (int i = 1; i < freeCurve->getSize(); i++) {

			path.lineTo(*freeCurve->getPoint(i));
		}

		painter.drawPath(path);
	}

	painter.setPen(oldPen);
}