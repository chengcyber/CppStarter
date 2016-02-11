/* File: IntArrayMain.cpp
 * -------------------
 * This file test the Class IntArray.
 */

#include "iostream"
#include "intarray.h"

using namespace std;


int main()
{

	IntArray iA(8);
	cout << iA.size() << endl;
	for(int i = 0; i < iA.size(); i++)
		cout << iA.get(i) << ", ";
	cout << endl;

	cout << "----test copy constructor---" << endl;
	IntArray iB(1);
	cout << iB.size() << endl;
	iB = iA;
	for(int i = 0; i < iB.size(); i++)
		cout << iB.get(i) << ", ";
	cout << endl;

	cout << "----test overloading-----" << endl;

	for(int i = 0; i < iB.size(); i++) {
		cout << iB[i] << ", ";
	}
	cout << endl;
	return 0;
}