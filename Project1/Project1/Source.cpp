#include <iostream>
#include "Array.h"
using namespace std;

void outputArray(const Array &);

int main() {

	Array integers1(7);
	outputArray(integers1);
	// outputArray(3); // no suitable constructor exists to convert from "int" to "Array"
	outputArray(Array(3));

	system("pause");
	return 0;
}

void outputArray(const Array &arrayToOutput) {
	cout << "The Array received has " << arrayToOutput.getSize()
		<< " elements. The contents are:\n" << arrayToOutput << endl;
}