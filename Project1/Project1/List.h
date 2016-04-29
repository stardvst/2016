#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h"
using namespace std;

template <typename NODETYPE>
class List {
public:
	List();
	~List();
	void insertAtFront(const NODETYPE &);
	void insertAtBack(const NODETYPE &);
	bool removeFromFront(NODETYPE &);
	bool removeFromBack(NODETYPE &);
	bool isEmpty() const;
	void print() const;
private:
	ListNode<NODETYPE> *first;
	ListNode<NODETYPE> *last;

	ListNode<NODETYPE> *createNewNode(const NODETYPE &);
};

template <typename NODETYPE>
List<NODETYPE>::List()
	:first(0), last(0) {
	// empty body
}

template <typename NODETYPE>
List<NODETYPE>::~List() {
	if (!isEmpty()) {
		cout << "Destroying nodes...\n";

		ListNode<NODETYPE> *current = first;
		ListNode<NODETYPE> *temp;

		while (current != 0) {
			temp = current;
			cout << temp->data << '\n';
			current = current->next;
			delete temp;
		}
	}
	cout << "All nodes destroyed.\n\n";
}

template <typename NODETYPE>
void List<NODETYPE>::insertAtFront(const NODETYPE &value) {
	ListNode<NODETYPE> *ptr = createNewNode(value);
	
	if (isEmpty()) {
		first = last = ptr;
	} else {
		ptr->next = first;
		first = ptr;
	}
}

template <typename NODETYPE>
void List<NODETYPE>::insertAtBack(const NODETYPE &value) {
	ListNode<NODETYPE> *ptr = createNewNode(value);

	if (isEmpty()) {
		first = last = ptr;
	}
	else {
		last->next = ptr;
		last = ptr;
	}
}

template <typename NODETYPE>
bool List<NODETYPE>::removeFromFront(NODETYPE &value) {
	if (isEmpty()) {
		return false;
	}
	else {
		ListNode<NODETYPE> *temp = first;
		
		if (first == last) {
			first = last = 0;
		} else {
			first = first->next;
		}

		value = temp->data;
		delete temp;
		return true;
	}
}

template <typename NODETYPE>
bool List<NODETYPE>::removeFromBack(NODETYPE &value) {
	if (isEmpty()) {
		return false;
	}
	else {
		ListNode<NODETYPE> *temp = last;

		if (first == last) {
			first = last = 0;
		}
		else {
			ListNode<NODETYPE> *current = first;

			while (current->next != last) {
				current = current->next;
			}

			last = current;
			current->next = 0;
		}

		value = temp->data;
		delete temp;
		return true;
	}
}

template <typename NODETYPE>
bool List<NODETYPE>::isEmpty() const {
	return first == 0;
}

template <typename NODETYPE>
ListNode<NODETYPE> *List<NODETYPE>::createNewNode(const NODETYPE &value) {
	return new ListNode<NODETYPE>(value);
}

template <typename NODETYPE>
void List<NODETYPE>::print() const {
	if (isEmpty()) {
		cout << "The list is empty.\n\n";
		return;
	}
	
	ListNode<NODETYPE> *current = first;
	cout << "The list is: ";
	while (current != 0) {
		cout << current->data << ' ';
		current = current->next;
	}
	cout << "\n\n";
}

#endif // !LIST_H