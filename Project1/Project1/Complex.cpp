#include <iostream>
#include "Complex.h"

Complex::Complex(double real, double imaginary) {
	setComplexNumber(real, imaginary);
}

Complex::~Complex() {}

void Complex::setComplexNumber(double real, double imaginary) {
	setRealPart(real);
	setImaginaryPart(imaginary);
}

void Complex::setRealPart(double real) {
	realPart = real;
}

void Complex::setImaginaryPart(double imaginary) {
	imaginaryPart = imaginary;
}

double Complex::getRealPart() {
	return realPart;
}

double Complex::getImaginaryPart() {
	return imaginaryPart;
}

void Complex::add(Complex complex2) {
	std::cout << "(" << realPart << " + " << imaginaryPart << "i) + "
		<< "(" << complex2.getRealPart() << " + " << complex2.getImaginaryPart() << "i)" <<
		" = " << realPart + complex2.getRealPart() << 
		(imaginaryPart - complex2.getImaginaryPart() > 0 ? " + " : " - ")  <<
		abs(imaginaryPart + complex2.getImaginaryPart()) << "i" << "\n";
}

void Complex::subtract(Complex complex2) {
	std::cout << "(" << realPart << " + " << imaginaryPart << "i) - "
		<< "(" << complex2.getRealPart() << " + " << 
		complex2.getImaginaryPart() << "i)" <<
		" = " << realPart - complex2.getRealPart() << 
		(imaginaryPart - complex2.getImaginaryPart() > 0  ? " + " : " - ") <<
		abs(imaginaryPart - complex2.getImaginaryPart()) << "i" << "\n";
}

void Complex::print() const {
	std::cout << "Complex number is " << "(" << realPart << ", " << imaginaryPart << ")" << "\n";
}