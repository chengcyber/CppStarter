/*
 * This program implement a caesarcipher encryption.
*/

#include <iostream>
#include "simpio.h"
#include <string>
#include <cctype>
using namespace std;

string encrypCaesar(string str, int key);
char encrypCaesar(char ch, int key);

int main()
{
	cout << "This program encodes a message using a Caesar cipher." << endl;
	int key = getInteger("Enter the number of character positions to shift: ");	
	if (key < 0) {
		key = (26 - (-key % 26));
	}
	string line = "";
	while (true) {
		line = getLine("Enter a message: ");
		if (line == "") break;
		line = encrypCaesar(line, key);
		cout << "Encoded message: " << line << endl;
	} 
	return 0;
}

string encrypCaesar(string str, int key) {
	string result = "";
	for (int i = 0; i < str.length(); i++) {
		char ch = encrypCaesar(str[i], key);
		result += ch;
	}
	return result;
}

char encrypCaesar(char ch, int key) {
	if (isupper(ch))
		return (((ch - 'A' + key) % 26) + 'A');
	else
		return ch;
} 