#ifndef PYRAMID_H
#define PYRAMID_H

#include "ThreeDimensionalShape.h"

class Pyramid :public ThreeDimensionalShape {
public:
	Pyramid(double, double, double);

	void setLength(double);
	double getLength() const;

	void setWidth(double);
	double getWidth() const;

	void setHeight(double);
	double getHeight() const;

	double getArea() const;
	double getVolume() const;
	void print() const;

private:
	double length;
	double width;
	double height;
};

#endif // !PYRAMID_H