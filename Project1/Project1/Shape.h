#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
	Shape() {};
	virtual ~Shape() {};

	char setFillCharacter() const;
	char setBorderCharacter() const;

	virtual void draw() const = 0;
	virtual void print() const = 0;
};

#endif // !SHAPE_H
