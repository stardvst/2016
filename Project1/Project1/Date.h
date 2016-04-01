#ifndef DATE_H
#define DATE_H

#include <iostream>
using std::ostream;

class Date {
	friend ostream &operator<<(ostream &, const Date &);
public:
	Date(int = 1, int = 1, int = 1990);
	void setDate(int, int, int);
	Date &operator++(); // prefix increment operator
	Date operator++(int); // postfix increment operator
	const Date &operator+=(const int); // add days, modify object
	static bool isLeapYear(const int); // is date in a leap year?
	bool endOfMonth(const int) const; 
private:
	int day;
	int month;
	int year;

	static const int days[];
	void helpIncrement();
};

#endif // !DATE_H

