/*
 * File: FindAreaCodes.cpp
 * -------------------------
 * read data from file :AreaCodes.txt
 * prompt user to enter area code 
 * output the state name result.
*/

#include "simpio.h"
#include <iostream>
#include "map.h"
#include "error.h"
#include <string>
using namespace std;

/* Function propotypes */
Map<int, string> createMapFromFile(string filename);
int stringToInteger(string str);

/* Main program */

int main() 
{
	Map<int, string> areas = createMapFromFile("AreaCodes.txt");
	while (true) {
		int code = getInteger("Enter area code :");
		if (areas.containsKey(code)) {
			cout << areas.get(code) << endl;
		} else {
			cout << "no result" << endl;
		}
	}


	return 0;
}

Map<int, string> createMapFromFile(string filename) {
	Map<int, string> map;
	ifstream ifs;
	ifs.open(filename.c_str());
	if(ifs.fail()) error("Can't read the data file.");
	while (true) {
		string line;
		getline(ifs, line);
		if (ifs.fail() || ifs.eof()) break;
		if (line.length() < 4 || line[3] != '-') error("Illegal data line : " + line);
		string code = line.substr(0,3);
		int key = stringToInteger(code);
		map.put(key, line.substr(4));
	}
	return map;
}

int stringToInteger(string str) {
	istringstream iss(str);
	int value;
	iss >> value >> ws;
	if (iss.fail() || !iss.eof()) error("stringToInteger: Illegal integer format");
	return value;
}