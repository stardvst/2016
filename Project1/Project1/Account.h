#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
public:
	explicit Account(double);
	void credit(double);
	bool debit(double);
	double getBalance() const;
private:
	double balance;
};

#endif // !ACCOUNT_H
