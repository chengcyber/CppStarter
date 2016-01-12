/*
 * File: cardmain.cpp
 * ---------------
 * The file contains main function for testing the card class.
 */

#include <iostream>
#include "card.h"
#include <string>

using namespace std;


int main() 
{
	for (Suit suit = CLUBS; suit <= SPADES; suit++) {
		for (int rank = ACE; rank <= KING; rank++) {
			cout << " " << Card(rank, suit);
		}
		cout << endl;
	}
	return 0;
}