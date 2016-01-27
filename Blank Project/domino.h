/*
 * File: domino.h
 * -------------------------
 * The head file of domino class contains leftdoc and rightdoc.
 */

#ifndef _domino_h
#define _domino_h

#include <string>
#include <iostream>

/*
 * Class: Domino
 * -------------------------
 * This class stores the two docs in integer value.
 */
class Domino {

/* Public section */
public:

/*
 * Constructors:
 * Usage: Donimo()
 * 			Donimo(x,y)
 * -------------------------
 * The constructor creates a donimo class contains left equals x,
 * right equals y, and Default constructor create with both zero.
 */
 	Domino();
 	Domino(int x, int y);


/*
 * Method:getLeftDocs
 * 			getRightDocs
 * Usage: int left = Domino.getLeftDocs()
 * 			int right = Domino.getRightDocs()
 * -------------------------
 * Return the left or right value of domino.
 */
 	int getRightDocs();
 	int getLeftDocs();

/*
 * Function: toString
 * Usage: string s = Domino.toString()
 * -------------------------
 * Display the left and right value of Domino.
 */
 	std::string toString();



/* Private section */
private:

	int leftDocs;
	int rightDocs;

};


/*
 * Operator: <<
 * -------------------------
 * overloading operator << 
 */

std::ostream & operator<< (std::ostream & os, Domino & Domino);

#endif