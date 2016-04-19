#include <iostream>
#include <cmath>
#include "Pyramid.h"
using std::cout;
using std::endl;


Pyramid::Pyramid(double l, double w, double h) {
	setLength(l);
	setWidth(w);
	setHeight(h);
}

void Pyramid::setLength(double l) {
	length = (l > 0 ? l : 1.0);
}

double Pyramid::getLength() const {
	return length;
}

void Pyramid::setWidth(double w) {
	width = (w > 0 ? w : 1.0);
}

double Pyramid::getWidth() const {
	return width;
}

void Pyramid::setHeight(double h) {
	height = (h > 0 ? h : 1.0);
}

double Pyramid::getHeight() const {
	return height;
}

double Pyramid::getArea() const {
	return getLength()*getWidth() + getLength()*sqrt((getWidth()*getWidth() / 4) +
		getHeight()*getHeight()) + getWidth()*sqrt((getLength()*getLength() / 4) +
			getHeight()*getHeight());
}

double Pyramid::getVolume() const {
	return (getLength()*getWidth()*getHeight()) / 3;
}
void Pyramid::print() const {
	cout << "Pyramid length: " << getLength() << endl
		<< "Pyramid width: " << getWidth() << endl
		<< "Pyramid height: " << getHeight() << endl
		<< "Pyramid surface area: " << getArea() << endl
		<< "Pyramid volume: " << getVolume() << endl;
}