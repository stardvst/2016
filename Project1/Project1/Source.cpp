#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include "Time.h"
using namespace std;


int main() {

	Time t;
	t.setHour(18).setMinute(34).setSecond(25);

	cout << "Universal time: ";
	t.printUniversal();
	cout << "\nStandard time: ";
	t.printStandard();

	cout << "\n\nNew standard time: ";
	t.setTime(20, 20, 20).printUniversal();
	cout << endl;

	system("pause");
	return 0;
}

