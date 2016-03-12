#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include "Date.h"
using namespace std;

int main() {
	
	Date d(28,2,2016);
	cout << "Date: ";
	d.print();
	d.nextDay();
	cout << "Next day is: ";
	d.print(); 
	cout << endl;

	system("pause");
	return 0;
}

