#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H

class HugeInteger {
public:
	void input();
	void output() const;

	HugeInteger add(const HugeInteger &) const;
	HugeInteger subtract(const HugeInteger &) const;
	HugeInteger multiply(const HugeInteger &) const;
	HugeInteger divide(const HugeInteger &) const;
	HugeInteger modulus(const HugeInteger &) const;

	bool isEqualTo(const HugeInteger &) const;
	bool isNotEqualTo(const HugeInteger &) const;
	bool isGreaterThan(const HugeInteger &) const;
	bool isLessThan(const HugeInteger &) const;
	bool isGreaterThanOrEqualTo(const HugeInteger &) const;
	bool isLessThanOrEqualTo(const HugeInteger &) const;
	bool isZero() const;

private:
	int digits[40];
};

#endif // !HUGEINTEGER_H

