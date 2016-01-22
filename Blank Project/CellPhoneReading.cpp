/* File: CellPhoneReading.cpp
 * -------------------
 * Entering text using a phone keypad is problematic; there are only 10 digits for 26 letters and thus
 * each digit key is mapped to several letters. Some cell phones require "multi-tap" ¡ªtap the 2 key
 * once for 'a', twice for 'b' and three times for 'c', which can get tedious. A streamlined alternative such
 * as Tegic's T9 predictive text requires just one tap on each digit, it then guesses which letter was
 * intended based on the sequence so far and its possible completions.
 * For example, if the user types the digit sequence "72", there are nine possibilities (pa, pb, pc, ra, rb,
 * rc, sa, sb, sc). Three of these seem promising (pa, ra, sa) because they prefix words such as "party"
 * and "sandwich", while the others can be ignored since they don't start any words. If the user enters
 * "9956", there are 81 (34
 * ) possibilities, but you can be assured the user meant "xylo" since that is the
 * only one that is a prefix of any English words.
 * Write the function ListCompletions(string digits, Lexicon & lex) that prints all words
 * from the lexicon that can be formed by extending the given digit sequence. For example, the
 * completions for "72547" are:
 * palisade palisaded palisades palisading palish rakis rakish rakishly rakishness sakis
 */

#include <iostream>
#include <string>
#include "simpio.h"
#include "lexicon.h"
#include "vector.h"
#include "strlib.h"

using namespace std;

void ListCompletions(string digits, Lexicon & lex);
void getDigitVec(string digits, Vector<string> &vec, int start, int finish);
void compareLex(Set<string> &set, Lexicon &lex);
string getStringT9(char ch);
Set<string> getCompletions(Vector<string> &vec);

int main()
{
	Lexicon lexicon("lexicon.dat");
	while(true) {
		string digits = getLine("Enter a digit sequence:");
		if (digits == "") break;
		ListCompletions(digits, lexicon);	
	}
	return 0;
}

void ListCompletions(string digits, Lexicon &lex) {
	Vector<string> vec;
	getDigitVec(digits, vec, 0, digits.length() - 1);
	cout << getCompletions(vec).toString() << endl;
	cout << "---------------" << endl;
	compareLex(getCompletions(vec), lex);
}

void getDigitVec(string digits, Vector<string> &vec, int start, int finish) {
	if( start > finish) return;
	string tmp = getStringT9(digits[start]);
	vec.add(tmp);
	getDigitVec(digits, vec, start + 1, finish);
}

void compareLex(Set<string> &set, Lexicon &lex) {
	Set<string> result;
	foreach(string s in set) {
		if (lex.containsPrefix(s)) result += s;
	}
	cout << result.toString() << endl;
}

string getStringT9(char ch) {
	switch(ch) {
	case '2': return "abc" ; break;
	case '3': return "def" ; break;
	case '4': return "ghi" ; break;
	case '5': return "jkl" ; break;
	case '6': return "mno" ; break;
	case '7': return "pqrs" ; break;
	case '8': return "tuv" ; break;
	case '9': return "wxyz" ; break;
	default : return ""; break;
	}
}

Set<string> getCompletions(Vector<string> &vec) {
	Set<string> result;
	if (vec.isEmpty()) {
		result += "";
	}
	else {
		// for (int i = 0; i < vec.size(); i++) {
			Vector<string> rest = vec;
			// rest.remove(i);
			// string str = vec[i];
			rest.remove(0);
			string str = vec[0];
			foreach (string s in getCompletions(rest)) {
				for (int j = 0; j < str.length(); j++) {
					char ch = str[j];
					result += ch + s;
				}
			}
		// }
	} 
	return result;
}