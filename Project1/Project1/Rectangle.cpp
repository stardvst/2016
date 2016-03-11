#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(double l, double w) {
	setLength(l);
	setWidth(w);
}

void Rectangle::setLength(double l) {
	if (l > 0.0 && l < 20.0) {
		length = l;
	}
	else {
		length = 1;
		std::cout << "Invalid length. Length set to 1." << '\n';
	}
}

void Rectangle::setWidth(double w) {
	if (w > 0.0 && w < 20.0) {
		width = w;
	}
	else {
		width = 1;
		std::cout << "Invalid width. WIdth set to 1." << '\n';
	}
}

double Rectangle::getLength() {
	return length;
}

double Rectangle::getWidth() {
	return width;
}

double Rectangle::perimeter() const {
	return 2 * (length + width);
}

double Rectangle::area() const {
	return length * width; 
}

Rectangle::~Rectangle() {}