/*
 * File: CountStair.cpp
 * -------------------------
 * You're standing at the base of a staircase and are heading to the top. A small stride will move up one
 * stair, a large stride advances two. You want to count the number of ways to climb the entire staircase
 * based on different combinations of large and small strides. For example, a staircase of three steps
 * can be climbed in three different ways: via three small strides or one small stride followed by one
 * large stride or one large followed by one small. A staircase of four steps can be climbed in five
 * different ways (enumerating them is an exercise left to reader :-).
 */


#include <string>
#include <iostream>
#include "simpio.h"

using namespace std;

/* Function prototypes */

int CountWays(int numStairs);

/* Main program */

int main()
{
	
	while (true) {
		int n = getInteger("Enter number of stairs:");
		if (n == 0) break;
		cout << CountWays(n) << endl;
	}
	return 0;
}

int CountWays(int numStairs) {
	if (numStairs <= 1) {
		return 1;
	} else {
		return CountWays(numStairs - 1) + CountWays(numStairs - 2);
	}

}