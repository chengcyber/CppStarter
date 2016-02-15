/*
 * File: bufferpriv.h
 * ------------------
 * This file contains the private section of the EditorBuffer class for
 * the array-based editor.
 */
/*
 * Implementation notes: Buffer data structure
 * -------------------------------------------
 * In the array-based implementation of the buffer, the characters in the
 * buffer are stored in a dynamic array.  In addition to the array, the
 * structure keeps track of the capacity of the buffer, the length of the
 * buffer, and the cursor position.  The cursor position is the index of
 * the character that follows where the cursor would appear on the screen.
 */
private:
/* Instance variables */
   char *array;          /* Dynamic array of characters     */
   int capacity;         /* Allocated size of that array    */
   int length;           /* Number of character in buffer   */
   int cursor;           /* Index of character after cursor */
/* Make it illegal to copy editor buffers */
   EditorBuffer(const EditorBuffer & value) { }
   const EditorBuffer & operator=(const EditorBuffer & rhs) { return *this; }
/* Private method prototype */
   void expandCapacity();