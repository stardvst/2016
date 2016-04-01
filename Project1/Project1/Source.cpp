#include <iostream>
#include "Interface.h"
using namespace std;


int main() {

	Interface i(5);
	cout << "i contains " << i.getValue()
		<< " before setting a value.\n";
	i.setValue(10);
	cout << "i contains " << i.getValue()
		<< " after setting a value.\n";

	system("pause");
	return 0;
}


