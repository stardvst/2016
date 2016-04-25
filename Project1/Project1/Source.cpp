#include <iostream>
#include "DivideByZeroException.h"
using namespace std;

double quotient(int numerator, int denominator) {
	if (denominator == 0) {
		throw DivideByZeroException();
	}
	return static_cast<double>(numerator) / denominator;
}

int main() {

	int number1;
	int number2;
	double result;

	cout << "Enter two integers (end-of-file to end): ";

	while (cin >> number1 >> number2) {

		try {
			result = quotient(number1, number2);
			cout << "The quotient is: " << result << endl;
		}
		catch(DivideByZeroException &divideByZeroException) {
			cout << "Exception occurred: " <<
				divideByZeroException.what() << endl;
		}

		cout << "\nEnter two integers (end-of-file to end): ";
	}
	

	system("pause");
	return 0;
}