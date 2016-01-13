/* File: card.cpp
 * -------------------
 * This file implements the Card class.
 */

#include <string>
#include "card.h"
#include "strlib.h"
using namespace std;

/* extern statement */


extern const int ACE = 1;
extern const int JACK = 11;
extern const int QUEEN = 12;
extern const int KING = 13;

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
	string prefix;
	if (rank == ACE) prefix = "A";
	else if (rank == JACK) prefix = "J";
	else if (rank == QUEEN) prefix = "Q";
	else if (rank == KING) prefix = "K";
	else prefix = integerToString(rank);
	return (prefix + suitToString(suit).substr(0,1));
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


/*
 * Operator Overloading: ++ for enum Suit.
 * Usage: s++, ++s
 * ---------------
*/ 

Suit operator++(Suit & su) {
	su = Suit(su + 1);
	return su;
}

Suit operator++(Suit & su, int) {
	Suit old = su;
	su = Suit(su + 1);
	return old;
}

ostream & operator<<(ostream & os, Card car) {
	return os << car.toString();
}

