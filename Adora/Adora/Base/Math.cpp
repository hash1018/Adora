
#include "Math.h"
#include <qpoint.h>
#include <math.h>

int math::toInt(double value) {

	if (value > 0) {

		return (int)(value + 0.5);
	}
	else if (value < 0) {

		return (int)(value - 0.5);
	}

	return 0;
}


int math::compare(double first, double second, double epsilon) {

	double takeAway = first - second;

	if (fabs(takeAway) < epsilon)
		return 0;

	if (takeAway > 0 && takeAway >= epsilon)
		return 1;

	if (takeAway < 0 && takeAway <= epsilon)
		return -1;

	return 2;
}

bool math::isBetween(double v, double bound1, double bound2, double tolerance) {

	if (math::compare(bound2, bound1) == 1) {
		if (v >= bound1 - tolerance && v <= bound2 + tolerance)
			return true;

	}
	else {
		if (v >= bound2 - tolerance && v <= bound1 + tolerance)
			return true;

	}
	return false;

}

bool math::checkPointLiesOnLine(const QPoint &point, const QPoint &start, const QPoint &end, double tolerance) {

	if (isBetween(point.x(), start.x(), end.x(), tolerance) == false || isBetween(point.y(), start.y(), end.y(), tolerance) == false)
		return false;

	if (compare(fabs(end.x() - start.x()), 0) == 0) // Vertical line. 
		return true;

	double angle = getAbsAngle(start.x(), start.y(), end.x(), end.y());
	double pointAngle = getAbsAngle(start.x(), start.y(), point.x(), point.y());

	double angle0X, angle0Y;
	rotate(360 - pointAngle, start.x(), start.y(), point.x(), point.y(), angle0X, angle0Y);


	double finalX, finalY;
	rotate(angle, start.x(), start.y(), angle0X, angle0Y, finalX, finalY);


	if (finalX - tolerance <= point.x() && finalX + tolerance >= point.x() &&
		finalY - tolerance <= point.y() && finalY + tolerance >= point.y())
		return true;

	return false;
}

bool math::checkPointLiesInsideRect(const QPoint &point, const QPoint &topLeft, const QPoint &bottomRight, double tolerance) {

	if (point.x() >= topLeft.x() - tolerance && point.x() <= bottomRight.x() + tolerance &&
		point.y() <= topLeft.y() + tolerance && point.y() >= bottomRight.y() - tolerance)
		return true;

	return false;
}

double math::getDistance(double x, double y, double x2, double y2) {

	double disX = fabs(x2 - x);
	double disY = fabs(y2 - y);

	double distance = sqrt(disX*disX + disY*disY);

	return distance;

}


double math::getAbsAngle(double centerX, double centerY, double anotherX, double anotherY) {

	double distanceX = fabs(anotherX - centerX);
	double distanceY = fabs(anotherY - centerY);

	double angle = atan2(distanceY, distanceX) * 180 / 3.1415926535897;

	if ((compare(anotherX, centerX) == 1 || compare(anotherX, centerX) == 0) &&
		(compare(anotherY, centerY) == 1 || compare(anotherY, centerY) == 0)) {
		angle = angle + 0;
		return angle;
	}

	if (compare(centerX, anotherX) == 1 && (compare(anotherY, centerY) == 1 || compare(anotherY, centerY) == 0)) {
		angle = 180 - angle;
		return angle;
	}

	if ((compare(centerX, anotherX) == 1 || compare(centerX, anotherX) == 0) && compare(centerY, anotherY) == 1) {
		angle = 180 + angle;
		return angle;
	}

	if (compare(anotherX, centerX) == 1 && compare(centerY, anotherY) == 1) {
		angle = 360 - angle;
		return angle;
	}

	return -1.0;
}

void math::rotate(double angle, double centerX, double centerY, double anotherX, double anotherY, double &appliedX, double &appliedY) {

	double cos_value = cos((angle*3.1415926535897) / 180);
	double sin_value = sin((angle*3.1415926535897) / 180);

	double tempX = anotherX - centerX;
	double tempY = anotherY - centerY;

	double tempX2 = cos_value*tempX - sin_value*tempY;
	double tempY2 = sin_value*tempX + cos_value*tempY;

	appliedX = tempX2 + centerX;
	appliedY = tempY2 + centerY;
}

double math::addAngle(double angle, double angle2) {

	double addedAngle = angle + angle2;

	if (addedAngle >= 360.0)
		addedAngle -= 360;
	else if (addedAngle < 0)
		addedAngle += 360;

	return addedAngle;
}