#include <iostream>
#include "SavingsAccount.h"
using namespace std;

int main() {
	
	SavingsAccount saver1(2000);
	SavingsAccount saver2(3000);

	saver1.modifyInterestRate(0.03);
	saver1.calculateMonthlyInterest();
	cout << "Monthly interest for saver1: " << saver1.getSavingsBalance() << "\n\n";

	saver2.modifyInterestRate(0.03);
	saver2.calculateMonthlyInterest();
	cout << "Monthly interest for saver2: " << saver2.getSavingsBalance() << "\n\n";

	saver1.modifyInterestRate(0.04);
	saver2.calculateMonthlyInterest();
	cout << "Monthly interest for saver1: " << saver1.getSavingsBalance() << "\n\n";

	saver2.modifyInterestRate(0.04);
	saver2.calculateMonthlyInterest();
	cout << "Monthly interest for saver2: " << saver2.getSavingsBalance() << "\n\n";

	system("pause");
	return 0;
}

