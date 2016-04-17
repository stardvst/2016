#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H

#include <iostream>
#include <string>
using std::string;
using std::ostream;

class HugeInteger {
	friend ostream &operator<<(ostream &, const HugeInteger &);
public:

	static const int digits = 30; // max digits in a HugeInteger

	HugeInteger(long = 0); // conversion/default ctor
	HugeInteger(const string &); // conversion ctor

	HugeInteger operator+(const HugeInteger &) const; // HugeInteger + HugeInteger
	HugeInteger operator+(int) const; // HugeInteger + int
	HugeInteger operator+(const string &) const; // HugeInteger + string

	HugeInteger operator*(const HugeInteger &) const; // HugeInteger * HugeInteger
	HugeInteger operator*(int) const; // HugeInteger * int
	HugeInteger operator*(const string &) const; // HugeInteger * string

	HugeInteger operator/(const HugeInteger &) const; // HugeInteger / HugeInteger
	HugeInteger operator/(int) const; // HugeInteger / int
	HugeInteger operator/(const string &) const; // HugeInteger / string

	HugeInteger operator==(const HugeInteger &) const; // HugeInteger == HugeInteger
	HugeInteger operator==(int) const; // HugeInteger == int
	HugeInteger operator==(const string &) const; // HugeInteger == string

	HugeInteger operator!=(const HugeInteger &) const; // HugeInteger != HugeInteger
	HugeInteger operator!=(int) const; // HugeInteger != int
	HugeInteger operator!=(const string &) const; // HugeInteger != string

private:
	short integer[digits];
};

#endif // !HUGEINTEGER_H

