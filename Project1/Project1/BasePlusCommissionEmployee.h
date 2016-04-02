#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string>
#include "CommissionEmployee.h"

class BasePlusCommissionEmployee :public CommissionEmployee {
public:
	BasePlusCommissionEmployee(const string &, const string &,
		const string &, double = 0.0, double = 0.0, double = 0.0);
	void setBaseSalary(double);
	double getBaseSalary() const;
	double earnings() const;
	void print() const;
private:
	double baseSalary;
};
 
#endif // !BASEPLUS_H

