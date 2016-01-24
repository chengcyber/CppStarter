/*
 * File: CutStock.cpp
 * -------------------------
 * You are charged with buying the plumbing pipes for a construction project. Your foreman gives you
 * a list of the varying lengths of pipe needed. Home Depot sells stock pipe in one fixed length. You
 * can divide each stock pipe in any way needed. Your job is to figure out the minimum number of
 * stock pipes required to satisfy the list of requests, thereby saving money and minimizing waste.
 * The recursive function CutStock(Vector<int> & requests, int stockLength) is given a
 * vector of the lengths needed and the stock pipe length. It returns the minimum number of stock pipes
 * needed to service all requests in the vector. For example, if the vector contains {4,3,4,1,7,8} and
 * the stock pipe length is 10, you can purchase three stock pipes and divide them as follows: {4,4,1}
 * {3,7} {8} and have two small leftover remnants. There are other possible arrangements that also fit
 * into three stock pipes, but it cannot be done with fewer.
 */

#include <iostream>
#include <string>
#include "simpio.h"
#include "vector.h"
#include "map.h"

using namespace std;

/* Function prototyep */
bool canCuted(Vector<int> & vec, int length);
// bool isSubVec(Vector<int> subvec, Vector<int> vec);
Map<int, Vector<int> > subSetSumVecs(Vector<int> & vec, int length);
int CutStock(Vector<int> & requests, int stockLength);


/* Main program */

int main() 
{
	Vector<int> stock;
	stock += 4,3,4,1,7,8;
	// stock += 4,3,4,8,7,1;
	// stock += 3,4,3,7;
	int length = 10;

	cout << "stock: " << stock.toString() << endl;
	cout << "length: " << length << endl;

	cout << "canBeCuted? " << canCuted(stock, length) << endl;
	cout << "------------------" << endl;

	// cout << subSetSumVecs(stock, length).toString() << endl;
	// cout << "------------------" << endl;

	cout << CutStock(stock, length) << endl;


	return 0;
}

bool canCuted(Vector<int> & vec, int length) {
	if (length < 0) {
		return false;
	} else if (vec.isEmpty()) {return length == 0;}
	else {
		Vector<int> rest = vec;
		int element = rest[0];
		rest.remove(0);
		if (canCuted(rest, length) || canCuted(rest, length - element))
			return true;
	}

}

Map<int, Vector<int> > subSetSumVecs(Vector<int> & vec, int length) {
	Map<int, Vector<int> > result;
	int index = 0;
	if (length == 0) {
		cout << "Finded one subSet" << endl;
		Vector<int> initVec;
		initVec += 0;
		result.put(index, initVec);
		// cout << result.toString() << endl;
	} else if (vec.isEmpty() || length < 0) {
		// return result;
	} else {
		Vector<int> rest = vec;
		int element = rest[0];
		rest.remove(0);
		Map<int, Vector<int> > subSets = subSetSumVecs(rest, length - element);
		// cout << subSet.toString() << endl;
		foreach(int n in subSets) {
			Vector<int> subSet = subSets.get(n);
			if (subSet[0] == 0) subSet.remove(0);
			subSet += element;
			result.put(index, subSet);
			index++;
		}

		subSets = subSetSumVecs(rest, length);
		foreach (int n in subSets)  {
			Vector<int> subSet = subSets.get(n);
			result.put(index, subSet);
			index++;
		}
		// cout << "---rest, length----" << endl;
		// cout << subSetSum(rest,length) << endl;
	}
	return result;
}


int CutStock(Vector<int> & requests, int stockLength) {
	int count = 0;
	if ( stockLength == 0) {

	} else if(requests.isEmpty()) {
		
	} else {
		
		while (true) {
			Map<int, Vector<int> > map = subSetSumVecs(requests, stockLength);
			if (map.isEmpty()) break;
			Vector<int> tmp = map.get(0);
			// if (!isSubVec(tmp, requests)) break; 
			cout << "Find one cuted:" << tmp.toString() << endl;
			for(int i = 0; i < requests.size(); i++) {
				for(int j = 0; j < tmp.size(); j++) {
					if (tmp[j] == requests[i]) {
						requests.remove(i);
						tmp.remove(j);
						j--;
						// cout << requests.toString() << endl;
						// cout << tmp.toString() << endl;
					}
				}
			}
			// if (tmp.isEmpty())
				count++;
			// else
				// break;
		}
		return count + CutStock(requests, stockLength - 1);
	}
	return count;
}

// bool isSubVec(Vector<int> subvec, Vector<int> vec) {
// 	foreach(int n in subvec) {

// 	}

// }