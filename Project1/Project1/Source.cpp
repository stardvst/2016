#include <iostream>
using namespace std;

template <typename T>
bool isEqualTo(const T &op1, const T &op2) {
	return op1 == op2;
}

class IntNumber {

	// the example won't work without this friend function 
	// because the compiler won't know how to compare two IntNumbers
	friend bool operator==(const IntNumber &n1, const IntNumber &n2) {
		return n1.number == n2.number;
	}

public:
	explicit IntNumber(int num = 5) {
		number = num;
	}
private:
	int number;
};

int main() {

	IntNumber number1(6);
	IntNumber number2;

	cout << "num1==num2? " << boolalpha << isEqualTo(number1, number2) <<
		"\nnum1!=num2? " << boolalpha << !isEqualTo(number1, number2) << endl;

	system("pause");
	return 0;
}