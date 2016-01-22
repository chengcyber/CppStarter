/*
 * File: DecimalToBinary.cpp
 * -------------------------
 * This file print the binary number of the input(decimal type).
 */

#include <iostream>
#include <string>
#include "simpio.h"
using namespace std;

/* Function prototype */
void printInBinary(int n);

/* Main program */
int main() 
{
	while(true) {
		int n = getInteger("Enter a number: ");
		if ( n == 0) break;
		cout << "The binary is ";
		printInBinary(n);
		cout << endl;
	}
	return 0;
}

void printInBinary(int n) {
	if (n < 2) {
		cout << n ;
	} else {
		printInBinary(n / 2);
		cout << n % 2;
	}
}