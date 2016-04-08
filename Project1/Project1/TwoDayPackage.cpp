#include <iostream>
#include "TwoDayPackage.h"
using std::cout;
using std::endl;

TwoDayPackage::TwoDayPackage(
	const string &sName, const string &sAddress,
	const string &sCity, const string &sState, const string &sZIP,
	double wght, double costPOunce,
	const string &rName, const string &rAddress,
	const string &rCity, const string &rState, const string &rZIP,
	double fee)
	:Package(sName, sAddress, sCity, sState, sZIP,
		wght, costPOunce,
		rName, rAddress, rCity, rState, rZIP) {

	setFlatFee(fee);

}

void TwoDayPackage::setFlatFee(double fee) {
	flatFee = ((fee > 0) ? fee : 0);
}

double TwoDayPackage::getFlatFee() const {
	return flatFee;
}

double TwoDayPackage::calculateCost() const {
	return flatFee + Package::calculateCost();
}

void TwoDayPackage::printfPackageInfo() const {
	Package::printfPackageInfo();
	cout << "Flat fee: " << getFlatFee() << endl
		<< "Cost with flat fee: " << calculateCost() << endl;
}