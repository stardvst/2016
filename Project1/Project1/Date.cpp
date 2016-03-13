#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Date.h"
using namespace std;

static const int days[] =
{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

/* user defined data */
Date::Date(int d, int m, int y) {
	// day error chaecking
	if (d >= 1 && d <= days[m]) {
		day = d;
	}
	if (m == 2 && d == 29 && (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))) { // leap year with 29.02.*
		day = 29;
	}
	else if (m == 2 && d == 29 &&
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
	}
	else {
		month = 1;
		cout << "Invalid month. Month set to 1.\n";
	}
	// year error checking
	if (y >= 1900 && y <= 2100) {
		year = y;
	}
	else {
		cout << "Invalid year. Year set to 1900.\n";
	}
}

Date::Date(int dayCount, int y) {
	int month = 1;
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
		if (dayCount >= 1 && dayCount <= 366) {
			day = 0;
			do {
				dayCount -= days[month];
				month++;
			} while (dayCount >= days[month]);
		}
		day = (month >= 3) ? --dayCount : dayCount;
	}
	else {
		if (dayCount >= 1 && dayCount <= 365) {
			day = 0;
			do {
				dayCount -= days[month];
				month++;
			} while (dayCount >= days[month]);
		}
		else if (dayCount == 366) {
			cout << y << " isn't a leap year. Date defaulted.\n";
			day = 1;
			Date::month = 1;
			year = 2000;
			return;
		}
		day = dayCount;
	}
	Date::month = month;
	year = y;
}

/* system defined data */
Date::Date() {
	time_t rawtime;
	struct tm *info;
	time(&rawtime);
	info = localtime(&rawtime);
	day = info->tm_mday; // not sure  
	month = info->tm_mon + 1; // tm_mon is [0, 11]
	year = info->tm_year + 1900; // tm_year is the years since 1900
}

void Date::formatDDDYYYY() const {
	int dayCount = 0;
	for (int i = 0; i < month; i++) {
		dayCount += days[i];
	}
	if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && month >= 3) {
		dayCount++;
	}
	dayCount += day;
	cout << "Date in DDD-YYYY format: " << setfill('0') << setw(3) <<
		dayCount << "-" << year << '\n';
}

void Date::formatMMDDYY() const {
	cout << "Date in MM/DD/YY format: " << setfill('0') << setw(2) << month << '/'
		<< setw(2) << day << '/' << setw(2) << year % 100 << '\n';
}

void Date::displayInTextFormat() const {
	const char *months[] =	{ "", "January", "February", "March", "April", "May",
		"June", "July", "August", "September", "October", "November", "December" };
	cout << "Date in text format: " << months[month] << " " << day << ", " << year << '\n';
}