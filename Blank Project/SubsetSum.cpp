/*
 * File: SubsetSum.cpp
 * -------------------------
 * This file find a subset of the set given by clienter that sum to the target value.
 */

#include <iostream>
#include <string>
#include "simpio.h"
#include "vector.h"

using namespace std;

bool CanMakeSum(Vector<int> & nums, int targetSum);
bool listSubset(Vector<int> & nums, int targetSum);

int main()
{
	Vector<int> nums;
	while (true) {
		int n = getInteger("Put a number: ");
		if(n == 0) break;
		nums.add(n);
	}

	cout << "----------" << endl;

	int targetSum = getInteger("Set the target value:");

	cout << "----------" << endl;

	cout << CanMakeSum(nums, targetSum) << endl;
	for(int i = 0; i < nums.size(); i++) {
		int temp = nums[0];
		nums.remove(0);
		nums.add(temp);
		listSubset(nums, targetSum);
	}

	
	return 0;
}

bool CanMakeSum(Vector<int> &nums, int targetSum) {
	if (nums.isEmpty()) return targetSum == 0;
	else {
		// for (int i = 0 ; i < nums.size(); i++) {
			// int element = nums[i];
			int element = nums[0];
			Vector<int> rest = nums;
			// rest.remove(i);
			rest.remove(0);
			return CanMakeSum(rest, targetSum - element) || CanMakeSum(rest, targetSum);
		// }
	}
}

bool listSubset(Vector<int> & nums, int targetSum) {
	

	if (targetSum == 0) {
		cout << "Finded!" << endl;
		return true;
	} else {
			if(nums.isEmpty()) return false;
		// for (int i = 0 ; i < nums.size(); i++) {
			// int element = nums[i];
			int element = nums[0];
			Vector<int> rest = nums;
			// rest.remove(i);
			rest.remove(0);
			if (listSubset(rest, targetSum - element)) {
				cout << element << ", ";
				return true;
			}
			if (listSubset(rest, targetSum)) return true; 
			return false;
		// }		
	}

}