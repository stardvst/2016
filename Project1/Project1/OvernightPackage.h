#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"

class OvernightPackage :public Package {
public:
	OvernightPackage(const string &, const string &, const string &, const string &, const string &,
		double, double,
		const string &, const string &, const string &, const string &, const string &,
		double);
	void setFeePerOunce(double);
	double getFeePerOunce() const;
	double calculateCost() const;
	void printfPackageInfo() const;
private:
	double feePerOunce;
};

#endif // !OVERNIGHTPACKAGE_H
