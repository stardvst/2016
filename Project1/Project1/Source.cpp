#include <iostream>
#include "Rational.h"
using namespace std;

int main() {

	Rational r1(2, 4);
	cout << "Fraction 1:\n";
	r1.printFloating();
	r1.printRational();

	Rational r2(10, 12);
	cout << "\nFraction 2:\n";
	r2.printFloating();
	r2.printRational();

	Rational r3 = r1 + r2;
	cout << "\nAdded. Fraction 3:\n";;
	r3.printFloating();
	r3.printRational();

	Rational r4 = r1 - r2;
	cout << "\nSubtracted. Fraction 4:\n";
	r4.printFloating();
	r4.printRational();

	Rational r5 = r1*r2;
	cout << "\nMultiplied. Fraction 5:\n";
	r5.printFloating();
	r5.printRational();

	Rational r6 = r1 / r2;
	cout << "\nDivided. Fraction 6:\n";
	r6.printFloating();
	r6.printRational();

	system("pause");
	return 0;
}

