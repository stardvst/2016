#include <iostream>
#include "Date.h"
using namespace std;

static const int days[] =
{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(int d, int m, int y) {
	// day error chaecking
	if (d >= 1 && d <= days[m]) {
		day = d;
	}
	if (m == 2 && d == 29 && (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))) { // leap year with 29.02.*
		day = 29;
	} else if (m == 2 && d == 29 && 
		!(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))) { // not leap year with 29.02.*
		cout << y << " isn't a leap year.\n";
		cout << "Date set to default.\n";
		day = 1;
		month = 1;
		year = 2000;
		return;
	}
	// month error checking
	if (m >= 1 && m <= 12) {
		month = m;
	} else {
		month = 1;
		cout << "Invalid month. Month set to 1.\n";
	}
	// year error checking
	if (y >= 1900 && y <= 2100) {
		year = y;
	} else {
		cout << "Invalid year. Year set to 1900.\n";
	}
}

void Date::nextDay() {
	if (day == 31 && month == 12) {
		day = 1;
		month = 1;
		year++;
	} else if ((month == 2 && day == 29 && (year % 400 == 0 || 
		(year % 4 == 0 && year % 100 != 0))) || // leap year 
		(day == days[month]) && !(year % 400 == 0 ||
			(year % 4 == 0 && year % 100 != 0))) { // not a leap year
		day = 1;
		month++;
	} else {
		day++;
	}
}

void Date::print() {
	cout << day << "/" << month << "/" << year << "\n";
}