#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
#include "HourlyEmployee.h"
using namespace std;

int main() {

	cout << fixed << setprecision(2);

	vector <Employee*> employees(4);

	employees[0] = new SalariedEmployee(
		"John", "Smith", "111-11-1111", 800);
	employees[1] = new HourlyEmployee(
		"Karen", "Price", "222-22-2222", 16.75, 40);
	employees[2] = new CommissionEmployee(
		"Sue", "Jones", "333-33-3333", 10000, .06);
	employees[3] = new BasePlusCommissionEmployee(
		"Bob", "Lewis", "444-44-4444", 5000, .04, 300);

	for (size_t i = 0; i < employees.size(); i++) {
		employees[i]->print();
		cout << endl;

		BasePlusCommissionEmployee *ptrDerived =
			dynamic_cast<BasePlusCommissionEmployee*>(employees[i]);

		if (ptrDerived != 0) {
			double oldBaseSalary = ptrDerived->getBaseSalary();
			cout << "old base salary: $" << oldBaseSalary << endl;
			ptrDerived->setBaseSalary(1.10 * oldBaseSalary);
			cout << "new base salary with 10% increase is: $"
				<< ptrDerived->getBaseSalary() << endl;
		}

		cout << "earned: $" << employees[i]->earnings() << "\n\n";
	}

	for (size_t j = 0; j < employees.size(); j++) {
		cout << "deleting object of " <<
			typeid(*employees[j]).name() << endl;
		delete employees[j];
	}

	system("pause");
	return 0;
}