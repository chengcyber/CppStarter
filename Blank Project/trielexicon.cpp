/*
 * File: trielexicon.cpp
 * -------------------------
 * This file implements the TrieLexicon Class.
 */

#include "trielexicon.h"
#include <cctype>
#include <iostream>
#include <fstream>
#include "error.h"

using namespace std;


/*
 * Implementation note: Constructors
 * -------------------------
 * The constructors initializes the new trieTree.
 * If given the specified filename. the Lexicon add the words
 * in that file.
 */
TrieLexicon::TrieLexicon() {
	trie = NULL;
	count = 0;
}

TrieLexicon::TrieLexicon(string filename) {
	this->TrieLexicon::TrieLexicon();
	// this->TrieLexicon::addWordsFromFile(filename);
	addWordsFromFile(filename);
}
/*
 * Implementation note: Destructor
 * -------------------------
 * The destructor deallocated the memory storage asscioate with Lexicon.
 */
TrieLexicon::~TrieLexicon() {
	clear();
}
/*
 * Implementation note: size
 * -------------------------
 * the number of words in Lexicon.
 */
int TrieLexicon::size() const {
	return count;
}
/*
 * Implementation note: isEmpty
 * -------------------------
 * true if count == 0, false otherwise.
 */
bool TrieLexicon::isEmpty() const {
	return (trie == NULL);
}
/*
 * Implementation note: add
 * -------------------------
 * Adds a new word to the internal TrieTree structure.
 */
void TrieLexicon::add(string word) {
	trieTree *tp;
	if (isEmpty()) {
		tp = new trieTree();
		tp->trieArr = new trieTree*[CAPACITY_COUNT];
		for (int i = 0; i < CAPACITY_COUNT; i++) {
			tp->trieArr[i] = NULL;
		}
		tp->contain = false;
		trie = tp;
	}
	tp = trie;
	for (int i = 0; i < word.length(); i++) {
		int index = toupper(word[i]) - 'A';
		if (tp->trieArr[index] == NULL) {
			trieTree *tptr = new trieTree();
			tptr->trieArr = new trieTree*[CAPACITY_COUNT];
			for (int j = 0; j < CAPACITY_COUNT; j++) {
				tptr->trieArr[j] = NULL;
			}
			tptr->contain = false;
			tp->trieArr[index] = tptr;
		}
		tp = tp->trieArr[index];
	}
	tp->contain = true;
	count++;
}
/*
 * Implementation note: addWordsFromFile
 * -------------------------
 * Adds words from the file, open file and add words line by line.
 * if the file doesn't exists or malformed, Error will be called.
 */
void TrieLexicon::addWordsFromFile(string filename) {
	ifstream infile;
	infile.open(filename.c_str());
	if(infile.fail()) {
		error("The Lexicon file dosen't exists.");
	}
	while (infile.good() || !infile.eof()) {
		string line = "";
		getline(infile, line);
		// cout << "Line : |" << line << "|" << endl;
		for (int i = 0 ; i < line.length(); i++) {
			char ch = line[i];
			if (!isalpha(ch)) error("Bad content in the file");
		}
		add(line);
	}

	infile.close();
}
/*
 * Implementation note: containsWord
 * -------------------------
 * Traverses the Trie structure to the specified word position, returns
 * true if the contain value is true, false otherwise.
 */
bool TrieLexicon::containsWord(string word) {
	if (isEmpty() || word == "") return false;
	trieTree *tp = trie;
	for (int i = 0; i < word.length(); i++) {
		int index = toupper(word[i]) - 'A';
		if(tp->trieArr[index] == NULL) return false;
		tp = tp->trieArr[index];
	}
	return tp->contain;
}
/*
 * Implementation note: containsPrefix
 * -------------------------
 * Traverses the Trie structure to finde the prefix position. returns
 * true if the position exists and is not NULL.
 */
bool TrieLexicon::containsPrefix(string prefix) {
	if (isEmpty() || prefix == "") return false;
	trieTree *tp = trie;
	for (int i = 0; i < prefix.length(); i++) {
		int index = toupper(prefix[i]) - 'A';
		if(tp->trieArr[index] == NULL) return false;
		tp = tp->trieArr[index];
	}
	return true;
}
/*
 * Implementation note: clear
 * -------------------------
 * reinitialize the lexicon object. and deallocated heap storage.
 */
void TrieLexicon::clear() {
	deleteTrie(trie);
	trie = NULL;
	count = 0;
}
void TrieLexicon::deleteTrie(trieTree *tp) {
	if (tp != NULL) {
		for (int i = 0; i < CAPACITY_COUNT; i++) {
			deleteTrie(tp->trieArr[i]);
		}
		delete tp;
	}
}