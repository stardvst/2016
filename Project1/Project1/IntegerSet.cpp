#include <iostream>
#include "IntegerSet.h"
using std::cout;

IntegerSet::IntegerSet() {
	for (int i = 0; i <= 100; i++) {
		set[i] = false;
	}
}

IntegerSet::IntegerSet(int values[], const int size) {
	int i;
	if (size >=0 && size <= 100) {
		for (i = 0; i < size; i++) {
			if (i == values[i]) {
				set[values[i]] = true;
			}
			else {
				set[values[i]] = false;
			}
		}
	}
	else if (size == 100) {
		for (i = 0; i <= 100; i++) {
			set[values[i]] = true;
		}
	}
	else {
		cout << "Size out of range. Set defaulted to all 0's.\n";
		for (i = 0; i <= 100; i++) {
			set[values[i]] = false;
		}
	}
}

IntegerSet IntegerSet::unionOfSets(const IntegerSet &other) const {
	IntegerSet third;
	for (int i = 0; i <= 100; i++) {
		if (set[i] || other.set[i]) {
			third.set[i] = true;
		}
		else {
			third.set[i] = false;
		}
	}
	return third;
}

IntegerSet IntegerSet::intersectionOfSets(const IntegerSet &other) const {
	IntegerSet third;
	for (int i = 0; i <= 100; i++) {
		if (set[i] && other.set[i]) {
			third.set[i] = true;
		}
		else {
			third.set[i] = false;
		}
	}
	return third;
}

void IntegerSet::insertElement(const int element) {
	set[element] = true;
}

void IntegerSet::deleteElement(const int element) {
		set[element] = false;
}
void IntegerSet::printSet(int values[]) const {
	for (int i = 0; i <= 100; i++) {
		if (values[i]) {
			cout << set[i] << ' ';
		}
	}
}

bool IntegerSet::isEqualTo(const IntegerSet &other) const {
	for (int i = 0; i <= 100; i++) {
		if (set[i] != other.set[i]) {
			return false;
		}
	}
	return true;
}