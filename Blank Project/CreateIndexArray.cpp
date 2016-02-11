/* File: CreateIndexArray.cpp
 * -------------------
 * Write a function createIndexArray(n) that allocates a dynamic array of n
 * integers in which each integer is initialized to its own index. For example,
 * calling createIndexArray(8) should return a pointer to the following array
 * on the heap:
 */

#include <iostream>
#include <string>

using namespace std;

/* Function prototypes */
int *createIndexArray(int n);


/* Main program */

int main()
{
	int *p = createIndexArray(8);
	for(int i = 0; i < 8; i++) 
	cout << *(--p) << endl;
	// cout << p << endl;
	return 0;
}

int* createIndexArray(int n) {
	int* array = new int[n];
	for(int i = 0; i < n; i++) {
		*array++ = i;
	}
	return array;
}