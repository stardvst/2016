#ifndef DATE_H
#define DATE_H

class Date {
public:
	Date(); 
	Date(int, int, int);
	Date(int, int);
	void formatDDDYYYY() const;
	void formatMMDDYY() const;
	void displayInTextFormat() const;
private:
	int day;
	int month;
	int year;
};

#endif // !DATE_H

