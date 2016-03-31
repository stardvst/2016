#ifndef STRING_H
#define STRING_H

#include <iostream>
using namespace std;

class String {
	friend ostream &operator<<(ostream &, const String &);
	friend istream &operator>>(istream &, String &);
public:
	String(const char * = "");
	String(const String &);
	~String();

	const String &operator=(const String &);
	const String &operator+=(const String &);

	bool operator!() const;
	bool operator==(const String &) const;
	bool operator!=(const String &) const;
	bool operator<(const String &) const;
	bool operator>(const String &) const;
	bool operator<=(const String &) const;
	bool operator>=(const String &) const;

	char &operator[](const int); // subscript operator (modifiable lvalue)
	char operator[](const int) const; // subscript operator (rvalue)
	String operator()(const int, const int = 0) const; // return a substring
	int getLength() const;

private:
	int length;
	char *ptr;

	void setString(const char *);
};

#endif // !STRING_H
