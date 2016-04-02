#include <iostream>
#include <iomanip>
#include "BasePlusCommissionEmployee.h"
using namespace std;


int main() {

	BasePlusCommissionEmployee employee(
		"Sue", "Jones", "222-22-2222", 5000, .04, 300);

	cout << fixed << setprecision(2);

	cout << "Employee information obtained by get functions: \n"
		<< "\nFirst name is " << employee.getFirstName()
		<< "\Last name is " << employee.getLastName()
		<< "\nSocial security number is "
		<< employee.getSocialSecurityNumber()
		<< "\nGross sales is " << employee.getGrossSales()
		<< "\nCommission rate is " << employee.getCommissionRate()
		<< "\nBase salary is " << employee.getBaseSalary() << endl;

	employee.setBaseSalary(1000); // set base salary

	cout << "\nUpdated employee information output by print function: \n" << endl;
	employee.print();

	cout << "\n\nEmployee's earnings: $" << employee.earnings() << endl;

	system("pause");
	return 0;
}


