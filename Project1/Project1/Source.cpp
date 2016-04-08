#include <iostream>
#include "TwoDayPackage.h"
#include "OvernightPackage.h"
using namespace std;



int main() {

	Package package1(
		"Cion", "Ziou 15024", "Shanghai", "West", "0005",		// sender info
		2.36, 1.5,												// package info
		"Lilia", "Manta 10/1", "Yerevan", "Shengavit", "0006");	// recipient info

	TwoDayPackage package2(
		"Cion", "Ziou 15024", "Shanghai", "West", "0005",		// sender info
 		2.36, 1.5,												// package info
		"Lilia", "Manta 10/1", "Yerevan", "Shengavit", "0006",	// recipient info
		0.35);													// fee

	OvernightPackage package3(
		"Cion", "Ziou 15024", "Shanghai", "West", "0005",		// sender info
		2.36, 1.5,												// package info
		"Lilia", "Manta 10/1", "Yerevan", "Shengavit", "0006",	// recipient info
		1.2);													// fee per ounce
		
	cout << "Ordinary package:" << endl;
	package1.printfPackageInfo();
	cout << endl << "Two Day Package:" << endl;
	package2.printfPackageInfo();
	cout << endl << "Overnight Package:" << endl;
	package3.printfPackageInfo();

	system("pause");
	return 0;
}


