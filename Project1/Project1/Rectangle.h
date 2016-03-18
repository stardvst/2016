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

private:
	Point topLeft, topRight, bottomLeft, bottomRight;
};

#endif // !RECTANGLE_H
