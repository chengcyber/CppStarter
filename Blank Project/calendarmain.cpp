/*
 * File: calendarmain.cpp
 * ---------------------
 * This file test Month type including calendar.h file.
 */

#include "calendar.h"
#include <string>
#include <iostream>
#include "simpio.h"
using namespace std;

int main()
{
	int year = getInteger("Enter a year:");
	for (Month month = JANUARY; month <= DECEMBER; month++) {
		cout << monthToString(month) << " has " 
			<< daysInMonth(month, year) << " days." << endl;
	}
	return 0;
}