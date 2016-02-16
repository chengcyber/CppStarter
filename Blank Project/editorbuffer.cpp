/*
 * File: ArrayBuffer.cpp
 * ---------------------
 * This file implements the buffer.h interface using an array representation.
 */
#include <iostream>
#include <string>
#include "editorbuffer.h"
#include "vector.h"
using namespace std;
/* Constants */
const int INITIAL_CAPACITY = 10;
/*
 * Implementation notes: Constructor and destructor
 * ------------------------------------------------
 * The constructor initializes the private fields.  The destructor
 * frees the heap-allocated memory, which is the dynamic array.
 */
EditorBuffer::EditorBuffer() {
   capacity = INITIAL_CAPACITY;
   array = new char[capacity];
   copyArr = NULL;
   length = 0;
   cursor = 0;
   copyLen = 0;
}
EditorBuffer::~EditorBuffer() {
   delete[] array;
   delete[] copyArr;
}
/*
 * Implementation notes: moveCursor methods
 * ----------------------------------------
 * The four moveCursor methods simply adjust the value of cursor.
 */
void EditorBuffer::moveCursorForward() {
   if (cursor < length) cursor++;
}
void EditorBuffer::moveCursorBackward() {
   if (cursor > 0) cursor--;
}
void EditorBuffer::moveCursorToStart() {
   cursor = 0;
}
void EditorBuffer::moveCursorToEnd() {
   cursor = length;
}
void EditorBuffer::moveCursorForwardWord() {
	if( cursor < length) {
		if(isspace(array[cursor])) {
			while(true) {
				if((cursor == length) || !isspace(array[cursor])) break;
				cursor++;
			}
		} else {
			while(true) {
				if((cursor == length) || isspace(array[cursor])) break;
				cursor++;
			}
		}
	}
}
void EditorBuffer::moveCursorBackwardWord() {
	if (cursor > 0) {
		if (isspace(array[cursor - 1])) {
			while(true) {
				if((cursor == 0) || !isspace(array[cursor - 1])) break;
				cursor--;
			}
		} else {
			while(true) {
				if((cursor == 0) || isspace(array[cursor - 1])) break;
				cursor--;
			}
		}
	}
}

/*
 * Implementation notes: insertCharacter and deleteCharacter
 * ---------------------------------------------------------
 * Each of the functions that inserts or deletes characters must shift
 * all subsequent characters in the array, either to make room for new
 * insertions or to close up space left by deletions.
 */
void EditorBuffer::insertCharacter(char ch) {
   if (length == capacity) expandCapacity();
   for (int i = length; i > cursor; i--) {
      array[i] = array[i - 1];
   }
   array[cursor] = ch;
   length++;
   cursor++;
}
void EditorBuffer::deleteCharacter() {
   if (cursor < length) {
      for (int i = cursor+1; i < length; i++) {
         array[i - 1] = array[i];
      }
      length--;
   }
}
void EditorBuffer::deleteWord() {
	while (cursor < length) {
		if(!isspace(array[cursor])) break;
		this->deleteCharacter();
	}
	while (cursor < length) {
		if(isspace(array[cursor])) break;
		this->deleteCharacter();
	}
}

/*
 * Implementation notes: showContents
 * ----------------------------------
 * This method prints the contents of the buffer with one space between
 * each character to leave room for a caret on the next line to indicate
 * the position of the cursor.
 */
void EditorBuffer::showContents() {
   for (int i = 0; i < length; i++) {
      cout << " " << array[i];
   }
   cout << endl;
   for (int i = 0; i < 2 * cursor; i++)
      cout << ' ';
   cout << "^" << endl;
}


/*
 * Implementation note: expandCapacity
 * -------------------------
 * This private method doubles the size of the array whenever the old one
 * runs out of space. To do so, expandCapacity allocates a new array,
 * copies the old characters to the new array, and then frees the old array.
 */
void EditorBuffer::expandCapacity() {
   char *oldArray = array;
   capacity *= 2;
   array = new char[capacity];
   for(int i = 0; i < length; i++) {
      array[i] = oldArray[i];
   }
   delete[] oldArray;
}

/*
 * Implementation note: copy, paste
 * -------------------------
 * copy buffer text to an internal array
 * paste insert the text to the cursor pointed to
 */
void EditorBuffer::copy(int n) {
   copyLen = n;
   if(copyArr != NULL) delete[] copyArr;
   copyArr = new char[n];
   for(int i = 0; i < n; i++) {
      copyArr[i] = array[cursor+i];
   }
}
void EditorBuffer::paste() {
   if(copyArr != NULL) {
      for(int i = 0; i < copyLen; i++) {
         this->insertCharacter(copyArr[i]);
      }
   }
}

/*
 * Implementation note: search
 * -------------------------
 * go throught all the element in array to get the same char[].
 * if it finds it, leave the cursor after the last character in str
 * and return ture. If str does not occur between the cursor and the end
 * of the buffer, then return false.
 */
bool EditorBuffer::search(string str) {
   if(str == "") return false;
   int index = -1;
   for(int i = cursor; i < length; i++) {
      if(index != -1) break;
      if(array[i] == str[0]) {
         index = i + 1;
         for(int j = 1; j < str.length(); j++) {
            if (array[i + j] != str[j]) {
               index = -1;
               break;
            }
            index++;
         }
      }
   }
   if(index == -1) return false;
   cursor = index;
   return true;
}