#include "Point.h"

Point::Point(int ax, int ay) {
	x = ax;
	y = ay;
}

void Point::setX(int ax) {
	x = ax;
}

void Point::setY(int ay) {
	y = ay;
}

int Point::getX() const {
	return x;
}

int Point::getY() const {
	return y;
}