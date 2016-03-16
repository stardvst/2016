#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
public:
	Rational(int = 1, int = 1);
	int getNumerator() const;
	int getDenominator() const;
	Rational add(const Rational &) const;
	Rational subtract(const Rational &) const;
	Rational multiply(const Rational &) const;
	Rational divide(const Rational &) const;
	void printRational();
	void printFloating() const; 
private:
	int numerator;
	int denominator;
	void reduceTheFraction(int, int);
};

#endif // !RATIONAL_H

