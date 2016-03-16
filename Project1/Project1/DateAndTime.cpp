#include <iostream>
#include <iomanip>
#include "DateAndTime.h"
using namespace std;

static const int days[] =
{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

const char *months[] = { "", "January", "February", "March", "April", "May",
"June", "July", "August", "September", "October", "November", "December" };

DateAndTime::DateAndTime(int d, int mon, int y, int h, int min, int s) {
	// day error chaecking
	if (d >= 1 && d <= days[mon]) {
		day = d;
	}
	if (mon == 2 && d == 29 && (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))) { // leap year with 29.02.*
		day = 29;
	}
	else if (mon == 2 && d == 29 &&
		!(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))) { // not leap year with 29.02.*
		cout << y << " isn't a leap year.\n";
		cout << "Date set to default.\n";
		day = 1;
		month = 1;
		year = 2000;
		return;
	}
	// month error checking
	if (mon >= 1 && mon <= 12) {
		month = mon;
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
	// hour error checking
	if (h >= 0 && h < 24) {
		hour = h;
	} else {
		cout << "Invalid hour. Hour set to 00.\n";
		hour = 0;
	}
	// minute error checking
	if (min >= 0 && min < 60) {
		minute = min;
	} else {
		cout << "Invalid minute. Minute set to 00.\n";
		minute = 0;
	}
	// second error checking
	if (s >= 0 && s < 60) {
		second = s;
	} else {
		cout << "Invalid second. Second set to 00.\n";
		second = 0;
	}
}

void DateAndTime::tick() {
	if ((minute == 59) && (second == 59)) {
		if (hour < 23) {
			hour++;
			minute = second = 0;
		}
		else {
			hour = minute = second = 0;
			nextDay();
		}
	}
	else if (minute == 59) {
		second++;
	}
	else if (second == 59) {
		minute++;
		second = 0;
	}
	else {
		second++;
	}
	cout << "One second later: " << setfill('0') << setw(2) << day << '/'
		<< setw(2) << month << '/' << year << ' ' <<
		((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
		<< setw(2) << minute << ":" << setw(2) << second << (hour < 12 ? " AM" : " PM") << "\n\n";
}

void DateAndTime::nextDay() {
	if (day == 31 && month == 12) {
		day = 1;
		month = 1;
		year++;
	}
	else if ((month == 2 && day == 29 && (year % 400 == 0 ||
		(year % 4 == 0 && year % 100 != 0))) || // leap year 
		(day == days[month]) && !(year % 400 == 0 ||
			(year % 4 == 0 && year % 100 != 0))) { // not a leap year
		day = 1;
		month++;
	}
	else {
		day++;
	}
}

void DateAndTime::printUniversal() const {
	cout << setfill('0') << setw(2) << day << '/' << setw(2) <<
		month << '/' << year << ' ' << hour << ":" << setw(2) <<
		minute << ":" << setw(2) << second << '\n';
}

void DateAndTime::printStandard() const {
	cout << months[month] << ' ' << day << ", " << year << ' ' <<
		setfill('0') << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":" << setw(2) <<
		minute << ":" << setw(2) << second << (hour < 12 ? " AM" : " PM") << '\n';
}