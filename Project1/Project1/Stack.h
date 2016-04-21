#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
public:
	explicit Stack(int = 10);
	~Stack() {
		delete[] ptrStack;
	}

	bool push(const T &);
	bool pop(T &);

	bool isEmpty() const {
		return top == -1;
	}

	bool isFull() const {
		return top == size - 1;
	}

private:
	int size;
	int top;
	T *ptrStack; // pointer to internal representation of the Stack
};

#endif // !STACK_H


template <typename T>
Stack<T>::Stack(int s)
	:size(s > 0 ? s : 10),
	top(-1),
	ptrStack(new T[size]) {
	// empty body
}

template <typename T> 
bool Stack<T>::push(const T &pushValue) {
	if (!isFull()) {
		ptrStack[++top] = pushValue;
		return true;
	}
	return false;
}

template <typename T> 
bool Stack<T>::pop(T &popValue) {
	if (!isEmpty()) {
		popValue = ptrStack[top--];
		return true;
	}
	return false;
}