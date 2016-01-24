/*
 * File: SubsetSum.cpp
 * -------------------------
 * This file find a subset of the set given by clienter that sum to the target value.
 */

#include <iostream>
#include <string>
#include "simpio.h"
#include "vector.h"
#include "map.h"

using namespace std;

bool CanMakeSum(Vector<int> & nums, int targetSum);
bool listSubset(Vector<int> & nums, int targetSum);
Map<int, Vector<int> > subSetSumVecs(Vector<int> & vec, int length, int index);

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
	
	listSubset(nums, targetSum);
	
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

void listSubset(Vector<int> & nums, int targetSum) {
	subSetSumVecs(nums, targetSum, 0).toString();
}

Map<int, Vector<int> > subSetSumVecs(Vector<int> & vec, int length, int index) {
	Map<int, Vector<int> > result;
	if (length == 0) {
		cout << "Finded,index: " << index << endl;
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
		Map<int, Vector<int> > subSets = subSetSumVecs(rest, length - element, index);
		// cout << subSet.toString() << endl;
		foreach(int n in subSets) {
			Vector<int> subSet = subSets.get(n);
			if (subSet[0] == 0) subSet.remove(0);
			subSet += element;
			result.put(index, subSet);
			index++;
		}

		subSets = subSetSumVecs(rest, length, index);
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