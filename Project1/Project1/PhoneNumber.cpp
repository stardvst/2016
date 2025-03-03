#include <iomanip>
#include "PhoneNumber.h"
using namespace std;

ostream &operator<<(ostream &output, const PhoneNumber &number) {
	output << "(" << number.areaCode << ") " << number.exchange <<
		"-" << number.line;
	return output;
}

istream &operator>>(istream &input, PhoneNumber &number) {
	input.ignore(); // ignoring the ( char
	input >> setw(3) >> number.areaCode;
	input.ignore(2); // ignore ) and space
	input >> setw(3) >> number.exchange;
	input.ignore(); // ignore )
	input >> setw(4) >> number.line;
	return input;
}