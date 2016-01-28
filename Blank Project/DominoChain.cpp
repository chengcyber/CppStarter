/*
 * File: DominoChain.cpp
 * -------------------------
 * This file form domino chain with recursion strategy!
 */

#include <string>
#include <iostream>
#include "domino.h"
#include "vector.h"

using namespace std;

/* Function prototype */
void printDominos(Vector<Domino> & domis);
bool formsDominoChain(Vector<Domino> & domis, int n);
// void rotateVec(Vector<Domino> & domis);
// bool isEquals(Vector<Domino> & do1, Vector<Domino> & do2);

int main()
{
	Vector<Domino> domis;
	Domino do1(1,4);
	Domino do2(1,6);
	Domino do3(2,6);
	Domino do4(3,4);
	domis.add(do1);
	domis.add(do2);
	domis.add(do3);
	domis.add(do4);
	
	printDominos(domis);
	cout << "Can Be formed: " << formsDominoChain(domis, 0) << endl;
	return 0;
}

bool formsDominoChain(Vector<Domino> & domis, int n) {
	if(domis.isEmpty()) {
		return true;
	} else {
		for (int i = 0; i < domis.size(); i++){
			Vector<Domino> rest = domis;		
			Domino hd = rest[i];
			rest.remove(i);
			int x = hd.getLeftDocs();
			int y = hd.getRightDocs();
			cout << "x,y" << x << "," << y << endl;
			if (n == 0) {
				if (formsDominoChain(rest, x) || formsDominoChain(rest, y)) {
					return true;
				}
			}
			else if (n == x)
				return formsDominoChain(rest,y);
			else if (n == y)
				return formsDominoChain(rest,x);
			rest.add(hd);
			// return formsDominoChain(rest,0);
		}
	}
	return false;
}


void printDominos(Vector<Domino> & domis) {
	cout << "----------" << endl;
	int count = 0;
	foreach(Domino domi in domis) {
		cout << "Domino" << count++ << ":" << domi << endl;
	}
	cout << "----------" << endl;
}

// void rotateVec(Vector<Domino> & domis) {
// 	if (!domis.isEmpty()) {
// 		Domino tmp = domis[0];
// 		domis.remove(0);
// 		domis.add(tmp);
// 	}
// }

// bool isEquals(Vector<Domino> & do1, Vector<Domino> & do2) {
// 	foreach(Domino d1 in do1) {
// 		foreach(Domino d2 in do2) {
// 			if(d1.getLeftDocs() != d2.getLeftDocs()
// 				|| d1.getRightDocs() != d2.getRightDocs()){
// 				return false;
// 			}
// 		}
// 	}
// 	return true;
// } 