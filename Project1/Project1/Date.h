#ifndef DATE_H
#define DATE_H

class Date {
public:
	Date(int = 1, int = 1, int = 2000);
	void nextDay();
	void print();
private:
	int day;
	int month;
	int year;
};

#endif // !DATE_H

