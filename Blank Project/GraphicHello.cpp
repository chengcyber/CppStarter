/*
 * File: main.cpp
 * --------------
 * This is a blank C++ source file.
 */

#include <iostream>
#include <string>
#include "gwindow.h"
using namespace std;

int main() {
	GWindow gw;
	cout << "This program draws." << endl;
	double width = gw.getWidth();
	double height = gw.getHeight();
	gw.drawLine(0, height / 2, width /2, 0);

	string str = string("hello") + ", " + "world";
	cout << str << endl;
    return 0;
}