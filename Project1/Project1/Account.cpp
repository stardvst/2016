#include <iostream>
#include "Account.h"



Account::Account(double initial) {
	if (initial >= 0.0) {
		balance = initial;
	}
	else {
		balance = 0.0;
		std::cout << "Initial balance was invalid. Setting to 0.\n";
	}
}

void Account::credit(double amount) {
	balance += amount;
}

bool Account::debit(double amount) {
	if (amount <= balance) {
		balance -= amount;
		return true;
	}
	else {
		std::cout << "Debit amount exceeds account balance.\n";
		return false;
	}
}

double Account::getBalance() const {
	return balance;
}