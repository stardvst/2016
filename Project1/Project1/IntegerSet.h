#ifndef INTEGERSET_H
#define INTEGERSET_H

class IntegerSet {
public:
	IntegerSet();
	IntegerSet(int [], const int);
	IntegerSet unionOfSets(const IntegerSet &) const;
	IntegerSet intersectionOfSets(const IntegerSet &) const;
	void insertElement(const int);
	void deleteElement(const int);
	void printSet(int []) const;
	bool isEqualTo(const IntegerSet &) const;
private:
	bool set[100];
};

#endif // !INTEGERSET_H
