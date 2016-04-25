#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <iomanip>
using namespace std;

template <typename T, int size>
class Array;

template <typename T, int size>
ostream &operator<< <>(ostream &, const Array<T, size> &);

template <typename T, int size>
istream &operator>> <>(istream &, Array<T, size> &);

template <typename T, int size>
class Array {

	
	friend ostream &operator<< <>(ostream &, const Array<T, size> &);
	
	friend istream &operator>> <>(istream &, Array<T, size> &);

public:
	Array();
	Array(const Array<T, size> &);

	int getSize() const;

	const Array<T, size> &operator=(const Array<T, size> &); // assignment operator
	bool operator==(const Array<T, size> &) const; // equality operator

												   // inequality operator; returns opposite of == operator
	bool operator!=(const Array<T, size> &right) {
		return !(*this == right); // invokes Array::operator==
	}

	// subscript operator for non-const objects returns modifiable lvalue
	T &operator[](int);

	// subscript operator for const objects returns rvalue
	T operator[](int) const;
private:
	T ptr[size]; // pointer to first element of pointer-based array
};



// OVERRIDING FOR FLOATS

template <int size>
class Array<float, size> {

	/* ATTENTION! friend operator templates must be specialized */

	friend ostream &operator<< <>(ostream &, const Array<float, size> &);
	friend istream &operator>> <>(istream &, Array<float, size> &);

public:
	Array();
	Array(const Array<float, size> &);

	int getSize() const;

	const Array<float, size> &operator=(const Array<float, size> &); // assignment operator
	bool operator==(const Array<float, size> &) const; // equality operator

													   // inequality operator; returns opposite of == operator
	bool operator!=(const Array<float, size> &right) {
		return !(*this == right); // invokes Array::operator==
	}

	// subscript operator for non-const objects returns modifiable lvalue
	float &operator[](int);

	// subscript operator for const objects returns rvalue
	float operator[](int) const;
private:
	float ptr[size]; // pointer to first element of pointer-based array
};

#endif // !ARRAY_H







template <typename T, int size>
Array<T, size>::Array() {
	for (int i = 0; i < size; i++) {
		ptr[i] = 0;
	}
}

template <typename T, int size>
Array<T, size>::Array(const Array<T, size> &arrayToCopy) {
	for (int i = 0; i < size; i++) {
		ptr[i] = arrayToCopy.ptr[i]; // copy into object
	}
}

template <typename T, int size>
int Array<T, size>::getSize() const {
	return size; // number of elements in Array
}

template <typename T, int size>
const Array<T, size> &Array<T, size>::operator=(const Array<T, size> &right) {
	if (&right != this) { // avoid self-assignment
		for (int i = 0; i < size; i++) {
			ptr[i] = right.ptr[i]; // copy array into object
		}
	}
	return *this;
}

template <typename T, int size>
bool Array<T, size>::operator==(const Array<T, size> &right) const {
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

template <typename T, int size>
T &Array<T, size>::operator[](int subscript) {
	if (subscript < 0 || subscript >= size) {
		cerr << "\nError: Subscript " << subscript <<
			" out of range\n";
		exit(1);
	}
	return ptr[subscript];
}

template <typename T, int size>
T Array<T, size>::operator[](int subscript) const {
	if (subscript < 0 || subscript >= size) {
		cerr << "\nError: Subscript " << subscript <<
			" out of range\n";
		exit(1);
	}
	return ptr[subscript];
}

template <typename T, int size>
istream &operator>> <>(istream &input, Array<T, size> &a) {
	for (int i = 0; i < size; i++) {
		input >> a.ptr[i];
	}
	return input;
}

template <typename T, int size>
ostream &operator<< <>(ostream &output, const Array<T, size> &a) {
	int i;
	for (i = 0; i < size; i++) {
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









template <int size>
Array<float, size>::Array() {
	for (int i = 0; i < size; i++) {
		ptr[i] = 0.0;
	}
}

template <int size>
Array<float, size>::Array(const Array<float, size> &arrayToCopy) {
	for (int i = 0; i < size; i++) {
		ptr[i] = arrayToCopy.ptr[i]; // copy into object
	}
}

template <int size>
int Array<float, size>::getSize() const {
	return size; // number of elements in Array
}

template <int size>
const Array<float, size> &Array<float, size>::operator=(const Array<float, size> &right) {
	if (&right != this) { // avoid self-assignment
		for (int i = 0; i < size; i++) {
			ptr[i] = right.ptr[i]; // copy array into object
		}
	}
	return *this;
}

template <int size>
bool Array<float, size>::operator==(const Array<float, size> &right) const {
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

template <int size>
float &Array<float, size>::operator[](int subscript) {
	if (subscript < 0 || subscript >= size) {
		cerr << "\nError: Subscript " << subscript <<
			" out of range\n";
		exit(1);
	}
	return ptr[subscript];
}

template <int size>
float Array <float, size > ::operator[](int subscript) const {
	if (subscript < 0 || subscript >= size) {
		cerr << "\nError: Subscript " << subscript <<
			" out of range\n";
		exit(1);
	}
	return ptr[subscript];
}

template <int size>
istream &operator>> <>(istream &input, Array<float, size> &a) {
	for (int i = 0; i < size; i++) {
		input >> a.ptr[i];
	}
	return input;
}

template <int size>
ostream &operator<< <>(ostream &output, const Array<float, size> &a) {
	int i;
	for (i = 0; i < size; i++) {
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

