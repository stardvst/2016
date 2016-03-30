#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "DoubleSubscriptedArray.h"


DoubleSubscriptedArray::DoubleSubscriptedArray(int r, int c) {
	row = ((r >= 1)) ? r : 5;
	column = ((c >= 1)) ? c : 5;
	ptr = new int[row*column];
	if (!ptr) {
		std::cout << "Not enought memory.\n";
		exit(1);
	}
	for (int i = 0; i < row*column; i++) {
		ptr[i] = 0;
	}
}

DoubleSubscriptedArray::DoubleSubscriptedArray(const DoubleSubscriptedArray &other) {
	row = other.row;
	column = other.column;
	ptr = new int[row*column];
	for (int i = 0; i < row*column; i++) {
		ptr[i] = other.ptr[i];
	}
}

DoubleSubscriptedArray::~DoubleSubscriptedArray() {
	delete[] ptr;
}

int DoubleSubscriptedArray::getRows() const {
	return row;
}

int DoubleSubscriptedArray::getColumns() const {
	return column;
}

int DoubleSubscriptedArray::getSize() const {
	return row * column;
}

const DoubleSubscriptedArray &DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray &right) {
	if (&right != this) {
		if (row != right.row || column != right.column) {
			delete[] ptr;
			row = right.row;
			column = right.column;
			ptr = new int[row*column];
		}
		for (int i = 0; i < row*column; i++) {
			ptr[i] = right.ptr[i];
		}
	}
	return *this;
}

bool DoubleSubscriptedArray::operator==(const DoubleSubscriptedArray &right) const {
	if (row != right.row || column != right.column) {
		return false;
	}
	else {
		for (int i = 0; i < row*column; i++) {
			if (ptr[i] != right.ptr[i]) {
				return false;
			}
		}
	}
	return true;
}

bool DoubleSubscriptedArray::operator!=(const DoubleSubscriptedArray &right) const {
	return !(*this == right);
}

int &DoubleSubscriptedArray::operator()(const int i, const int j) {
	if (i > row) {
		std::cerr << "Subscript " << i << " is out of range.\n";
		if (j > column) {
			std::cerr << "Subscript " << j << " is out of range.\n";
			system("pause");
			exit(1);
		}
		system("pause");
		exit(1);
	}
	if (j > column) {
		std::cerr << "Subscript " << j << " is out of range.\n";
		system("pause");
		exit(1);
	}
	return ptr[i*row + j];
}

const int &DoubleSubscriptedArray::operator()(const int i, const int j) const {
	if (i > row) {
		std::cerr << "Subscript " << i << " is out of range.\n";
		if (j > column) {
			std::cerr << "Subscript " << j << " is out of range.\n";
			system("pause");
			exit(1);
		}
		system("pause");
		exit(1);
	}
	if (j > column) {
		std::cerr << "Subscript " << j << " is out of range.\n";
		system("pause");
		exit(1);
	}
	return ptr[i*row + j];
}

istream &operator>>(istream &input, DoubleSubscriptedArray &a) {
	for (int i = 0; i < a.row*a.column; i++) {
		input >> a.ptr[i];
	}
	return input;
}

ostream &operator<<(ostream &output, const DoubleSubscriptedArray &a) {
	for (int i = 0; i < a.column; i++) {
		for (int j = 0; j < a.row; j++) {
			output << std::setw(7) << a.ptr[i*a.column + j];
		}
		std::cout << std::endl;
	}
	return output;
}