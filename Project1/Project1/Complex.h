#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
public:
	Complex(double = 1, double = 1);
	~Complex();
	void setComplexNumber(double, double);
	void setRealPart(double);
	void setImaginaryPart(double);
	double getRealPart();
	double getImaginaryPart();
	void add(Complex);
	void subtract(Complex);
	void print() const;
private:
 	double realPart;
	double imaginaryPart;
};

#endif // !COMPLEX_H
