#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(Point TLeft, Point TRight, Point BLeft, Point BRight) {
	if (TLeft.getX() >= 0 && TLeft.getX() <= 20.0 &&
		TLeft.getY() >= 0 && TLeft.getY() <= 20.0 &&
		TRight.getX() >= 0 && TRight.getX() <= 20.0 &&
		TRight.getY() >= 0 && TRight.getY() <= 20.0 &&
		BLeft.getX() >= 0 && BLeft.getX() <= 20.0 &&
		BLeft.getY() >= 0 && BLeft.getY() <= 20.0 &&
		BRight.getX() >= 0 && BRight.getX() <= 20.0 &&
		BLeft.getY() >= 0 && BLeft.getY() <= 20.0) {
		topLeft = TLeft;
		topRight = TRight;
		bottomLeft = BLeft;
		bottomRight = BRight;
	}
	else {
		std::cout << "x and y coordinates should be >= 0 && <= 20.\n";
	}

	if (TLeft.getX() != BLeft.getX()) {
		std::cout << "Top left and bottom left must have the same x value.\n";
	}

	if (TRight.getX() != BRight.getX()) {
		std::cout << "Top right and bottom right must have the same x value.\n";
	}
}

Point Rectangle::getTopLeft() const {
	return topLeft;
}

Point Rectangle::getTopRight() const {
	return topRight;
}

Point Rectangle::getBottomLeft() const {
	return bottomLeft;
}

Point Rectangle::getBottomRight() const {
	return bottomRight;
}

double Rectangle::calculateWidth() const {
	Point TRight = this->getTopRight();
	Point TLeft = this->getTopLeft();
	return TRight.getX() - TLeft.getX();
}

double Rectangle::calculateHeight() const {
	Point TRight = this->getTopRight();
	Point BRight = this->getBottomRight();
	return TRight.getY() - BRight.getY();
}

double Rectangle::calculatePerimeter() const {
	return (this->calculateHeight() * 2 + this->calculateWidth() * 2);
}

double Rectangle::calculateArea() const {
	return (this->calculateHeight() * this->calculateWidth());
}

bool Rectangle::isSquare() const {
	if (this->calculateHeight() == this->calculateWidth()) {
		return true;
	}
	else {
		return false;
	}
}

void Rectangle::draw() const {
	char fill = setFillCharacter();
	char border = setPerimeterCharacter();
	int box[25][25];

	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			box[i, j] = ' ';
		}
	}

	for (int i = 25 - topLeft.getY(); i <= 24 - bottomLeft.getX(); i++) {
		for (int j = topLeft.getX(); j <= topRight.getX(); j++) {
			if (i == 25 - topLeft.getY() || i == 24 - bottomLeft.getX() ||
				j == topLeft.getX() || j == topRight.getX()) {
				box[i, j] = border;
			} else {
				box[i, j] = fill;
			}
		}
	}
}