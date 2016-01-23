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

using namespace std;

/* Function prototyep */
bool canCuted(Vector<int> & vec, int length);
void subSetSum(Vector<int> & vec, int length, Vector<int> & result);
// int CutStock(Vector<int> & requests, int stockLength);

/* Main program */

int main() 
{
	Vector<int> stock, result;
	// stock += 4,3,4,1,7,8;
	stock += 7,3,1;

	cout << canCuted(stock, 10) << endl;

	subSetSum(stock, 10, result);
	cout << result.toString() << endl;

	return 0;
}

bool canCuted(Vector<int> & vec, int length) {
	if (vec.isEmpty()) {
		return length == 0;
	} else {
		Vector<int> rest = vec;
		int element = rest[0];
		rest.remove(0);
		if (canCuted(rest, length) || canCuted(rest, length - element))
			return true;
	}

}

void subSetSum(Vector<int> & vec, int length, Vector<int> & result) {
	if (length == 0) {
		result.add(0);
		cout << result.toString() << endl;
	} else if (vec.isEmpty() || length < 0) {

	} else {
		Vector<int> rest = vec;
		int element = rest[0];
		rest.remove(0);
		for (int i = 0; i < rest.size(); i++) {
			subSetSum(rest, length - element, result);
			for(int j = 0; j < result.size(); j++)
				if (result[j] == 0) result[j] = element;
		}
	}
}

// int CutStock(Vector<int> & requests, int stockLength) {
// 	if (stockLength == 0) return count ;
// 	Vector<int> rest = requests;
// 	int count = 0;
// 	Vector<int> subSum = subSetSum(rest, stockLength);
// 	if (subSum.isEmpty()) {
// 		return count + CutStock(rest, stockLength -1);
// 	} else {
// 		for(int i = 0; i < rest.size(); i++) {
// 			for (int j = 0 ; j < subSum.size(); j++) {
// 				if (rest[i] == subSum[j]) {
// 					subSum.remove(j);
// 					rest.remove(i);
// 				}

// 			}
// 		}
// 		return 1 + CutStock(rest, stockLength);
// 	}
// }