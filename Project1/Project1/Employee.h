#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
public:
	Employee(const string &, const string &);
	~Employee();
	string getFirstName() const;
	string getlastName() const;
	// static member function
	static int getCount();
private:
	string firstName;
	string lastName;
	// static data
	static int count;
};

#endif // !EMPLOYEE_H

