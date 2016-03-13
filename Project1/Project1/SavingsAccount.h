#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount {
public:
	SavingsAccount(int);
	~SavingsAccount() {};

	double getSavingsBalance() const;

	void calculateMonthlyInterest();
	static void modifyInterestRate(double);
private:
	double savingsBalance;
};

#endif // !SAVINGSACCOUNT_H

