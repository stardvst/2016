#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
using namespace std;

class Stack {
public:
	void push(char c) {

	}
	char pop() {

	}
	void input() {

	}
	void show() {

	}
	void instructions() {
		cout << "Enter your choice:\n" <<
			"   1 to insert an element into the stack.\n"
			"   2 to delete an element from the stack.\n"
			"   3 to end.\n";
	}
private:
	char c;
	Stack *next;
};

int main() {
	
	Stack stack;
	Stack *top = &stack;
	int choice;
	char value;

	stack.instructions();
	cin >> choice;

	while (choice != 3) {
		switch (choice) {
			case 1: 
				cout << "Enter a char: ";
				cin >> value;
				stack.push(value);
				break;
			case 2:

		}
	}

	system("pause");
	return 0;
}

