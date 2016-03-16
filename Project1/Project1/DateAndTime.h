#ifndef DATEANDTIME_H
#define DATEANDTIME_H

class DateAndTime {
public:
	DateAndTime(int, int, int, int, int, int);
	void tick();
	void printUniversal() const;
	void printStandard() const;
private:
	int second;
	int minute;
	int hour;
	int day;
	int month;
	int year;
	void nextDay();
};

#endif // !DATEANDTIME_H

