/*
 * File: domino.cpp
 * -------------------------
 * This file implements the domino.h
 */

#include "domino.h"
#include <string>
#include <iostream>
#include "strlib.h"

using namespace std;


/*
 * Implementation notes: Constructors
 * -------------------------
 * The constructors of class Domino depend on two parameters: x, y. 
 */
Domino::Domino(int x, int y) {
	leftDocs = x;
	rightDocs = y;
}

Domino::Domino() {
	leftDocs = 0;
	rightDocs = 0;
}

/*
 * Implementation notes: getters or accessors
 * -------------------------
 * get each private instance variables
 */
int Domino::getRightDocs() {
	return rightDocs;
}
int Domino::getLeftDocs() {
	return leftDocs;
}


/*
 * Implementation notes: toString()
 * -------------------------
 * Display the left and right values of domino.
 */
string Domino::toString() {

	return ("{" + integerToString(leftDocs) + "," 
		+ integerToString(rightDocs) + "}");
}

/*
 * Operator Overloading: <<
 * -------------------------
 * overload the << operator with toString method.
 */
ostream & operator<< (ostream & os, Domino & domino) {
	return os << domino.toString();
}
