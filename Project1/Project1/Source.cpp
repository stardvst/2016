#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
using namespace std;

class Test {
public:
	Test(int = 0);
	void print() const;
private:
	int x;
};

Test::Test(int value) : x(value) {};

void Test::print() const {
	cout << "x = " << x << endl; // uses the this pointer implicitly
	cout << "this->x = " << this->x << endl;
	cout << "(*this).x = " << (*this).x << endl;
}


int main() {

	Test testObject(12);
	testObject.print();
	
	system("pause");
	return 0;
}

