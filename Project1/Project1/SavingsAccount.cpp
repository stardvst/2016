#include "SavingsAccount.h"

static double annualInterestRate;

SavingsAccount::SavingsAccount(int balance) {
	savingsBalance = balance;
}

double SavingsAccount::getSavingsBalance() const {
	return savingsBalance;
}

void SavingsAccount::calculateMonthlyInterest() {
	savingsBalance += (savingsBalance * (annualInterestRate / 12));
}

void SavingsAccount::modifyInterestRate(double newInterestRate) {
	annualInterestRate = newInterestRate;
}

