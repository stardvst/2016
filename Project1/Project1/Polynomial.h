#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <string>
using std::ostream;
using std::istream;

class Polynomial {
	friend ostream &operator<<(ostream &, const Polynomial &);
	friend istream &operator>>(istream &, Polynomial &);
public:
	Polynomial(int = 1, int = 1);
	Polynomial(const Polynomial &);

	void setCoefficient(int);
	int getCoefficient() const;
	void setExponent(int);
	int getExponent() const;

	const Polynomial &operator=(const Polynomial &);
	const Polynomial &operator+(const Polynomial &) const;
	const Polynomial &operator+=(const Polynomial &);
	const Polynomial &operator-(const Polynomial &) const;
	const Polynomial &operator-=(const Polynomial &);
	const Polynomial &operator*(const Polynomial &) const;
	const Polynomial &operator*=(const Polynomial &);

private:
	int coefficient;
	int exponent;

	static std::string terms[];
	static int quantity;
};

#endif // !POLYNOMIAL_H


