#include <iostream>
#include "Date.h"
using namespace std;


int main() {

	Date d1(27, 12, 1992);
	Date d2(99, 0, 8045);
	Date d3;

	cout << "d1 is " << d1 << "\nd2 is " << d2 << "\nd3 is " << d3;
	cout << "\n\nd2 += 7 is " << (d2 += 7);

	d3.setDate(28, 2, 1992);
	cout << "\nd3 is " << d3;
	cout << "\n++d3 is " << ++d3 << " (leap year allows 29th)";

	Date d4(13, 7, 2002);

	cout << "\n\nTesting the prefix increment operator:\n"
		<< " d4 is " << d4 << endl;
	cout << "++d4 is " << ++d4 << endl;
	cout << " d4 is " << d4;

	cout << "\n\nTesting the postfix increment operator:\n"
		<< " d4 is " << d4 << endl;
	cout << "d4++ is " << d4++ << endl;
	cout << " d4 is " << d4 << endl;

	system("pause");
	return 0;
}

