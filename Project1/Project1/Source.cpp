#include <iostream>
#include <iomanip>
using namespace std;


int main() {
	
	const int arraySize = 10;
	int data[arraySize] = { 34, 56, 4, 10, 77, 51, 93, 30, 5, 52 };
	int insert;


	cout << "Unsorted array:\n";
	for (int i = 0; i < arraySize; ++i) {
		cout << setw(4) << data[i];
	}
		
	/* insertion sort */
	for (int next = 1; next < arraySize; ++next) {
		insert = data[next]; // store the value in the current element
		int moveItem = next; // initialize location to place element

		// search for the location in which to put the current element
		while ((moveItem > 0) && (data[moveItem - 1] > insert)) { 
			data[moveItem] = data[moveItem - 1]; // shift element one slot to the right
			moveItem--;
		}

		data[moveItem] = insert; // place inserted element into the array
	}

	cout << "\nSorted array:\n";
	for (int i = 0; i < arraySize; ++i) {
		cout << setw(4) << data[i];
	}


	cin.get();
	return 0;
}