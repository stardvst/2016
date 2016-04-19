#ifndef SQUARE_H
#define SQUARE_H

#include "TwoDimensionalShape.h"

class Square :public TwoDimensionalShape {
public:

	explicit Square(double);

	void setSide(double);
	double getSide() const;

	double getArea() const;
	void print() const;

	//void draw() const;

private:
	double side;
};

#endif // !SQUARE_H