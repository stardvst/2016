//#include <stdio.h>
//#include <conio.h>
//
//int main() {
//
//	int account;
//	char name[30];
//	float balance;
//
//	FILE *ptr;
//
//	if ((ptr = fopen("clients.dat", "w")) == NULL) {
//		printf("File could not be opened\n");
//	}
//	else {
//		printf("Enter the account, name, and balance.\n");
//		printf("Enter EOF to end input.\n? ");
//		scanf("%d", &account);
//
//		while (!feof(stdin)) {
//			scanf("%s%f", name, &balance);
//			fprintf(ptr, "%d %s %.2f\n", account, name, balance);
//			printf("? ");
//			scanf("%d", &account);
//		}
//		fclose(ptr);
// 	}
//
//	return 0;
//}


//int main() {
//
//	int account;
//	char name[30];
//	float balance;
//
//	FILE *ptr;
//
//	if ((ptr = fopen("clients.dat", "r")) == NULL) {
//		printf("File could not be opened\n");
//	}
//	else {
//		printf("%-10s%-13s%s\n", "Account", "Name", "Balance");
//		fscanf(ptr, "%d%s%f", &account, name, &balance);
//		while (!feof(ptr)) {
//			printf("%-10d%-13s%7.2f\n", account, name, balance);
//			fscanf(ptr, "%d%s%f", &account, name, &balance);
//		}
//		fclose(ptr);
//	}
//
//	getch();
//	return 0;
//}


//int main() {
//
//	int request;
//	int account;
//	char name[30];
//	float balance;
//	FILE *ptr;
//
//	if ((ptr = fopen("clients.dat", "r")) == NULL) {
//		printf("File could not be opened\n");
//	}
//	else {
//		printf("Enter request\n"
//			" 1 - List accounts with zero balances\n"
//			" 2 - List accounts with credit balances\n"
//			" 3 - List accounts with debit balances\n"
//			" 4 - End of run\n? ");
//		scanf("%d", &request);
//		while (request != 4) {
//			fscanf(ptr, "%d%s%f", &account, name, &balance);
//			switch (request) {
//			case 1:
//				printf("\nAccounts with zero balances:\n");
//				while (!feof(ptr)) {
//					if (balance == 0) {
//						printf("%-10d%-13s%7.2f\n", account, name, balance);
//					}
//					fscanf(ptr, "%d%s%f", &account, name, &balance);
//				}
//				break;
//			case 2:
//				printf("\nAccounts with credit balances:\n");
//				while (!feof(ptr)) {
//					if (balance < 0) {
//						printf("%-10d%-13s%7.2f\n", account, name, balance);
//					}
//					fscanf(ptr, "%d%s%f", &account, name, &balance);
//				}
//				break;
//			case 3:
//				printf("\nAccounts with debit balances:\n");
//				while (!feof(ptr)) {
//					if (balance > 0) {
//						printf("%-10d%-13s%7.2f\n", account, name, balance);
//					}
//					fscanf(ptr, "%d%s%f", &account, name, &balance);
//				}
//				break;
//			}
//			rewind(ptr);
//			printf("\n? ");
//			scanf("%d", &request);
//		}
//		printf("End of run.\n");
//		fclose(ptr);
//	}
//	
//	return 0;
//}


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