#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
public:
	Rational(int = 1, int = 1);

	/* addition, subtraction, multiplication, division */
	Rational operator+(const Rational &) const;
	Rational operator-(const Rational &) const;
	Rational operator*(const Rational &) const;
	Rational operator/(const Rational &) const;

	/* relational and equality operators */
	bool operator==(const Rational &) const;
	bool operator!=(const Rational &) const;
	bool operator<(const Rational &) const;
	bool operator>(const Rational &) const;
	bool operator<=(const Rational &) const;
	bool operator>=(const Rational &) const;

	/* print the fraction */
	void printRational() const;
	void printFloating() const; 
private:
	int numerator;
	int denominator;
};

#endif // !RATIONAL_H

