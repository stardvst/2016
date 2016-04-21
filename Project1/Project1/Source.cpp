#include <iostream>
using namespace std;

template< typename T >
int printArray(const T * const array, int count, int lowSubscript, int highSubscript) {
	if (lowSubscript >= 1 && highSubscript <= count && lowSubscript <= highSubscript) {
		int numberOfElements = 0;
		for (int i = lowSubscript; i < highSubscript; i++) {
			cout << array[i] << " ";
			numberOfElements++;
		}
		cout << endl;
		return numberOfElements;
	}
	return 0;
}

int main() {

	const int aCount = 5; // size of array a
	const int bCount = 7;
	const int cCount = 6;

	int a[aCount] = { 1,2,3,4,5 };
	double b[bCount] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7 };
	char c[cCount] = "HELLO";

	cout << "Array a contains" << endl;
	if (printArray(a, aCount, 2, 4) == 0) {
		cout << "Subscripts are not correct!\n";
	}
	cout << endl;

	cout << "Array b contains" << endl;
	if (printArray(b, bCount, -5, 4) == 0) {
		cout << "Subscripts are not correct!\n";
	}
	cout << endl;

	cout << "Array c contains" << endl;
	if (printArray(c, cCount, 5, 4) == 0) {
		cout << "Subscripts are not correct!\n";
	}
	cout << endl;

	system("pause");
	return 0;
}