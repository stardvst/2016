#include <iostream>
#include "DateAndTime.h"
using namespace std;

int main() {
	//DateAndTime date(16, 3, 2016, 14, 25, 34);
	DateAndTime date(16, 3, 2016, 23, 59, 59);
	date.printStandard();
	date.printUniversal();
	date.tick();
	system("pause");
	return 0;
}

