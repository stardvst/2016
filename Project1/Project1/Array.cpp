#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Array.h"
using namespace std;

Array::Array(int arraySize) {
	size = (arraySize < 10) ? arraySize : 10;
	ptr = new int[size]; // create space for pointer-based array
	for (int i = 0; i < size; i++) {
		ptr[i] = 0;
	}
}

Array::Array(const Array &arrayToCopy) :size(arrayToCopy.size) {
	ptr = new int[size];
	for (int i = 0; i < size; i++) {
		ptr[i] = arrayToCopy.ptr[i]; // copy into object
	}
}

Array::~Array() {
	delete[] ptr;
}

int Array::getSize() const {
	return size; // number of elements in Array
}

const Array &Array::operator=(const Array &right) {
	if (&right != this) { // avoid self-assignment
		if (size != right.size) {  // for Arrays of different sizes, deallocate original
			delete[] ptr;			 // left-side array, then allocate new left-side array
			size = right.size;
			ptr = new int[size];
		}
		for (int i = 0; i < size; i++) {
			ptr[i] = right.ptr[i]; // copy array into object
		}
	}
	return *this;
}

bool Array::operator==(const Array &right) const {
	if (size != right.size) {
		return false;
	} 
	for (int i = 0; i < size; i++) {
		if (ptr[i] != right.ptr[i]) {
			return false;
		}
	}
	return true;
}

int &Array::operator[](int subscript) {
	if (subscript < 0 || subscript >= size) {
		cerr << "\nError: Subscript " << subscript <<
			" out of range\n";
		exit(1);
	}
	return ptr[subscript];
}

int Array::operator[](int subscript) const {
	if (subscript < 0 || subscript >= size) {
		cerr << "\nError: Subscript " << subscript <<
			" out of range\n";
		exit(1);
	}
	return ptr[subscript];
}

istream &operator>>(istream &input, Array &a) {
	for (int i = 0; i < a.size; i++) {
		input >> a.ptr[i];
	}
	return input;
}

ostream &operator<<(ostream &output, const Array &a) {
	int i;
	for (i = 0; i < a.size; i++) {
		output << setw(12) << a.ptr[i];
		if ((i + 1) % 4 == 0) {
			output << endl;
		}
	}
	if (i % 4 != 0) {
		output << endl;
	}
	return output;
}