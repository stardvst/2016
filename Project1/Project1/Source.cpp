#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include "Employee.h"
using namespace std;


int main() {
	
	cout << "Number of employees before instantiation of any objects is "
		<< Employee::getCount() << endl;

	// the following scope creates and destroys
	// Employee objects before main terminates
	{
		Employee e1("Susan", "Baker");
		Employee e2("Robert", "Jones");

		cout << "Number of employees after objects are instantiated is "
			<< Employee::getCount();

		cout << "\n\nEmployee 1: " << e1.getFirstName() << ' ' << e1.getlastName() 
			<< "\nEmployee 2: " << e2.getFirstName() << ' ' << e2.getlastName() << "\n\n";
	}

	// no objects exist, so call static member function getCount again
	// using the class name and the binary scope resolution operator
	cout << "\nNumber of employees after objects are deleted is "
		<< Employee::getCount() << "\n";

	system("pause");
	return 0;
}

