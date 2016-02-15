/* File: intarray.cpp
 * -------------------
 * This file implementes the IntArray class.
 */

#include "intarray.h"
#include "error.h"

using namespace std;

/* Implementation notes: IntArray Construtor
 * -------------------
 * This constructor allcate the array of n,
 * and initialize the fields of the object.
 */
IntArray::IntArray(int n) {
	arr = new int[n];
	capacity = n;
	for(int i = 0; i < capacity; i++) {
		arr[i] = 0;
	}
}

/* Implementation note: IntArray Destructor
 * -------------------
 * The destructor frees any heap memory allocated by the class, which is just the dynamic array of elements.
 */
IntArray::~IntArray() {
	delete[] arr;
}

int IntArray::size() {
	return capacity;
}

int IntArray::get(int k) {
	if (k >= capacity) error("ERR: out of range");
	int* p = arr;
	p = p + k;
	return *p;
}

void IntArray::put(int k, int value) {
	if (k >= capacity) error("ERR: out of range");
	int *p = arr;
	*(p + k) = value;
}

int & IntArray::operator[](int k) {
	return arr[k];
}




