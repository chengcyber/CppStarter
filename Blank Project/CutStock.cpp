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
Vector<int> getSubSetCuted(Vector<int> & vec, int length);

/* Main program */

int main() 
{
	Vector<int> stock;
	stock += 4,3,4,1,7,8;

	cout << canCuted(stock, 10) << endl;

	cout << getSubSetCuted(stock, 10).toString() << endl;

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

Vector<int> getSubSetCuted(Vector<int> & vec, int length) {
	Vector<int> result;
	if (vec.isEmpty() || length < 0) {

	} else {
		Vector<int> rest = vec;
		int element = rest[0];
		rest.remove(0);
		foreach(int n in getSubSetCuted(rest, length - element))
			result.add(element);
	}
	return result;
}