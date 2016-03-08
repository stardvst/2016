#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
using namespace std;

class Count {
	friend void setX(Count &, int);
public:
	Count() : x(0) {};
	void print() const {
		cout << x << endl;
	}
private:
	int x;
};

void setX(Count &count, int val) {
	count.x = val;
}

int main() {

	Count counter;

	cout << "counter.x after instantiation: ";
	counter.print();

	setX(counter, 8);
	cout << "counter.x after call to setX friend function: ";
	counter.print();

	setX(counter, 5);
	cout << "counter.x after call to setX friend function: ";
	counter.print();

	system("pause");
	return 0;
}

