/*
 * File: main.cpp
 * --------------
 * This is a blank C++ source file.
 */

#include <iostream>
#include "gwindow.h"
using namespace std;

int main() {
	GWindow gw;
	cout << "This program draws." << endl;
	double width = gw.getWidth();
	double height = gw.getHeight();
	gw.drawLine(0, height / 2, width /2, 0);
    return 0;
}