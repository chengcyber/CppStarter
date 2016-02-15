/* File: intarraypriv.h
 * -------------------
 * private section of IntArray Class.
 */

public:

	// IntArray(const IntArray & iArr);
	// IntArray & operator= (const IntArray & iArr);
IntArray(const IntArray & iArr) {
	copyInternalDate(iArr);
}

IntArray & operator= (const IntArray & iArr) {
	if(this != & iArr) {
		delete[] arr;
		copyInternalDate(iArr);
	}
	return *this;
}

private:

	int *arr;
	int capacity;

	// void copyInternalData(const IntArray & iArr);
	void copyInternalDate(const IntArray & iArr) {
		arr = new int[iArr.capacity];
		for(int i = 0; i < iArr.capacity; i++) {
			arr[i] = iArr.arr[i];
		}
		capacity = iArr.capacity;
	}