#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "HourlyEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
using namespace std;

void virtualViaPointer(const Employee *const);
void virtualViaReference(const Employee &);

int main() {

	cout << fixed << setprecision(2);

	SalariedEmployee salariedEmployee(
		"John", "Smith", "111-11-1111", 800);
	HourlyEmployee hourlyEmployee(
		"Karen", "Price", "222-22-2222", 16.75, 40);
	CommissionEmployee commissionEmployee(
		"Sue", "Jones", "333-33-3333", 10000, .06);
	BasePlusCommissionEmployee basePlusCommissionEmployee(
		"Bob", "Lewis", "444-44-4444", 5000, .04, 300);
	
	cout << "Employees processed individually using static binding:\n\n";

	salariedEmployee.print();
	cout << "\nearned $" << salariedEmployee.earnings() << "\n\n";
	hourlyEmployee.print();
	cout << "\nearned $" << hourlyEmployee.earnings() << "\n\n";
	commissionEmployee.print();
	cout << "\nearned $" << commissionEmployee.earnings() << "\n\n";
	basePlusCommissionEmployee.print();
	cout << "\nearned $" << basePlusCommissionEmployee.earnings() << "\n\n";

	
	vector <Employee*> employees(4);
	employees[0] = &salariedEmployee;
	employees[1] = &hourlyEmployee;
	employees[2] = &commissionEmployee;
	employees[3] = &basePlusCommissionEmployee;

	// call virtualViaPointer to print each Employee's information
	// and earnings using dynamic binding
	cout << "Employees processed polymorphically via dynamic binding:\n\n";
	for (size_t i = 0; i < employees.size(); i++) {
		virtualViaPointer(employees[i]);
	}

	// call virtualViaReference to print each Employee's information
	// and earnings using dynamic binding
	cout << "Virtual function calls made off base-class references:\n\n";
	for (size_t i = 0; i < employees.size(); i++) {
		virtualViaReference(*employees[i]); // note dereferencing
	} 

	system("pause");
	return 0;
}


void virtualViaPointer(const Employee *const baseClassPointer) {
	baseClassPointer->print();
	cout << "\nearned: $" << baseClassPointer->earnings() << "\n\n";
}

void virtualViaReference(const Employee &baseClassReference) {
	baseClassReference.print();
	cout << "\nearned: $" << baseClassReference.earnings() << "\n\n";
}