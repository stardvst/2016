#ifndef INTEGER_H
#define INTEGER_H

class Integer {
public:
	explicit Integer(int = 0);
	~Integer();
	void setInteger(int i);
	int getInteger() const;
private:
	int value;
};

#endif // !INTEGER_H
