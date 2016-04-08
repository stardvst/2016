#include <iostream>
#include "OvernightPackage.h"
using std::cout;
using std::endl;


OvernightPackage::OvernightPackage(
	const string &sName, const string &sAddress,
	const string &sCity, const string &sState, const string &sZIP,
	double wght, double costPOunce,
	const string &rName, const string &rAddress,
	const string &rCity, const string &rState, const string &rZIP,
	double feePOunce)
	:Package(sName, sAddress, sCity, sState, sZIP,
		wght, costPOunce,
		rName, rAddress, rCity, rState, rZIP) {

	setFeePerOunce(feePOunce);
	
}

void OvernightPackage::setFeePerOunce(double feePOunce) {
	feePerOunce = ((feePOunce > 0) ? feePOunce : 0);
}

double OvernightPackage::getFeePerOunce() const {
	return feePerOunce;
}

double OvernightPackage::calculateCost() const {
	return (Package::getCostPerOunce() + getFeePerOunce()) * Package::getWeight();
}

void OvernightPackage::printfPackageInfo() const {
	Package::printfPackageInfo();
	cout << "Fee per ounce: " << getFeePerOunce() << endl
		<< "Cost with fee per ounce: " << calculateCost() << endl;
}
