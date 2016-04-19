#include <iostream>
#include "Square.h"
using std::cout;
using std::endl;


Square::Square(double s) {
	setSide(s);
}

void Square::setSide(double s) {
	side = (s > 0 ? s : 1.0);
}

double Square::getSide() const {
	return side;
}

double Square::getArea() const {
	return getSide() * getSide();
}

void Square::print() const {
	cout << "Square side: " << getSide() << endl
		<< "Square area: " << getArea() << endl;
}