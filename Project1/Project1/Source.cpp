#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include "Time.h"
using namespace std;


int main() {
	
	Time t;
	t.printStandard();
	cout << "\n";
	t.printUniversal();
	cout << "\n";

	system("pause");
	return 0;
}

