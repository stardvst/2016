#ifndef INTERFACE_H
#define INTERFACE_H

class Implementation; // forward class declaration

class Interface {
public:
	Interface(int);
	~Interface();
	void setValue(int v);
	int getValue() const;
private:
	Implementation *ptr;
};

#endif // !INTERFACE_H

