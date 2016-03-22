#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"

class Rectangle {
public:
	Rectangle(Point, Point, Point, Point);

	Point getTopLeft() const;
	Point getTopRight() const;
	Point getBottomLeft() const;
	Point getBottomRight() const;

	double calculateWidth() const;
	double calculateHeight() const;
	double calculatePerimeter() const;
	double calculateArea() const;

	bool isSquare() const;

	void draw() const;
	char setFillCharacter() const;
	char setBorderCharacter() const;
	void scaleHeight(int);
	void scaleWidth(int);
	bool rotateTheRectangle();
	bool moveTheRectangle(int, int);
private:
	Point topLeft;
	Point topRight;
	Point bottomLeft;
	Point bottomRight;
};

#endif // !RECTANGLE_H
