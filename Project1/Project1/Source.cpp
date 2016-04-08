#include <iostream>
#include "SavingsAccount.h"
#include "CheckingAccount.h"
using namespace std;



int main() {

	SavingsAccount account(1500, 0.1);
	cout << "Loading account...\nInitial balance: " << account.getBalance() << endl;
	double interest = account.calculateInterest();
	cout << "Interest: " << interest << endl;
	account.credit(interest);
	cout << "Adding interest to balance..." << endl;
	cout << "Balance: " << account.getBalance() << endl << endl;

	CheckingAccount check(1000, 100);
	cout << "Checking account...\nInitial balance: " << check.getBalance() << endl;
	cout << "Adding amount to balance..." << endl;
	check.credit(150);
	cout << "Balance: " << check.getBalance() << endl;
	cout << "Deducting invalid amount from balance..." << endl;
	check.debit(2500);
	cout << "Deducting valid amount (+fee) from balance..." << endl;
	check.debit(500);
	cout << "Balance: " << check.getBalance() << endl;

	system("pause");
	return 0;
}


