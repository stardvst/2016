#include <iostream>
#include "HugeInteger.h"

void HugeInteger::input() {
	std::cout << "Input the digits:\n";
	for (int i = 0; i < 40; i++) {
		std::cout << "Digit " << i + 1 << ": ";
		std::cin >> digits[i];
	}
	std::cout << "\n\n";
}

void HugeInteger::output() const {
	std::cout << "Output:\n";
	for (int i = 0; i < 40; i++) {
		std::cout << "Digit " << i + 1 << ": " << digits[i] << "   ";
		if ((i + 1) % 4 == 0) {
			std::cout << "\n";
		}
	}
	std::cout << "\n\n";
}

HugeInteger HugeInteger::add(const HugeInteger &other) const {
	HugeInteger temp;
	for (int i = 0; i < 40; i++) {
		temp.digits[i] = digits[i] + other.digits[i];
	}
	return temp;
}

HugeInteger HugeInteger::subtract(const HugeInteger &other) const {
	HugeInteger temp;
	for (int i = 0; i < 40; i++) {
		temp.digits[i] = digits[i] - other.digits[i];
	}
	return temp;
}

HugeInteger HugeInteger::multiply(const HugeInteger &other) const {
	HugeInteger temp;
	for (int i = 0; i < 40; i++) {
		temp.digits[i] = digits[i] * other.digits[i];
	}
	return temp;
}

HugeInteger HugeInteger::divide(const HugeInteger &other) const {
	HugeInteger temp;
	for (int i = 0; i < 40; i++) {
		if (other.digits[i] == 0) {
			std::cout << "Digit " << i << ": " << "Denominator can't be 0. Value set to -1.\n";
			temp.digits[i] = -1;
			continue;
		}
		else {
			temp.digits[i] = (double)digits[i] / other.digits[i];
		}
	}
	return temp;
}

HugeInteger HugeInteger::modulus(const HugeInteger &other) const {
	HugeInteger temp;
	for (int i = 0; i < 40; i++) {
		if (other.digits[i] == 0) {
			std::cout << "Digit " << i << ": " << "Can't mod 0. Value set to -1.\n";
			temp.digits[i] = -1;
			continue;
		}
		else {
			temp.digits[i] = digits[i] % other.digits[i];
		}
	}
	return temp;
}

bool HugeInteger::isEqualTo(const HugeInteger &other) const {
	for (int i = 0; i < 40; i++) {
		if (digits[i] != other.digits[i]) {
			return false;
		}
	}
	return true;
}

bool HugeInteger::isNotEqualTo(const HugeInteger &other) const {
	for (int i = 0; i < 40; i++) {
		if (digits[i] == other.digits[i]) {
			return false;
		}
	}
	return true;
}

bool HugeInteger::isGreaterThan(const HugeInteger &other) const {
	for (int i = 0; i < 40; i++) {
		if (digits[i] <= other.digits[i]) {
			return false;
		}
	}
	return true;
}

bool HugeInteger::isLessThan(const HugeInteger &other) const {
	for (int i = 0; i < 40; i++) {
		if (digits[i] >= other.digits[i]) {
			return false;
		}
	}
	return true;
}

bool HugeInteger::isGreaterThanOrEqualTo(const HugeInteger &other) const {
	for (int i = 0; i < 40; i++) {
		if (digits[i] < other.digits[i]) {
			return false;
		}
	}
	return true;
}

bool HugeInteger::isLessThanOrEqualTo(const HugeInteger &other) const {
	for (int i = 0; i < 40; i++) {
		if (digits[i] > other.digits[i]) {
			return false;
		}
	}
	return true;
}

bool HugeInteger::isZero() const {
	for (int i = 0; i < 40; i++) {
		if (digits[i] != 0) {
			return false;
		}
	}
	return true;
}