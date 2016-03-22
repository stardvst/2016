#include <iostream>
#include "Rectangle.h"
using namespace std;

int main() {

	Point p1(5, 5);		Point p2(10, 5);
	Point p3(5, 2);		Point p4(10, 2);
	Rectangle r1(p1, p2, p3, p4);
	cout << "Height: " << r1.calculateHeight() << '\n';
	cout << "Width: " << r1.calculateWidth() << '\n';
	cout << "Area: " << r1.calculateArea() << '\n';
	cout << "Is square? " << (r1.isSquare() ? "yes\n\n" : "no\n\n");
	cout << "Drawing a rectangle:\n";
	r1.draw();

	cout << endl << "Scaling height:\n";
	r1.scaleHeight(3);
	r1.draw();

	cout << endl << "Scaling width:\n";
	r1.scaleWidth(3);
	r1.draw();

	cout << endl << "Rotating the rectangle:\n";
	r1.rotateTheRectangle();
	r1.draw();

	cout << endl << "Moving the rectangle:\n";
	r1.moveTheRectangle(-25,-25);
	r1.draw();

	/*Point p5(0, 2);		Point p6(2, 2);
	Point p7(0, 0);		Point p8(2, 0);
	Rectangle r2(p5, p6, p7, p8);
	cout << "Height: " << r2.calculateHeight() << '\n';
	cout << "Width: " << r2.calculateWidth() << '\n';

	cout << "Area: " << r2.calculateArea() << '\n';
	cout << "Is square? " << (r2.isSquare() ? "yes\n" : "no\n");
	r2.draw();*/

	system("pause");
	return 0;
}

