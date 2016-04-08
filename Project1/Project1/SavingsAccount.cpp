#include "SavingsAccount.h"


SavingsAccount::SavingsAccount(double initial, double rate)
	:Account(initial) {
	interestRate = rate;
}

double SavingsAccount::calculateInterest() const {
	return interestRate * Account::getBalance();
}


