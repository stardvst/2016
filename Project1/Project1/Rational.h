#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
public:
	Rational(int = 1, int = 1);
	~Rational();
	int getNumerator();
	int getDenominator();
	void add(Rational);
	void subtract(Rational);
	void multiply(Rational);
	void divide(Rational);
	void printRational () const;
	void printFloating() const;
private:
	int numerator;
	int denominator;
	static void reduce(int, int);
};

#endif // !RATIONAL_H

