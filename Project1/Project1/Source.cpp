#include <iostream>
#include "Flight.h"
using namespace std;


int main() {

	Time dep(12, 14, 0);
	Time arr(4, 14, 00);
	Flight flight1(CLIMBING, "Armavia", "ASD-5686", "KT-209A", 12000, 1000,
		"North", 13265, dep, arr, "BOS", "LAX");
	flight1.changeAltitude(17000);
	system("pause");
	return 0;
}

