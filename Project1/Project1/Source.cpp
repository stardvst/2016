#include <iostream>
#include "PhoneNumber.h"
using namespace std;

int main() {

	PhoneNumber phone;

	cout << "Enter phone number in the form (123) 456-7890:" << endl;

	// cin >> phone invokes operator>> by implicitly issuing
	// the global function call operator>>( cin, phone )
	cin >> phone;

	cout << "The phone number entered was: ";

	// cout << phone invokes operator<< by implicitly issuing
	// the global function call operator<<( cout, phone )
	cout << phone;
	
	system("pause");
	return 0;
}

