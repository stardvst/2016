#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
public:
	Rational(int = 1, int = 1);
	Rational add(const Rational &) const;
	Rational subtract(const Rational &) const;
	Rational multiply(const Rational &) const;
	Rational divide(const Rational &) const;
	void printRational() const;
	void printFloating() const; 
private:
	int numerator;
	int denominator;
};

#endif // !RATIONAL_H

