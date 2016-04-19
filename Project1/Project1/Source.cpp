#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"
using namespace std;

int main() {

	cout << fixed << setprecision(2);

	vector <Package*> packages(2);

	packages[0] = new TwoDayPackage("Cion", "Ziou 15024", "Shanghai", "West", "0005",		// sender info
		2.36, 1.5,												// package info
		"Lilia", "Manta 10/1", "Yerevan", "Shengavit", "0006",	// recipient info
		0.35);													// fee

	packages[1] = new OvernightPackage(
		"Cion", "Ziou 15024", "Shanghai", "West", "0005",		// sender info
		2.36, 1.5,												// package info
		"Lilia", "Manta 10/1", "Yerevan", "Shengavit", "0006",	// recipient info
		1.2);													// fee per ounce

	double totalShippingCost = 0.0;

	for (size_t i = 0; i < packages.size(); i++) {
		cout << "Package " << i + 1 << ": " << endl
			<< "Sender's address: " << packages[i]->getSenderAddress() << endl
			<< "Recipient address: " << packages[i]->getRecipientAddress() << endl
			<< "Package cost: " << packages[i]->calculateCost() << endl << endl;
		totalShippingCost += packages[i]->calculateCost();
	}

	cout << "\nTotal shipping cost: " << totalShippingCost << endl;

	for (size_t j = 0; j < packages.size(); j++) {
		cout << "deleting obect of " <<
			typeid(*packages[j]).name() << endl;
		delete packages[j];
	}

	cin.get();
	return 0;
}