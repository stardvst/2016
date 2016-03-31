#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "String.h"
using namespace std;

String::String(const char *s)
	:length((s != 0) ? strlen(s) : 0) {
	cout << "Conversion (and default) constructor: " << s << endl;
	setString(s);
}

String::String(const String &copy)
	: length(copy.length) {
	cout << "Copy constructor: " << copy.ptr << endl;
	setString(copy.ptr);
}

String::~String() {
	cout << "Destructor " << ptr << endl;
	delete[] ptr;
}

const String &String::operator=(const String &right) {
	cout << "operator= called" << endl;
	if (&right != this) { // avoid self assignment
		delete[] ptr;
		length = right.length;
		setString(right.ptr);
	}
	else {
		cout << "Attempted assignment of a String to itself" << endl;
	}
	return *this;
}

const String &String::operator+=(const String &right) {
	size_t newLength = length + right.length;
	char *temp = new char[newLength + 1];

	strcpy(temp, ptr);
	strcpy(temp + length, right.ptr);

	delete[] ptr;
	ptr = temp;
	length = newLength;
	return *this;
}

bool String::operator!() const {
	return length == 0;
}

bool String::operator==(const String &right) const {
	return strcmp(ptr, right.ptr) == 0;
}

bool String::operator!=(const String &right) const {
	return !(*this == right);
}

bool String::operator<(const String &right) const {
	return strcmp(ptr, right.ptr) == -1;
}

bool String::operator<=(const String &right) const {
	return !(right < *this);
}

bool String::operator>(const String &right) const {
	return right < *this;
}

bool String::operator>=(const String &right) const {
	return !(*this < right);
}

char &String::operator[](const int subscript) {
	if (subscript < 0 || subscript >= length) {
		cerr << "Error. Subscript " << subscript <<
			" is out of range.\n";
		system("pause");
		exit(1);
	}
	return ptr[subscript]; // non-const return; modifiable lvalue
}

char String::operator[](const int subscript) const {
	if (subscript < 0 || subscript >= length) {
		cerr << "Error. Subscript " << subscript <<
			" is out of range.\n";
		system("pause");
		exit(1);
	}
	return ptr[subscript]; // returns copy of this element
}

String String::operator()(const int index, const int subLength) const {
	// if index is out of range or substring length < 0
	if (index < 0 || index >= length || subLength < 0) {
		return "";
	}

	// determine length of substring
	int len;
	if ((subLength == 0) || (index + subLength>length)) {
		len = length - index;
	}
	else {
		len = subLength;
	}

	// allocate temporary array for substring and '\0'
	char *temp = new char[length + 1];

	// copy substring into char array and terminate string
	strncpy(temp, &ptr[index], len);
	temp[len] = '\0';

	// create temporary String object containing the substring
	String tempString(temp);
	delete[] temp;
	return tempString; // return copy of the temporary String
}

int String::getLength() const {
	return length;
}

void String::setString(const char *s) {
	ptr = new char[length + 1];
	if (s != 0) {
		strcpy(ptr, s);
	}
	else {
		ptr[0] = '\0';
	}
}

ostream &operator<<(ostream &output, const String &s) {
	output << s.ptr;
	return output;
}

istream &operator>>(istream &input, String &s) {
	char temp[100];
	input >> setw(100) >> temp;
	s = temp; // use String class assignment operator
	return input;
}