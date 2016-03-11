#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include "Rectangle.h"
using namespace std;


int main() {
	
	Rectangle r1(2, 3);
	cout << "Area: " << r1.area() << "\nPerimeter: " << r1.perimeter() << "\n\n";

	Rectangle r2(-5, 25);
	cout << "Area: " << r2.area() << "\nPerimeter: " << r2.perimeter() << '\n';

	system("pause");
	return 0;
}

