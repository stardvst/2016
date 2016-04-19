#include <iostream>
#include "Shape.h"



char Shape::setFillCharacter() const {
	char fill;
	std::cout << "Enter a fill character: ";
	std::cin >> fill;
	return fill;
}

char Shape::setBorderCharacter() const {
	char border;
	std::cout << "Enter a border character: ";
	std::cin >> border;
	return border;
}
