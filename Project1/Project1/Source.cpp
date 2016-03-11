#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include "Complex.h"
using namespace std;


int main() {
	
	Complex c1(2, 3), c2(3, 4);
	c1.print();
	c2.print();
	c1.add(c2);
	c2.subtract(c1);
	c1.subtract(c2);

	system("pause");
	return 0;
}

