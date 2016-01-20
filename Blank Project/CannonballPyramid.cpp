/*
 * File: CannonballPyramid.cpp
 * -------------------------
 * Spherical objects, such as cannonballs, can be stacked to form a pyramid with 
 * one  cannonball  at  the  top,  sitting  on  top  of  a  square  composed  of  four 
 * cannonballs, sitting on top of a square composed of nine cannonballs, and so 
 * forth.  Write a recursive function cannonball that takes as its argument the 
 * height of the pyramid and returns the number of cannonballs it contains.  Your 
 * function  must  operate  recursively  and  must  not  use  any  iterative  constructs, 
 * such as while or for. 
 */

#include <iostream>
#include <string>
#include "simpio.h"
using namespace std;

/* Function prototype */
int layer(int n);
int cannonball(int n);
int cannonballAll(int n);

/* Main Program */

int main()
{
	while (true) {
		int cb = getInteger("Enter the number of CannonballPyramid: ");
		if (cb == -1) break;
		cout << cannonballAll(cb) << endl;
	}
	return 0;
}


int layer(int n) {
	if (n == 1)
		return 1;
	return 1 + layer(n - 1);
}

int cannonball(int n) {
	if (n == 1)
		return layer(1);
	return layer(n) + cannonball(n - 1);
}

int cannonballAll(int n) {
	if (n == 1)
		return cannonball(1);
	return cannonball(n) + cannonballAll(n - 1);
}