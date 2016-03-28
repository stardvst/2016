#include <iostream>
#include "DeckOfCards.h"
using namespace std;


int main() {

	DeckOfCards deck1;
	deck1.shuffle();
	for (int i = 0; i < 53; i++) {
		if (!deck1.moreCards()) {
			cout << "Card " << i + 1 << " is " << deck1.dealCard().toString()
				<< endl;
		}
		else {
			cout << "No more cards to deal.\n";
		}
	}
	
	system("pause");
	return 0;
}

