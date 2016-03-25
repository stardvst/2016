#include <iostream>
#include "Array.h"
using namespace std;

int main() {
	
	Array integers1(7); // seven-element Array
	Array integers2; // 10-element Array by default

	cout << "Size of Array integers1 is "
		<< integers1.getSize() << 
		"\nArray after initialization:\n" << integers1;

	cout << "Size of Array integers2 is "
		<< integers2.getSize() <<
		"\nArray after initialization:\n" << integers2;

	cout << "\nEnter 17 integers:" << endl;
	cin >> integers1 >> integers2;

	cout << "\nAfter input, the Arrays contain:\n"
		<< "integers1:\n" << integers1 
		<< "\nintegers2:\n" << integers2;

	cout << "\nEvaluating: integers1 != integers2" << endl;
	if (integers1 != integers2) {
		cout << "integers1 and integers2 are not equal" << endl;
	}

	// create Array integers3 using integers1 as an
	// initializer; print size and contents
	Array integers3(integers1); // invokes copy constructor
	cout << "Size of Array integers3 is "
		<< integers3.getSize() <<
		"\nArray after initialization:\n" << integers3;

	cout << "\nAssigning integers2 to integers1:" << endl; // use overloaded assignment (=) operator
	integers1 = integers2;

	cout << "integers1:\n" << integers1
		<< "\nintegers2:\n" << integers2;

	// use overloaded equality (==) operator
	cout << "\nEvaluating: integers1 == integers2" << endl;
	if (integers1 == integers2) {
		cout << "integers1 and integers2 are equal" << endl;
	}

	// use overloaded subscript operator to create lvalue
	cout << "\n\nAssigning 1000 to integers1[5]" << endl;
	integers1[5] = 1000;
	cout << "integers1:\n" << integers1;

	// attempt to use out-of-range subscript
	cout << "\nAttempt to assign 1000 to integers1[15]" << endl;
	integers1[15] = 1000; // ERROR: out of range

	system("pause");
	return 0;
}

