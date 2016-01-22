/*
 * File: DrawRuler.cpp
 * -------------------------
 * The tallest tick mark falls at the center dividing into halves, two shorter tick marks indicate the quarter
 * divisions, and even shorter ones are used to mark the eighths and sixteenths and so on. Write the
 * recursive function DrawRuler(double x, double y, double w, double h). The function is
 * given the coordinates for a rectangle in which to draw the ruler. The function draws a line along the
 * rectangle's bottom edge and a sequence of vertical tick marks. The middlemost tick mark is centered
 * and is as tall as the rectangle height. Each smaller tick mark is half the height of the next larger one.
 * Once the tick marks become sufficiently small, the recursion terminates.
 */

#include "gwindow.h"


using namespace std;

void drawRuler(double x, double y, double w, double h, GWindow gw);

int main()
{
	GWindow gw;
	drawRuler(50,100,100,50, gw);
	return 0;
}

void drawRuler(double x, double y, double w, double h, GWindow gw){
	
	gw.drawLine( x + w / 2, y, x + w / 2, y + h);
	if (w < 10) {
		return;
	} else {
		drawRuler(x, y + h / 2, w / 2, h / 2, gw);
		drawRuler(x + w /2, y + h / 2, w / 2, h / 2, gw);
	}
}