#ifndef THREEDIMENSIONALSHAPE_H
#define THREEDIMENSIONALSHAPE_H

#include "Shape.h"

class ThreeDimensionalShape :public Shape {
public:
	virtual double getArea() const = 0;
	virtual double getVolume() const = 0;
};

#endif // !THREEDIMENSIONALSHAPE_H