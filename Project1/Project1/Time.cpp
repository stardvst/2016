#include <iostream>
#include <iomanip>
#include "Time.h"
using namespace std;

Time::Time(int h, int m, int s) {
	setTime(h, m, s);
}

void Time::setTime(int h, int m, int s) {
	setHour(h);
	setMinute(m);
	setSecond(s);
}

void Time::setHour(int h) {
	hour = (h >= 0 && h < 24) ? h : 0;
}

void Time::setMinute(int m) {
	minute = (m >= 0 && m < 60) ? m : 0;
}

void Time::setSecond(int s) {
	second = (s >= 0 && s < 60) ? s : 0;
}

int Time::getHour() {
	return hour;
}

int Time::getMinute() {
	return minute;
}

int Time::getSecond() {
	return second;
}

void Time::tick() {
	if ((minute == 59) && (second == 59)) {
		if (hour < 23) {
			hour++;
			minute = second = 0;
		}
		else {
			hour = minute = second = 0;
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
	cout << "One second later: " << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":" << setfill('0')
		<< setw(2) << getMinute() << ":" << setw(2) << getSecond() << (hour < 12 ? " AM" : " PM") << "\n\n";
}

void Time::printUniversal() {
	cout << setfill('0') << setw(2) << getHour() << ":" << setw(2) << 
		getMinute() << ":" << setw(2) << getSecond();
}

void Time::printStandard() {
	cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":" << setfill('0')
		<< setw(2) << getMinute() << ":" << setw(2) << getSecond() 
		<< (hour < 12 ? " AM" : " PM") << "\n";
}

int Time::secondsSinceMidnight() const {
	return hour * 60 * 60 + minute * 60 + second;
}