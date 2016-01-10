/*
 * File: TrigTable.cpp
 * -------------------------
 * This program use <iomanip> library give more control over outpu format,
 * display a table of trigonometric sines and cosines.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = 3.1415926;

int main()
{
	cout << " theta | sin(theta) | cos(theta) |" << endl;
	int theta = 30;
	/* persistent */
	cout << setprecision(7) << right << fixed;
	cout << setw(5) << theta << "  | " << 
	/* setw is transient */
	setw(10) << sin(double(theta * PI / 180)) << " | " << 
	setw(10) << cos(double(theta * PI / 180)) << " |" << 
	endl;
	return 0;
}