#include <iostream>
#include "DoubleSubscriptedArray.h"
using namespace std;


int main() {

	DoubleSubscriptedArray integers1(2, 2);
	DoubleSubscriptedArray integers2;

	cout << "Integers1 has " << integers1.getRows() << " rows" <<
		" and " << integers1.getColumns() << " columns. The size is " <<
		integers1.getSize() << endl;

	cout << "Integers2 has " << integers2.getRows() << " rows" <<
		" and " << integers2.getColumns() << " columns. The size is " <<
		integers2.getSize() << endl;

	cout << "Enter " << integers1.getSize() + integers2.getSize() <<
		" integers:\n";
	cin >> integers1 >> integers2;

	cout << "After input, arrays contain:\n" <<
		"integers1:\n" << integers1 <<
		"integers2:\n" << integers2;

	cout << "\nEvaluating: integers1 != integers2" << endl;
	if (integers1 != integers2) {
		cout << "integers1 and integers2 are not equal" << endl;
	}

	DoubleSubscriptedArray integers3(integers1);

	cout << "Integers3 has " << integers3.getRows() << " rows" <<
		" and " << integers3.getColumns() << " columns. The size is " <<
		integers3.getSize() << endl;

	
	cout << "\nintegers1[4][5] is " << integers1(4, 5);
	cout << "\nintegers1[1][1] is " << integers1(1, 1);
	cout << "\nintegers2[1][1] is " << integers2(1, 1);

	cout << "\nAssigning integers2 to integers1:" << endl;
	integers1 = integers2;

	cout << "\nEvaluating: integers1 == integers2" << endl;
	if (integers1 == integers2) {
		cout << "integers1 and integers2 are equal" << endl;
	}

	

	system("pause");
	return 0;
}

