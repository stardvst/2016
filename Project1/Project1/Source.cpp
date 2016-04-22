#include <iostream>
using namespace std;

template <typename T>
void printArray(const T *const array, int count) {
	for (int i = 0; i< count; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void printArray(const char *const array, int count) {
	for (int i = 0; i < count; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int main() {

	char *arrayOfChar[] = { "Happy", "New", "Year" };
	printArray(arrayOfChar, 3);

	system("pause");
	return 0;
}