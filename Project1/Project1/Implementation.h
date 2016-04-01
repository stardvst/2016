#ifndef IMPLEMENTATION_H
#define IMPLEMENTATION_H

class Implementation {
public:
	Implementation(int v) :value(v) {
		// empty body
	}
	void setValue(int v) {
		value = v;
	}
	int getValue() const {
		return value;
	}
private:
	int value;
};

#endif // !IMPLEMENTATION_H
