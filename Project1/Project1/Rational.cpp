#include <iostream>
#include "Rational.h"

Rational::Rational(int n, int d) {
	reduce(n, d);
	numerator = n;
	denominator = d;
}

Rational::~Rational() {};

int Rational::getNumerator() {
	return numerator;
}

int Rational::getDenominator() {
	return denominator;
}

void Rational::add(Rational rat) {
	
}

void Rational::subtract(Rational rat) {

}

void Rational::multiply(Rational fraction) {
	numerator *= fraction.getNumerator;
	denominator *= fraction.getDenominator;
	reduce(numerator, denominator);
}

void Rational::divide(Rational fraction) {
	numerator *= fraction.getDenominator;
	denominator *= fraction.getNumerator;
	reduce(numerator, denominator);
}

void Rational::printRational() const {
	std::cout << "Fraction is " << numerator << "/" << denominator << "\n";
}

void Rational::printFloating() const {
	std::cout << "In floating-point format: " << numerator / denominator << "\n";
}

void Rational::reduce(int n, int d) {
	int i = 2;
	while (n % i == 0 && d % i == 0) {
		n /= i;
		d /= i;
		i++;
	}
}