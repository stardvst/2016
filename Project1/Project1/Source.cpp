#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void outputLine(int account, const string name, double balance) {
	cout << left << setw(10) << account << setw(13) << name
		<< setw(7) << setprecision(2) << right << balance << endl;
}

int main() {

	ifstream inClientFile("clients.txt", ios::in);
	if (!inClientFile) {
		cerr << "File could not be opened" << endl;
		exit(1);
	}

	int account;
	string name;
	double balance;

	cout << left << setw(10) << "Account" << setw(13)
		<< "Name" << "Balance" << endl << fixed << showpoint;

	while (inClientFile >> account >> name >> balance) {
		outputLine(account, name, balance);
	}


	cin.get();
	return 0;
}