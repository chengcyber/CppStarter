/* File: intarray.h
 * -------------------
 * The file descript class IntArray.
 */

#ifndef _IntArray_h
#define _IntArray_h


class IntArray {

public:

/* Constructor: IntArray
 * Usage: intArray(n)
 * -------------------
 * Creates a array contain n integer number.
 */
IntArray(int n);

/* Destructor: ~IntArray
 * Automatic
 * -------------------
 * automatic called when the object disappear
 */
~IntArray();

/* Method: size
 * Usage: int s = intArray.size()
 * -------------------
 * Returns the size of intArray.
 */
int size();

/* Method: get
 * Usage: int n = intArray.get(k)
 * -------------------
 * Returns the index k element of intArray. If k is not within the bounds of the array, call error with a message explaining the problem.
 */
int get(int k);

/* Method: put
 * Usage: intArray.put(k, value)
 * -------------------
 * Assagin the index k element with value. If k is not within the bounds of the array, call error with a message explaining the problem.
 */
void put(int k, int value);

/* Operator Overloading []
 * Usage: int n = intArray[k]
 * -------------------
 * Returns the index k element of Array. Also check bound.
 */
int & operator[](int k);

#include "intarraypriv.h"

};




#endif