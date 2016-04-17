#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "Card.h"
#include <vector>

class DeckOfCards {
public:
	DeckOfCards();
	void shuffle();
	Card dealCard();
	void dealFiveCardHand();
	bool containsAPair() const;
	bool containsTwoPairs() const;
	bool containsThreeOfAKind() const;
	bool containsFourOfAKind() const;
	bool containsAFlush() const;
	bool containsAStraight() const;
	bool moreCards() const;
private:
	std::vector<Card> deck; // a vector to store the Cards
	std::vector<Card> hand; // a five-card poker hand
	int currentCard; // the next card to deal
};

#endif // !DECKOFCARDS_H

