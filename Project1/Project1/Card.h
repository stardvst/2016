#ifndef CARD_H
#define CARD_H

#include <string>
 
class Card {
public:
	Card(int, int);
	std::string toString() const;
	int getFace() const;
	int getSuit() const;
private:
	int face;
	int suit;
	static const std::string suits[4];
	static const std::string faces[13];
};

#endif // !CARD_H
