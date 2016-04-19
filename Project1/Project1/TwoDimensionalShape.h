#ifndef TWODIMENSIONALSHAPE_H
#define TWODIMENSIONALSHAPE_H

#include "Shape.h"

class TwoDimensionalShape :public Shape {
public:
	virtual double getArea() const = 0;
};

#endif // !TWODIMENSIONALSHAPE_H
