#include <string>
#include "Polynomial.h"
using std::string;

int Polynomial::quantity = 0;
string Polynomial::terms[] = { "" };

Polynomial::Polynomial(int c, int e) {
	coefficient = (c != 0 ? c : 1);
	exponent = (e != 0 ? e : 1);
	terms[quantity++] = coefficient + "x" + exponent;
}

Polynomial::Polynomial(const Polynomial &copy) {
	coefficient = copy.coefficient;
	exponent = copy.exponent;
	terms[quantity++] = coefficient + "x" + exponent;
}

void Polynomial::setCoefficient(int c) {
	coefficient = (c != 0 ? c : 1);
}

int Polynomial::getCoefficient() const {
	return coefficient;
}

void Polynomial::setExponent(int e) {
	exponent = (e != 0 ? e : 1);
}

int Polynomial::getExponent() const {
	return exponent;
}

const Polynomial &Polynomial::operator=(const Polynomial &right) {
	coefficient = right.coefficient;
	exponent = right.exponent;
	return *this;

}

const Polynomial &Polynomial::operator+(const Polynomial &right) const {
	if (right.exponent == exponent) {
		return Polynomial(coefficient + right.coefficient, exponent);
	}
	else {
		Polynomial p;
		if (right.exponent > exponent) {
			p.terms[0] = right.coefficient + "x" + right.exponent;
			p.terms[1] = coefficient + "x" + exponent;
		}
		else {
			p.terms[0] = coefficient + "x" + exponent;
			p.terms[1] = right.coefficient + "x" + right.exponent;
		}
		return p;
	}
}

const Polynomial &Polynomial::operator+=(const Polynomial &right) {
	if (right.exponent == exponent) {
		coefficient += right.coefficient;
	}
	else {
		if (right.exponent > exponent) {
			terms[0] = right.coefficient + "x" + right.exponent;
			terms[1] = coefficient + "x" + exponent;
		}
		else {
			terms[0] = right.coefficient + "x" + right.exponent;
			terms[1] = coefficient + "x" + exponent;
		}
	}
	return *this;
}

const Polynomial &Polynomial::operator-(const Polynomial &right) const {
	if (right.exponent == exponent) {
		return Polynomial(coefficient + right.coefficient, exponent);
	}
	else {
		Polynomial p;
		if (right.exponent > exponent) {
			p.terms[0] = right.coefficient + "x" + right.exponent;
			p.terms[1] = coefficient + "x" + exponent;
		}
		else {
			p.terms[0] = coefficient + "x" + exponent;
			p.terms[1] = right.coefficient + "x" + right.exponent;
		}
		return p;
	}
}

const Polynomial &Polynomial::operator-=(const Polynomial &right) {
	if (right.exponent == exponent) {
		coefficient -= right.coefficient;
	}
	else {
		if (right.exponent > exponent) {
			terms[0] = right.coefficient + "x" + right.exponent;
			terms[1] = coefficient + "x" + exponent;
		}
		else {
			terms[0] = right.coefficient + "x" + right.exponent;
			terms[1] = coefficient + "x" + exponent;
		}
	}
	return *this;
}

const Polynomial &Polynomial::operator*(const Polynomial &right) const {
	return *this;
}

const Polynomial &Polynomial::operator*=(const Polynomial &right) {
	
}

ostream &operator<<(ostream &output, const Polynomial &p) {
	return output;

}

istream &operator>>(istream &input, Polynomial &p) {
	return input;
}