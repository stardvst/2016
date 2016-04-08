#include "CheckingAccount.h"



CheckingAccount::CheckingAccount(double initial, double fee)
	:Account(initial) {
	feePerTransaction = fee;
}

void CheckingAccount::credit(double amount) {
	Account::credit(amount);
	Account::debit(feePerTransaction);
}

void CheckingAccount::debit(double amount) {
	if (Account::debit(amount)) {
		Account::debit(feePerTransaction);
	}
}