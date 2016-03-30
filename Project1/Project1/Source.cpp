#include <iostream>
#include "Complex.h"
using namespace std;


int main() {

	Complex x(4.3, 8.2);
	Complex y(3.3, 1.1);
	Complex z;

	cout << "x is " << x << endl <<
		"y is " << y << endl << "z is " << z << endl << endl;
	
	cout << "z = x + y" << endl; 
	z = x + y;
	cout << x << " + " << y << " = " << z << endl << endl;

	cout << "z = x - y" << endl;
	z = x - y;
	cout << x << " - " << y << " = " << z << endl << endl;

	cout << "z = x * y" << endl;
	z = x * y;
	cout << x << " * " << y << " = " << z << endl << endl;

	cout << "Is x = y ?: " << ((x == y) ? "yes" : "no") << endl;

	system("pause");
	return 0;
}

