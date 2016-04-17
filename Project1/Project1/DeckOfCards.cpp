#include "DeckOfCards.h"
#include <iostream>
#include <ctime>


DeckOfCards::DeckOfCards() {
	srand(time(NULL));
	currentCard = 0;
	for (int suit = 0; suit < 4; suit++) {
		for (int face = 0; face < 13; face++) {
			Card card(face, suit);
			deck.push_back(card);
		}
	}
}

void DeckOfCards::shuffle() {
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

void DeckOfCards::dealFiveCardHand() {
	for (int card = 0; card < 5; card++) {
		hand.push_back(deck[rand() % 52]);
		std::cout << "Card " << card + 1 << " is " << hand[card].toString() << std::endl;
	}
}

bool DeckOfCards::containsAPair() const {
	int faceFrequency[13] = { 0 };
	bool onePair = false;
	for (int i = 0; i < 5; i++) {
		faceFrequency[hand[i].getFace()]++;
	}
	for (int i = 0; i < 13; i++) {
		if (faceFrequency[i] == 2) {
			for (int j = i; j < 13; j++) {
				if (faceFrequency[j] == 2) {
					return false;
				}
			}
			return true; 
		}
	}
	return false;
}

bool DeckOfCards::moreCards() const {
	return currentCard == 52;
}