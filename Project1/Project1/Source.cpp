#include <iostream>
#include "HugeInteger.h"
using namespace std;

int main() {

	HugeInteger h1;
	h1.input();

	HugeInteger h2;
	h2.input();

	HugeInteger h3 = h1.add(h2);
	cout << "h1 + h2 =\n";
	h3.output();

	h3 = h1.subtract(h2);
	cout << "h1 - h2 =\n";
	h3.output();

	h3 = h1.multiply(h2);
	cout << "h1 * h2 =\n";
	h3.output();

	cout << "h1 / h2 =\n";
	h3 = h1.divide(h2);
	h3.output();

	cout << "h1 % h2 =\n";
	h3 = h1.modulus(h2);
	h3.output();


	system("pause");
	return 0;
}

