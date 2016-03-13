#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include "Date.h"
using namespace std;

int main() {
	
	//Date d(11,2,2016);
	//Date d(125, 2016);
	//Date d(125, 2015);
	//Date d(366, 2015);
	Date d; // is initialized by the system
	d.formatDDDYYYY();
	d.formatMMDDYY();
	d.displayInTextFormat();

	system("pause");
	return 0;
}

