#include <iostream>
#include "Rational.h"

Rational::Rational(int n, int d) {
	int low, high;
	if (n > d) {
		low = d;
		high = n;
	}
	else {
		high = d;
		low = n;
	}
	for (int i = low; i > 0; i--) {
		if ((low%i == 0) && (high%i == 0)) {
			n /= i;
			d /= i;
		}
	}
	numerator = n;
	denominator = d;
}

int Rational::getNumerator() const {
	return numerator;
}

int Rational::getDenominator() const {
	return denominator;
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