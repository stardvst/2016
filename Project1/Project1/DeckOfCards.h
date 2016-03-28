#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "Card.h"
#include <vector>

class DeckOfCards {
public: 
	DeckOfCards();
	void shuffle();
	Card dealCard();
	bool moreCards() const;
private:
	std::vector<Card> deck; // a vector to store the Cards
	int currentCard; // the next card to deal
};

#endif // !DECKOFCARDS_H

