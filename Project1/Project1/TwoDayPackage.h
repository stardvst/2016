#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"

class TwoDayPackage :public Package {
public:
	TwoDayPackage(const string &, const string &, const string &, const string &, const string &,
		double, double,
		const string &, const string &, const string &, const string &, const string &,
		double);
	void setFlatFee(double);
	double getFlatFee() const;
	double calculateCost() const;
	void printfPackageInfo() const;
private:
	double flatFee;
};
	 
#endif // !TWODAYPACKAGE_H
