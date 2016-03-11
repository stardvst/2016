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

void add(Rational rat) {
	
}

void Rational::reduce(int n, int d) {
	int i = 2;
	while (n % i == 0 && d % i == 0) {
		n /= i;
		d /= i;
		i++;
	}
}