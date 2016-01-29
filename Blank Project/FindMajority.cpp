/*
 * File: FindMajority.cpp
 * -------------------------
 * that takes a vector of nonnegative integers and returns the majority element, 
 * which is defined to be a value that occurs in an absolute majority (at least 50 
 * percent plus one) of the element positions.  If no majority element exists, the 
 * function should return –1 to signal that fact.  Your function must also meet the 
 * following conditions: 
 *  
 * •  It must run in O(N) time. 
 * •  It must use O(1) additional space.  In other words, it may use individual 
 * temporary  variables  but  may  not  allocate  any  additional  array  or  vector 
 * storage.  Moreover, this condition rules out recursive solutions, because the 
 * space required to store the stack frames would grow with the depth of the 
 * recursion. 
 * •  It may not change any of the values in the vector. 
 *  
 * The  hard  part  about  this  problem  is  coming  up  with  the  algorithm,  not 
 * implementing it.  Play with some sample vectors and see if you can come up 
 * with the right strategy. 
 */

#include <string>
#include <iostream>
#include "vector.h"

using namespace std;

int findMajorityElement(Vector<int> &vec);
int findCandidate(Vector<int> &vec);
bool isMajority(Vector<int> &vec, int cand);

int main()
{
	Vector<int> vec;
	// vec += 2, 3, 5, 2, 2, 6;
	vec += 2, 2, 3, 5, 2, 2, 6;
	cout << "vec: " << vec.toString() << endl;
	cout << "majority: " << findMajorityElement(vec) << endl;
	return 0;
}


/*
 * http://www.geeksforgeeks.org/majority-element/
 */

int findMajorityElement(Vector<int> &vec) {
	int cand = findCandidate(vec);
	if (isMajority(vec, cand)) {
		return cand;
	} 
	return -1;
}

int findCandidate(Vector<int> &vec) {
	int majIndex = 0;
	int cntMaj = 1;
	for(int i = 1; i < vec.size(); i++) {
		if(vec[i] == vec[majIndex]) {
			cntMaj++;
		} else {
			cntMaj--;
		}
		if(cntMaj == 0) {
			majIndex = i;
			cntMaj = 1;
		}
	}
	return vec[majIndex];
}

bool isMajority(Vector<int> &vec, int cand) {
	int cnt = 0;
	for(int i = 0; i < vec.size(); i++) {
		if(vec[i] == cand) {
			cnt++;
		}
	}
	if(cnt > vec.size() / 2) {
		return true;
	}
	return false;
}