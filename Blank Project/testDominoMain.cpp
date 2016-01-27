/*
 * File: testDominoMain.cpp
 * -------------------------
 * This file test the domino class.
 */

#include "domino.h"
#include <string>
#include <iostream>

using namespace std;

/* Function prototype */
void printDominoDtl(Domino domino);

int main() 
{
	Domino do1;
	printDominoDtl(do1);

	Domino do2(6,6);
	printDominoDtl(do2);

	return 0;
}

void printDominoDtl(Domino domino) {
	cout << "Show instatnce variables: " << endl;
	cout << "Left: " << domino.getLeftDocs() << endl;
	cout << "Right: " << domino.getRightDocs() << endl;

	cout << "---------" << endl;
	cout << "test toString()" << endl;
	cout << domino.toString() << endl;

	cout << "---------" << endl;
	cout << "test operator overloading" << endl;
	cout << domino << endl;

	cout << "----Over-----" << endl;
}