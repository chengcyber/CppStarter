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
void printString(string word);
void printContainWord(TrieLexicon & lex, string word);
void printContainPrefix(TrieLexicon & lex, string prefix);

int main()
{
	TrieLexicon lex("lexicon.txt");
	printLexicon(lex);
	printContainPrefix(lex, "Ap");
	printContainWord(lex, "Ap");
	printContainPrefix(lex, "ApPLe");
	printContainWord(lex, "ApPLe");
	printContainPrefix(lex, "vaild");
	printContainWord(lex, "vaild");
	return 0;
}

void printLexicon(TrieLexicon & lex) {
	cout << "isEmpty? " << lex.isEmpty() << endl;
	cout << "size: " << lex.size() << endl;	
	cout << "------lexicon content------" << endl;
	lex.mapAll(printString);
	cout << "------END of LEXICON ------" << endl;
}

void printString(string word) {
	cout << word << endl;
}

void printContainWord(TrieLexicon & lex, string word) {
	cout << "containsWord - " << word << " -" << endl;
	cout << lex.containsWord(word) << endl;
	cout << "-----------------------" << endl;
}

void printContainPrefix(TrieLexicon & lex, string prefix) {
	cout << "containsPrefix - " << prefix << " -" << endl;
	cout << lex.containsPrefix(prefix) << endl;
	cout << "-----------------------" << endl;
}