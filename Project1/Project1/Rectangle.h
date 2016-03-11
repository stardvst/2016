#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
public:
	Rectangle(double = 1, double = 1);
	void setLength(double);
	void setWidth(double);
	double getLength();
	double getWidth();
	double perimeter() const;
	double area() const;
	~Rectangle();
private:
	double length;
	double width;
};

#endif // !RECTANGLE_H
