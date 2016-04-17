#include "Card.h"

const std::string Card::suits[4] = { "Hearts", "Clubs", "Diamonds", "Spades" };
const std::string Card::faces[13] = { "Ace", "Two", "Three", "Four", "Five", 
"Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen","King" };

Card::Card(int f, int s) {
	face = (f >= 0 && f < 13) ? f : 0;
	suit = (s >= 0 && s < 4) ? s : 0;
}

std::string Card::toString() const {
	return faces[face] + " of " + suits[suit];
}

int Card::getFace() const {
	return face;
}

int Card::getSuit() const {
	return suit;
}