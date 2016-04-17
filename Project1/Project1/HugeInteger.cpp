#include <cctype> // isdigit
#include "HugeInteger.h"


HugeInteger::HugeInteger(long value) {
	for (int i = 0; i < digits; i++) {
		integer[i] = 0; // init to 0
	}
	for (int j = digits - 1; value != 0 && j >= 0; j--) {
		integer[j] = value % 10;
		value /= 10;
	}
}

HugeInteger::HugeInteger(const string &number) {
	for (int i = 0; i < digits; i++) {
		integer[i] = 0; // init to 0
	}

	int length = number.size();
	for (int j = digits - length, k = 0; j < digits; j++, k++) {
		if (isdigit(number[k])) {
			integer[j] = number[k] - '0';
		}
	}
}

HugeInteger HugeInteger::operator+(const HugeInteger &operand2) const {
	HugeInteger temp;
	int carry = 0;
	for (int i = digits - 1; i >= 0; i--) {
		temp.integer[i] = integer[i] + operand2.integer[i] + carry;
		if (temp.integer[i] > 9) {
			temp.integer[i] %= 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
	}
	return temp;
}

HugeInteger HugeInteger::operator+(int operand2) const {
	return *this + HugeInteger(operand2);
}

HugeInteger HugeInteger::operator+(const string &operand2) const {
	return *this + HugeInteger(operand2);
}

ostream &operator<<(ostream &output, const HugeInteger &number) {
	int i;
	for (i = 0; (number.integer[i] == 0) && (i <= HugeInteger::digits); i++)
		;
	if (i == HugeInteger::digits) {
		output << 0;
	}
	for (; i < HugeInteger::digits; i++) {
		output << number.integer[i];
	}
	return output;
}