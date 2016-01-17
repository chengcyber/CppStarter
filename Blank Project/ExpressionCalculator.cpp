/* File: ExpressionCalculator.cpp
 * -------------------
 * This file implements a smiple arithemetic calculator. Input to the
 * calculator consists of lines composed of numbers (either integers or reals)
 * combined together using the arithmetic operators +, -, *, and /. For each line
 * of input, your program should display the result of applying the operators from
 * left to right. You should use the token scanner to read the terms and operators
 * and set up the scanner so that it ignores any whitespace characters. Your
 * program should exit when the user enters a blank line. 
 */

#include <iostream>
#include <string>
#include "simpio.h"
#include "tokenscanner.h"
#include "strlib.h"

using namespace std;

/* constants */
const string SENTINEL = "";

/* enumeratic type */
enum OperatorType {
ADD,
MIN,
MUL,
DIV,
ERR
};

/* Function prototypes */
double exCal(string line);
OperatorType transOper(string oper);
double simpCal(double lhs, double rhs, OperatorType oper);
/* show Token of line testing */
double showToken(string line);

/* Main Program */
int main() 
{
	double result = 0;
	while (true) {
		string line = getLine("> ");
		if (line == SENTINEL) break;
		// result = showToken(line);
		result = exCal(line);
		cout << result << endl;
	}
	return 0;
}

double exCal(string line) {
	TokenScanner token(line);
	token.scanNumbers();
	token.ignoreWhitespace();

	double lhs = stringToReal(trim(token.nextToken()));
	double rhs;
	OperatorType oper;
	while(token.hasMoreTokens()) {
		oper = transOper(trim(token.nextToken()));
		rhs = stringToReal(trim(token.nextToken()));
		lhs = simpCal(lhs, rhs, oper);
	}
	return lhs;
}

OperatorType transOper(string oper) {
	if (oper == "+") return ADD;
	if (oper == "-") return MIN;
	if (oper == "*") return MUL;
	if (oper == "/") return DIV;
	return ERR;
}

double simpCal(double lhs, double rhs, OperatorType oper) {
	double result = -1;
	switch(oper) {
		case ADD: result = lhs + rhs; break;
		case MIN: result = lhs - rhs; break;
		case MUL: result = lhs * rhs; break;
		case DIV: result = lhs / rhs; break;
		default: break;
	}
	return result;
}

double showToken(string line) {
	TokenScanner tok(line);
	tok.scanNumbers();
	tok.ignoreWhitespace();

	while(tok.hasMoreTokens()) {
		cout << trim(tok.nextToken()) << endl;
	}

	return 0;
}