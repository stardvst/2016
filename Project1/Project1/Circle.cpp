#include <iostream>
#include "Circle.h"
using std::cout;
using std::endl;

#define PI 3.14

Circle::Circle(double r) {
	setRadius(r);
}

void Circle::setRadius(double r) {
	radius = (r > 0 ? r : 1.0);
}

double Circle::getRadius() const {
	return radius;
}

double Circle::getArea() const {
	return PI * getRadius() * getRadius();
}

void Circle::print() const {
	cout << "Circle radius: " << getRadius() << endl
		<< "Circle area: " << getArea() << endl;
}
