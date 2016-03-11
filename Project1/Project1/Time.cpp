#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Time.h"
using namespace std;

Time::Time(int h, int m, int s) {
	time_t rawtime;
	struct tm *info;
	time(&rawtime);
	info = localtime(&rawtime);
	setTime(info->tm_hour, info->tm_min, info->tm_sec);
}

Time &Time::setTime(int h, int m, int s) {
	setHour(h);
	setMinute(m);
	setSecond(s);
	return *this; // enables cascading
}

Time &Time::setHour(int h) {
	hour = (h >= 0 && h < 24) ? h : 0;
	return *this; // enables cascading
}

Time &Time::setMinute(int m) {
	minute = (m >= 0 && m < 60) ? m : 0;
	return *this; // enables cascading
}

Time &Time::setSecond(int s) {
	second = (s >= 0 && s < 60) ? s : 0;
	return *this; // enables cascading
}

int Time::getHour() const {
	return hour;
}

int Time::getMinute() const {
	return minute;
}

int Time::getSecond() const {
	return second;
}

void Time::printUniversal() const {
	cout << setfill('0') << setw(2) << hour << ":"
		 << setw(2) << minute << ":" << setw(2) << second;
}

void Time::printStandard() const {
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
		<< ":" << setfill('0') << setw(2) << minute
		<< ":" << setw(2) << second << (hour < 12 ? " AM" : " PM");
}