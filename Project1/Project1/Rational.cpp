#include <iostream>
#include "Rational.h"

Rational::Rational(int n, int d) {
	int sign = 1, gcd, low;
	// determine the sign
	if (n < 0 && d < 0) {
		n = -n; d = -d;
	}
	else if (n < 0) {
		n = -n;
		sign = -1;
	}
	else if (d < 0) {
		d = -d;
		sign = -1;
	}
	// if denom is 0
	if (d == 0) {
		std::cout << "Divison by zero not allowed.\nDenemonator defaulted to 1.\n";
		d = 1;
	} 
	// find gcd
	if (n < d) {
		low = n;
		gcd = d;
	}
	else {
		low = d;
		gcd = n;
	}
	while (low != 0) {
		int temp = gcd % low;
		gcd = low;
		low = temp;
	}
	// divide original values by their gcd 
	numerator = (n / gcd) * sign; 
	denominator = d / gcd;
}

Rational Rational::operator+(const Rational &fraction) const {
	return Rational(numerator*fraction.denominator + denominator*fraction.numerator,
		denominator*fraction.denominator);
}

Rational Rational::operator-(const Rational &fraction) const {
	return Rational(numerator*fraction.denominator - denominator*fraction.numerator,
		denominator*fraction.denominator);
}

Rational Rational::operator*(const Rational &fraction) const {
	return Rational(numerator * fraction.numerator, denominator * fraction.denominator);
}

Rational Rational::operator/(const Rational &fraction) const {
	return Rational(numerator * fraction.denominator, denominator * fraction.numerator);
}

bool Rational::operator==(const Rational &fraction) const {
	if (fraction.numerator == numerator &&
		fraction.denominator == denominator) {
		return true;
	}
	else {
		return false;
	}
}

bool Rational::operator!=(const Rational &fraction) const {
	return !(fraction == *this);
}

bool Rational::operator<(const Rational &fraction) const {
	if (numerator*fraction.denominator < denominator*fraction.numerator) {
		return true;
	}
	else {
		return false;
	}

}

bool Rational::operator>(const Rational &fraction) const {
	return fraction < *this;
}

bool Rational::operator<=(const Rational &fraction) const {
	return !(fraction < *this);
}

bool Rational::operator>=(const Rational &fraction) const {
	return !(*this < fraction);
}

void Rational::printRational() const {
	std::cout << "Fraction is " << numerator << "/" << denominator << "\n";
}

void Rational::printFloating() const {
	std::cout << "In floating-point format: " << (double)numerator / denominator << "\n";
}