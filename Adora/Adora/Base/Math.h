
#ifndef _MATH_H
#define _MATH_H

class QPoint;

namespace math {

	int toInt(double value);
	int compare(double first, double second, double epsilon = 0.0001);
	bool isBetween(double v, double bound1, double bound2, double tolerance);
	bool checkPointLiesOnLine(const QPoint &point, const QPoint &start, const QPoint &end, double tolerance);
	bool checkPointLiesInsideRect(const QPoint &point, const QPoint &topLeft, const QPoint &bottomRight, double tolerance);

	double getDistance(double x, double y, double x2, double y2);
	double getAbsAngle(double centerX, double centerY, double anotherX, double anotherY);
	void rotate(double angle, double centerX, double centerY, double anotherX, double anotherY, double &appliedX, double &appliedY);
	double addAngle(double angle, double angle2);

};

#endif //_MATH_H