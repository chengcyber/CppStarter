/* File: FindDuplicate.cpp
 * -------------------
 * Given an array of n elements which contains elements from 0 to n-1,
 * with any of these numbers appearing any number of times. 
 * Find these repeating numbers in O(n) and using only constant memory space.
 * 
 * For example, let n be 7 and array be {1, 2, 3, 1, 3, 6, 6}, 
 * the answer should be 1, 3 and 6.
 * 
 * This problem is an extended version of following problem.
 * 
 * Find the two repeating elements in a given array
 * http://www.geeksforgeeks.org/find-the-two-repeating-elements-in-a-given-array/
 * 
 */

#include <iostream>
#include <string>
#include "vector.h"
#include <cmath>

using namespace std;

int findDuplicate(Vector<int> & vec);
void printDuplicate(Vector<int> & vec);

int main()
{
	Vector<int> vec;
	vec += 1,2,3,4,3,4,3,4;
	cout << "Vec: " << vec.toString() << endl;
	// cout << "Duplicate: " << findDuplicate(vec) << endl;
	printDuplicate(vec);
	return 0;
}

/*
 * http://www.geeksforgeeks.org/find-the-two-repeating-elements-in-a-given-array/
 * can be used only in integer value vector, and without 0.
 */

// run in O(N) time, use only O(1) additional space.
void printDuplicate(Vector<int> & vec) {
	for (int i = 0; i < vec.size(); i++) {
		if(vec[abs(vec[i])] >= 0) {
			vec[abs(vec[i])] = -vec[abs(vec[i])];
		} else {
			cout << abs(vec[i]) << endl;	
		}

	}
}

/*
 * http://www.keithschwarz.com/interesting/code/?dir=find-duplicate
 * can not understand...
 */

// int findDuplicate(Vector<int> & vec) {
// 	int size = vec.size();
// 	int slow = size - 1;
// 	int fast = size - 1;
// 	while(true) {
// 		slow = vec[slow];
// 		fast = vec[vec[fast]];
// 		if (slow == fast) {
// 			break;
// 		}
// 	}

// 	int finder = size - 1;
// 	while(true) {
// 		slow = vec[slow];
// 		finder = vec[finder];
// 		if (slow == finder) {
// 			return slow;
// 		}
// 	}

// }