#include <iostream>
#include "BasePlusCommissionEmployee.h"
using std::cout;


BasePlusCommissionEmployee::BasePlusCommissionEmployee(
	const string &first, const string &last, const string &ssn,
	double sales, double rate, double salary)
	: CommissionEmployee(first, last, ssn, sales, rate) {
	setBaseSalary(salary);

	cout << "BasePlusCommissionEmployee constructor:\n";
	print();
	cout << "\n\n";
}
 
BasePlusCommissionEmployee::~BasePlusCommissionEmployee() {
	cout << "BasePlusCommissionEmployee destructor:\n";
	print();
	cout << "\n\n";
}

void BasePlusCommissionEmployee::setBaseSalary(double salary) {
	baseSalary = (salary < 0.0) ? 0.0 : salary;
}

double BasePlusCommissionEmployee::getBaseSalary() const {
	return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const {
	return baseSalary + CommissionEmployee::earnings();
}

void BasePlusCommissionEmployee::print() const {
	std::cout << "base-salaried ";
	CommissionEmployee::print();
	std::cout << "\nbase salary: " << getBaseSalary();
}