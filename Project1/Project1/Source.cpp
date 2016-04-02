#include <iostream>
#include <iomanip>
#include <conio.h>
#include "BasePlusCommissionEmployee.h"
using namespace std;


int main() {

	cout << fixed << setprecision(2);
	{
		{
			CommissionEmployee employee1(
				"Bob", "Lewis", "333-33-3333", 5000, .04);
		}
		cout << endl;
		BasePlusCommissionEmployee
			employee2("Lisa", "Jones", "555-55-5555", 2000, .06, 800);

		cout << endl;
		BasePlusCommissionEmployee
			employee3("Mark", "Sands", "888-88-8888", 8000, .15, 2000);
	}
	
	
	
	
	system("pause");
	return 0;
}


