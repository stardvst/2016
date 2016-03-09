#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
using namespace std;

class Triangle {
public:
	Triangle() {};
	~Triangle() {};
	void setBase(double b) {
		base = b;
	}
	void setHeight(double h) {
		height = h;
	}
private:
	double base;
	double height;
};

Triangle input() {
	Triangle object;
	double b, h;
	cout << "Enter base: ";
	cin >> b;
	object.setHeight(b);
	cout << "Enter height: ";
	cin >> h;
	object.setHeight(h);
	cout << "S = (base * height) / 2 = " << (b * h) / 2 << "\n";
	return object;
}

int main() {
	
	Triangle t1 = input();
	
	system("pause");
	return 0;
}

