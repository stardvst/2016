#ifndef DOUBLESUBSCRIPTEDARRAY_H
#define DOUBLESUBSCRIPTEDARRAY_H

#include <iostream>
using std::ostream;
using std::istream;

class DoubleSubscriptedArray {
	friend ostream &operator<<(ostream &, const DoubleSubscriptedArray &);
	friend istream &operator>>(istream &, DoubleSubscriptedArray &);
public:
	DoubleSubscriptedArray(int = 3, int = 3); // default constructor
	DoubleSubscriptedArray(const DoubleSubscriptedArray &); // copy constructor
	~DoubleSubscriptedArray(); // destructor
	int getRows() const;
	int getColumns() const;
	int getSize() const;
	const DoubleSubscriptedArray &operator=(const DoubleSubscriptedArray &);
	bool operator==(const DoubleSubscriptedArray &) const;
	bool operator!=(const DoubleSubscriptedArray &) const;

	int &operator()(const int, const int);
	const int &operator()(const int, const int) const;

private:
	int row;
	int column;
	int *ptr;
};

#endif // !DOUBLESUBSCRIPTEDARRAY_H

