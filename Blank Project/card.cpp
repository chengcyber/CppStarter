/* File: card.cpp
 * -------------------
 * This file implements the Card class.
 */

#include <string>
#include "card.h"
#include "strlib.h"
using namespace std;

/* Function prototype */
string suitToString(Suit su);

/*
 * Implementation notes: Constructor
 * ---------------------------------
 * the constructor of class Card depends on the two parameters: rank and suit
 * each indicates the value of the instace card.
 */
Card::Card(int r, Suit s) {
	rank = r;
	suit = s;
}

/* Implementation notes: getters
 * ---------------------------------
 * getters or called accessors to private instance variables(ivars).
 */
int Card::getRank() {return rank;}
Suit Card::getSuit() {return suit;}

/*
 * Implementation notes: toString
 * ---------------------------------
 * show the ivars to string like "2H" and overload << operator
 */
string Card::toString() {
	return ( integerToString(rank) + suitToString(suit) );
}

string suitToString(Suit su) {
	switch(su) {
		case CLUBS : return "CLUBS"; break;
		case DIAMONDS : return "DIAMONDS"; break;
		case HEARTS : return "HEARTS"; break;
		case SPADES : return "SPADES"; break;
		default : return "?"; break;
	}
}