#include "DeckOfCards.h"
#include <iostream>
#include <ctime>


DeckOfCards::DeckOfCards() {
	currentCard = 0;
	for (int suit = 0; suit < 4; suit++) {
		for (int face = 0; face < 13; face++) {
			Card card(face, suit);
			deck.push_back(card);
		}
	}
}

void DeckOfCards::shuffle() {
	srand(time(NULL));
	for (int i = 0; i < 52; i++) {
		int j = rand() % 52;
		Card temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}

Card DeckOfCards::dealCard() {
	return deck[currentCard++];
}

bool DeckOfCards::moreCards() const {
	return currentCard == 52;
}