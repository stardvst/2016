#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include "Time.h"
using namespace std;


int main() {
	
	Time t(11,59,59);
	cout << "Current time: ";
	t.printStandard();
	t.tick();

	t.setTime(23, 59, 59);
	cout << "Current time: ";
	t.printStandard();
	t.tick();

	t.setTime(10, 59, 59);
	cout << "Current time: ";
	t.printStandard();
	t.tick();

	t.setTime(10, 35, 59);
	cout << "Current time: ";
	t.printStandard();
	t.tick();

	system("pause");
	return 0;
}

