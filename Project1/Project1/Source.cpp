#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
using namespace std;

class Date {
public:
	Date() {};
	Date(int = 1, int = 1, int = 1900) {};
	void show() {
		cout << day << '/' << month << '/' << year << '\n';
	}
private:
	int day;
	int month;
	int year;
};

int main() {
	
	Date ob;
	Date ob1 = ob;

	cout << "ob: " << ob.show();

	system("pause");
	return 0;
}

