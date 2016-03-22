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

	if (TLeft.getY() != TRight.getY()) {
		std::cout << "Top left and top right must have the same y value.\n";
	}

	if (BLeft.getY() != BRight.getY()) {
		std::cout << "Bottom left and bottom right must have the same y value.\n";
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
	const char fill = setFillCharacter();
	const char border = setBorderCharacter();
	char box[26][26];

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			box[i][j] = ' ';
			box[i][0] = '|';
			box[25][j] = '-';
		}
	}

	box[0][0] = '^';
	box[25][0] = '+';
	box[25][25] = '>';

	for (int i = 25 - topLeft.getY(); i < 25 - bottomLeft.getY(); i++) {
		for (int j = topLeft.getX() + 1; j < topRight.getX() + 1; j++) {
			if ((i == (25 - topLeft.getY())) || (i == (24 - bottomLeft.getY())) ||
				(j == topLeft.getX() + 1) || (j == topRight.getX())) {
				box[i][j] = border;
			}
			else {
				box[i][j] = fill;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			std::cout << box[i][j];
		}
		std::cout << std::endl;
	}
}

void Rectangle::scaleHeight(int coordinate) {
	topLeft.setY(topLeft.getY() + coordinate);
	topRight.setY(topRight.getY() + coordinate);
}

void Rectangle::scaleWidth(int coordinate) {
	topRight.setX(topRight.getX() + coordinate);
	bottomRight.setX(bottomRight.getX() + coordinate);
}

void Rectangle::rotateTheRectangle() {
	if ((bottomLeft.getX() + (topRight.getY() - bottomRight.getY()) > 25) ||
		(bottomLeft.getY() + (topRight.getX() - topLeft.getX() > 25))) {
	}
	else {
		bottomLeft.setX(bottomRight.getX());
		bottomLeft.setY(bottomRight.getY());
		bottomRight.setX(bottomLeft.getX() + (topRight.getY() - bottomRight.getY()));
		bottomRight.setY(bottomLeft.getY());
		topLeft.setY(bottomLeft.getY() + (topRight.getX() - topLeft.getX()));
		topLeft.setX(bottomLeft.getX());
		topRight.setX(bottomRight.getX());
		topRight.setY(topLeft.getY());
	}
}

void Rectangle::moveTheRectangle(int xChange, int yChange) {
	if ((topRight.getX() + xChange > 25) || (topRight.getY() + yChange > 25) ||
		(bottomLeft.getX() + xChange) || (bottomLeft.getY() + yChange)) {
		std::cout << "Coordinates are out of borders. The rectangle won't be moved.\n\n";
	}
	else {
		bottomLeft.setX(bottomLeft.getX() + xChange);
		bottomLeft.setY(bottomLeft.getY() + yChange);
		bottomRight.setX(bottomRight.getX() + xChange);
		bottomRight.setY(bottomRight.getY() + yChange);
		topLeft.setX(topLeft.getX() + xChange);
		topLeft.setY(topLeft.getY() + yChange);
		topRight.setX(topRight.getX() + xChange);
		topRight.setY(topRight.getY() + yChange);
	}
}

char Rectangle::setFillCharacter() const {
	char fill;
	std::cout << "Enter a fill character: ";
	std::cin >> fill;
	return fill;
}

char Rectangle::setBorderCharacter() const {
	char border;
	std::cout << "Enter a border character: ";
	std::cin >> border;
	return border;
}