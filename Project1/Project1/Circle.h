#ifndef CIRCLE_H
#define CIRCLE_H

#include "TwoDimensionalShape.h"

class Circle :public TwoDimensionalShape {
public:
	explicit Circle(double);

	void setRadius(double);
	double getRadius() const;

	double getArea() const;
	void print() const;
private:
	double radius;
};

#endif // !CIRCLE_H