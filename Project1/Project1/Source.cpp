#include <iostream>
#include "Rational.h"
using namespace std;

int main() {
	
	Rational r1(2,4);
	cout << "Fraction 1:\n";
	r1.printFloating();
	r1.printRational();

	Rational r2(10,12);
	cout << "\nFraction 2:\n";
	r2.printFloating();
	r2.printRational();

	Rational r3 = r1.add(r2);
	cout << "\nAdded. Fraction 3:\n";;
	r3.printFloating();
	r3.printRational();

	Rational r4 = r1.subtract(r2);
	cout << "\nSubtracted. Fraction 4:\n";
	r4.printFloating();
	r4.printRational();

	Rational r5 = r1.multiply(r2);
	cout << "\nMultiplied. Fraction 5:\n";
	r5.printFloating();
	r5.printRational();

	Rational r6 = r1.divide(r2);
	cout << "\nDivided. Fraction 6:\n";
	r6.printFloating();
	r6.printRational();

	/*Point p1(0, 3);		Point p2(2, 3);
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
	cout << "Is square? " << (r2.isSquare() ? "yes\n" : "no\n");*/

	system("pause");
	return 0;
}

