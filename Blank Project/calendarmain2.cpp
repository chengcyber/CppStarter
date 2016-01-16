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
	electionDay.nextDay();
	cout << electionDay.toString() << endl;
	electionDay.lastDay();
	cout << electionDay.toString() << endl;
	cout << inaugurationDay.toString() << endl;

	Month mon = JUNE;
	for (int i = 1; i <= 3 ; i++)
		cout << i << " " << monthToString(mon++) << endl;

	cout << electionDay.getMonth() << endl;
	cout << inaugurationDay.getMonth() << endl;

	cout << "relation:" << endl;
	cout << (electionDay == inaugurationDay) << endl;
	cout << (electionDay != inaugurationDay) << endl;
	cout << (electionDay <= inaugurationDay) << endl;
	cout << (electionDay >= inaugurationDay) << endl;
	cout << (electionDay < inaugurationDay) << endl;
	cout << (electionDay > inaugurationDay) << endl;
	cout << "---" << endl;
	for (int i = 0; i < 15; i++) {
		electionDay = electionDay + 10;
		cout << electionDay.toString() << endl;
	}
	cout << "----------------" << endl;
	for (int i = 0; i < 15; i++) {
		electionDay = electionDay - 10;
		cout << electionDay.toString() << endl;
	}


	return 0;
}