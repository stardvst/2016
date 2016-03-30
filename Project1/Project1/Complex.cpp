#include <iostream>
#include "Complex.h"

Complex::Complex(double realPart, double imaginaryPart)
	:real(realPart), imaginary(imaginaryPart) {
	// empty body
}

Complex Complex::operator+(const Complex &operand2) const {
	return Complex(real + operand2.real, imaginary + operand2.imaginary);
}

Complex Complex::operator-(const Complex &operand2) const {
	return Complex(real - operand2.real, imaginary - operand2.imaginary);
}

Complex Complex::operator*(const Complex &operand2) const {
	return Complex(real * operand2.real - imaginary * operand2.imaginary,
		real * operand2.imaginary + imaginary * operand2.real);
}

bool Complex::operator==(const Complex &operand2) const {
	if (real == operand2.real && imaginary == operand2.imaginary) {
		return true;
	}
	else {
		return false;
	}
}

bool Complex::operator!=(const Complex &operand2) const {
	if (real != operand2.real || imaginary != operand2.imaginary) {
		return true;
	}
	else {
		return false;
	}
}

istream &operator>>(istream &input, Complex &number) {
	input >> number.real >> number.imaginary;
	return input;
}

ostream &operator<<(ostream &output, const Complex &number) {
	output << '(' << number.real << ", " << number.imaginary << ')';
	return output;
}