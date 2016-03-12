#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
public:
	Rectangle();
	void setRectangle();
	double calculateLength() const;
	double calculateWidth() const;
	double calculatePerimeter() const;
	double calculateArea() const;
	bool isSquare();
	~Rectangle();
private:
	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;
	int x4;
	int y4;
};

#endif // !RECTANGLE_H
