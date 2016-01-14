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
	Date electionDay(6, NOVEMBER, 2012); 
	Date inaugurationDay(21, JANUARY, 2013); 
	cout << electionDay.toString() << endl;
	cout << inaugurationDay.toString() << endl;

	Month mon = JANUARY;
	for (int i = 1; i <= 30 ; i++)
		cout << i << " " << mon++ << endl;
	return 0;
}