#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;


int main() {

	string str = "Hello";
	string::const_iterator iter = str.begin();
	cout << "str = " << str
		<< "\n(Using iterator iter) str is: ";
	while (iter != str.end()) {
		cout << *iter;
		++iter;
	}

	cin.get();
	return 0;
}