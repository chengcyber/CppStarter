/*
 * File: trielexiconmain.cpp
 * -------------------------
 * This file test the TrieLexcion Class.
 */

#include <iostream>
#include <string>
#include "trielexicon.h"
#include "error.h"

using namespace std;

void printLexicon(TrieLexicon & lex);

int main()
{
	TrieLexicon lex;
	printLexicon(lex);
	lex.add("A");
	printLexicon(lex);
	cout << lex.containsWord("A") << endl;
	// cout << lex.containsWord("b") << endl;
	// cout << lex.containsWord("C") << endl;

	printLexicon(lex);
	return 0;
}

void printLexicon(TrieLexicon & lex) {
	cout << "isEmpty? " << lex.isEmpty() << endl;
	cout << "size: " << lex.size() << endl;	
}