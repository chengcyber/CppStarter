/*
 * File: trielexicon.h
 * -------------------------
 * This file define a inteface of Lexicon Class, 
 * which implemented by the "trie" data structure
 */

#ifndef _trielexicon_h
#define _trielexicon_h

#include <string>

struct trieTree
{
	trieTree **trieArr;
	bool contain;
};
/*
 * Class: TrieLexicon
 * -------------------------
 * This class is used to represent a lexicon, or word list.
 * (the centural word in "retrieval").
 * -> A B C . . . Z  yes/no
 *    | | |-> A B C . . . Z yes/no
 *    | |-> A B C . . . Z  yes/no
 *    |-> A B C . . . Z  yes/no
 * trie's root node is meaningless, each hup points to
 * a pointer array contains A - Z and a yes/no signal.
 * the word in the lexicon is the current character append to
 * the string of the last pointer referenced. yes/no means
 * the current word is/is not the member in Lexicon.  
 *
 * TrieLexicon lex("lexicon.txt") // only support the text file.
 * lex.add("someword");
 * if (lex.containsPrefix("some") || lex.containsWord("word"))
 * 		. . .
 */
class TrieLexicon
{
public:
/*
 * Constructor: TrieLexicon
 * Usage: TrieLexicon lex;
 * 			TrieLexicon *tlp = new TrieLexicon;
 * -------------------------
 * The constructor initializes a new empty lexicon
 */
	TrieLexicon();
/*
 * Constructor: TrieLexicon
 * Usage: TrieLexicon lex("lexicon.txt");
 * 			TrieLexicon *tlp = new TrieLexicon("lexicon.txt");
 * -------------------------
 * The constructor initializes a new lexicon which populated with
 * the specified text file.
 * If this file doesn't exists or malformed, Error is called to exit.
 */
 	TrieLexicon(std::string filename);
/*
 * Destructor: ~TrieLexicon 
 * ----------------------------------
 * the desctrutor frees any heap space associated with TrieLexicon.
 */
	~TrieLexicon();
/*
 * Method: size
 * Usage: int n = lex.size()
 * ----------------------------------
 * Returns the total number of words in lexicon.
 */
 	int size() const;
/*
 * Method: isEmpty
 * Usage: if (lex.isEmpty()) . . .
 * ----------------------------------
 * Returns true when lex is an empty lexicon, otherwise return false.
 */
 	bool isEmpty() const;
/*
 * Method: add
 * Usage: lex.add("word")
 * ----------------------------------
 * This method add a new word to Lexicon.
 */
 	void add(std::string word);
/*
 * Method: addWordsFromFile(string filename)
 * Usage: lex.addWordsFromFile("words.txt")
 * ----------------------------------
 * This method add the words from the specified file, the file contains the words
 * one per line, if the file doesn't exists or malformed, Error is called to exit.
 */
 	void addWordsFromFile(std::string filename);
/*
 * Method: containsWord
 * Usage: if (lex.contansWord("word")) . . .
 * ----------------------------------
 * Returns true if the specified word is contained in the lexicon,
 * false otherwise. Words are considered case-insensitively, "zoo"
 * is the same as "ZOO" or "zoo".
 */
 	bool containsWord(std::string word);
/*
 * Method: containsPrefix
 * Usage: if (lex.containsPrefix("pre")) . . .
 * ----------------------------------
 * Returns true if any words in the lexicon begin with the prefix, false otherwise.
 * The prefix is also considered case-insensitively.
 */
 	bool containsPrefix(std::string prefix);
/*
 * Method: clear
 * Usage: lex.clear();
 * ----------------------------------
 * This method removes all the words in the lexicon. the lexicon will be empty
 * after being cleared.
 */
 	void clear();
/*
 * Method: mapAll
 * Usage: lex.mapAll(PrintToFile, outputStream);
 * ----------------------------------
 * This file iterates through this lexicon and calls the function fn once for
 * each word and client's data. That data can be of whatever type is needed
 * client's callback. 
 */
 	template <typename FunctionType>
 	void mapAll(FunctionType fn);
/*
 * Method: DeepCopy support
 * ----------------------------------
 * This copy constructor and operator= are definced to make a deep copy,
 * making it possible to pass/return lexicons by value and assign from one
 * lexicon to another.
 */
 	TrieLexicon(const TrieLexicon &src);
 	const TrieLexicon & operator=(const TrieLexicon &src);
private:
	/* constant varibales */
	static const int CAPACITY_COUNT = 26;
	trieTree *trie;
	int count ;
	void deepCopy(const TrieLexicon &src);
};

	template <typename FunctionType>
	void traversal(trieTree *&t, FunctionType fn, std::string word) {
		if (t->contain) {
			fn(word);
		}
		for (int i = 0; i < 26; i++) {
			if (t->trieArr[i] != NULL) {
				word += i + 'A';
				traversal(t->trieArr[i], fn, word);
				word -= i + 'A';
			}
		}
	}
	
 	template <typename FunctionType>
 	void TrieLexicon::mapAll(FunctionType fn) {
 		// traversal and fn()
 		traversal(trieTree *&t, FunctionType fn, "");
 	}

#endif