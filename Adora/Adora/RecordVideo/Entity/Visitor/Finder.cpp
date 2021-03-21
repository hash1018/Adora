

#include "Finder.h"
#include "RecordVideo/Entity/FreeCurve.h"
#include <qrect.h>
#include "Base/Math.h"

Finder::Finder(const QPoint &point, bool &foundEntity)
	:point(point), foundEntity(foundEntity) {

}

Finder::~Finder() {

}

void Finder::visit(FreeCurve *freeCurve) {

	int width = freeCurve->getWidth();

	if (freeCurve->getSize() == 0)
		return;

	else if (freeCurve->getSize() == 1) {
	
		QRect rect(QPoint(this->point.x() - width, this->point.y() - width),
			QPoint(point.x() + width, point.y() + width));

		if (math::checkPointLiesInsideRect(*freeCurve->getPoint(0), QPoint(point.x() - width, point.y() - width),
			QPoint(point.x() + width, point.y() + width), width) == true) {
		
			this->foundEntity = true;
			return;
		}
	}
	else {
	
		QPoint temp = *freeCurve->getPoint(0);

		for (int i = 1; i < freeCurve->getSize(); i++) {

			if (math::checkPointLiesOnLine(point, temp, *freeCurve->getPoint(i), width) == true) {

				this->foundEntity = true;
				return;
			}

			temp = *freeCurve->getPoint(i);
		}
	}

	this->foundEntity = false;
}