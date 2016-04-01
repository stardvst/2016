#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

const int Date::days[] =
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

/* user defined data */
Date::Date(int d, int m, int y) {
	setDate(d, m, y);
}

void Date::setDate(int dd, int mm, int yy) {
	month = (mm >= 1 && mm <= 12) ? mm : 1;
	year = (yy >= 1900 && yy <= 2100) ? yy : 1900;

	// test for a leap year
	if (month == 2 & isLeapYear(year)) {
		day = (dd >= 1 && dd <= 29) ? dd : 1;
	} else {
		day = (dd >= 1 && dd <= days[month]) ? dd : 1;
	}
}

Date &Date::operator++() {
	helpIncrement();
	return *this;
}

Date Date::operator++(int) { // the dummy integer parameter does not have a parameter name
	Date temp = *this;
	helpIncrement();
	return temp;
}

const Date &Date::operator+=(const int additionalDays) {
	for (int i = 0; i < additionalDays; i++) {
		helpIncrement();
	}
	return *this;
}

bool Date::isLeapYear(const int testYear) {
	if (testYear % 400 == 0 ||
		(testYear % 100 != 0 && testYear % 4 == 0)) {
		return true;
	}
	else {
		return false;
	}
}

bool Date::endOfMonth(const int testDay) const {
	if (month == 2 && isLeapYear(year)) {
		return testDay == 29;
	}
	else {
		return testDay == days[month];
	}
}

void Date::helpIncrement() {
	if (!endOfMonth(day)) {
		day++;
	}
	else {
		if (month < 12) { // day is end of month and month < 12
			day = 1;
			month++;
		}
		else { // last day of year
			day = 1;
			month = 1;
			year++;
		}
	}
}

ostream &operator<<(ostream &output, const Date &d) {
	static string monthName[13] = { "", "January", "February",
		 "March", "April", "May", "June", "July", "August",
		 "September", "October", "November", "December" };
	output << monthName[d.month] << ' ' << d.day << ", " << d.year << endl;
	return output;
}