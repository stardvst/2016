#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
#include "Shape.h"
#include "TwoDimensionalShape.h"
#include "ThreeDimensionalShape.h"
#include "Circle.h"
#include "Pyramid.h"
using namespace std;

int main() {

	cout << fixed << setprecision(2);

	vector <Shape*> shapes(2);

	shapes[0] = new Circle(5);
	shapes[1] = new Pyramid(1, 3, 4);

	for (size_t i = 0; i < shapes.size(); i++) {
		TwoDimensionalShape *twoDimensional =
			dynamic_cast<TwoDimensionalShape*>(shapes[i]);
		ThreeDimensionalShape *threeDimensional =
			dynamic_cast<ThreeDimensionalShape*>(shapes[i]);

		if (twoDimensional != 0) {
			twoDimensional->print();
			cout << endl;
		}
		else if (threeDimensional != 0) {
			threeDimensional->print();
			cout << endl;
		}
	}

	cout << endl;

	for (size_t j = 0; j < shapes.size(); j++) {
		cout << "deleting obect of " <<
			typeid(*shapes[j]).name() << endl;
		delete shapes[j];
	}

	cin.get();
	return 0;
}