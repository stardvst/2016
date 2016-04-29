#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;


int main() {
	
	ofstream outClientFile("clients.txt", ios::app);
	if (!outClientFile) {
		cerr << "File could not be opened" << endl;
		exit(1);
	}
	
	cout << "Enter the account, name, and balance." << endl
		<< "Enter end-of-file to end input.\n? ";

	int account;
	string name;
	double balance;

	while (cin >> account >> name >> balance) {
		outClientFile << account << ' ' << name << ' ' << balance << endl;
		cout << "? ";
	}

	cin.get();
	return 0;
}