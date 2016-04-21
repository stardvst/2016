#include <iostream>
using namespace std;

template <typename T>
void selectionSort(T *array, const int count) {
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - 1; j++) {
			if (array[j] > array[j + 1]) {
				T temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int main() {

	int intArray[5];
	double doubleArray[5];

	// int array
	for (int i = 0; i < 5; i++) {
		cout << "Enter intArray[" << i << "]: ";
		cin >> intArray[i];
	}
	
	selectionSort(intArray, 5);

	cout << "\nintArray sorted:\n";
	for (int i = 0; i < 5; i++) {
		cout << "Enter intArray[" << i << "]: " << intArray[i] << endl;
	}
	cout << "\n\n";

	// double array
	for (int i = 0; i < 5; i++) {
		cout << "Enter doubleArray[" << i << "]: ";
		cin >> doubleArray[i];
	}

	selectionSort(doubleArray, 5);

	cout << "\n\ndoubleArray sorted:\n";
	for (int i = 0; i < 5; i++) {
		cout << "Enter doubleArray[" << i << "]: " << doubleArray[i] << endl;
	}


	system("pause");
	return 0;
}