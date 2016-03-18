#include <iostream>
#include "Rectangle.h"
using namespace std;

int main() {

	Point p1(0, 3);		Point p2(2, 3);
	Point p3(0, 0);		Point p4(2, 0);
	Rectangle r1(p1, p2, p3, p4);
	cout << "Height: " << r1.calculateHeight() << '\n';
	cout << "Width: " << r1.calculateWidth() << '\n';
	cout << "Area: " << r1.calculateArea() << '\n';
	cout << "Is square? " << (r1.isSquare() ? "yes\n\n" : "no\n\n");

	Point p5(0, 2);		Point p6(2, 2);
	Point p7(0, 0);		Point p8(2, 0);
	Rectangle r2(p5, p6, p7, p8);
	cout << "Height: " << r2.calculateHeight() << '\n';
	cout << "Width: " << r2.calculateWidth() << '\n';
	cout << "Area: " << r2.calculateArea() << '\n';
	cout << "Is square? " << (r2.isSquare() ? "yes\n" : "no\n");

	system("pause");
	return 0;
}

