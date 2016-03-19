#include <iostream>
#include "Rational.h"

Rational::Rational(int n, int d) {
	if (d == 0) {
		std::cout << "Divison by zero not allowed.\nDenemonator defaulted to 1.\n";
		d = 1;
	}
	int low = (n > d) ? d : n;
	if (low < 0) {
		low = -low;
	}
	for (int i = low; i > 1; i--) {
		if ((n % i == 0) && (d % i == 0)) {
			n /= i;
			d /= i;
		}
	}
	numerator = n;
	denominator = d;
}

Rational Rational::add(const Rational &fraction) const {
	return Rational(numerator*fraction.denominator + denominator*fraction.numerator,
		denominator*fraction.denominator);
}

Rational Rational::subtract(const Rational &fraction) const {
	return Rational(numerator*fraction.denominator - denominator*fraction.numerator,
		denominator*fraction.denominator);
}

Rational Rational::multiply(const Rational &fraction) const {
	return Rational(numerator * fraction.numerator, denominator * fraction.denominator);
}

Rational Rational::divide(const Rational &fraction) const {
	return Rational(numerator * fraction.denominator, denominator * fraction.numerator);
}

void Rational::printRational() const {
	std::cout << "Fraction is " << numerator << "/" << denominator << "\n";
}

void Rational::printFloating() const {
	std::cout << "In floating-point format: " << (double)numerator / denominator << "\n";
}