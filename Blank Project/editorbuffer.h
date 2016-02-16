/*
 * File: editorbuffer.h
 * -------------------------
 * The head file contain a class buffer for editor.
 */


#ifndef _editorbuffer_h
#define _editorbuffer_h

#include <string>
/*
 * Class: EditorBuffer
 * -------------------
 * This class represents an editor buffer, which maintains an ordered
 * sequence of characters along with an insertion point called the cursor.
 */
class EditorBuffer {
public:
/*
 * Constructor: EditorBuffer
 * Usage: EditorBuffer buffer;
 * ---------------------------
 * Creates an empty editor buffer.
 */
   EditorBuffer();
/*
 * Destructor: ~EditorBuffer
 * Usage: (usually implicit)
 * -------------------------
 * Frees any heap storage associated with this buffer.
 */
   ~EditorBuffer();
/*
 * Methods: moveCursorForward, moveCursorBackward
 * Usage: buffer.moveCursorForward();
 *        buffer.moveCursorBackward();
 * -----------------------------------
 * These functions move the cursor forward or backward one character,
 * respectively.  If the command would shift the cursor beyond either
 * end of the buffer, this method has no effect.
 */
   void moveCursorForward();
   void moveCursorBackward();

/*
 * Methods: moveCursorToStart, moveCursorToEnd
 * Usage: buffer.moveCursorToStart();
 *        buffer.moveCursorToEnd();
 * --------------------------------
 * These functions move the cursor to the start or the end of this buffer.
 */
   void moveCursorToStart();
   void moveCursorToEnd();
/*
 * Method: insertCharacter
 * Usage: buffer.insertCharacter(ch);
 * ----------------------------------
 * Inserts the single character ch into this buffer at the cursor
 * position.  The cursor is then advanced to follow the inserted
 * character, thereby allowing for consecutive insertions.
 */
   void insertCharacter(char ch);
/*
 * Method: deleteCharacter
 * Usage: buffer.deleteCharacter();
 * --------------------------------
 * Deletes the character immediately after the cursor.  If the cursor is
 * at the end of the buffer, the method has no effect.
 */
   void deleteCharacter();
   void deleteWord();
/*
 * Method: showContents
 * Usage: buffer.showContents();
 * -----------------------------
 * Displays the buffer contents on the console stream and notes the
 * position of the cursor.
 */
   void showContents();
/*
 * Methods: moveCursorForwardWord, moveCursorBackwardWord
 * Usage: buffer.moveCursorForwardWord()
 *		  buffer.moveCursorBackwardWord()
 * ----------------------------------
 * These functions move the cursor forward or backward one word,
 * respectively. If the command would shift the coursor beyond either
 * end of the buffer, this method has no effect.
 */
 	void moveCursorForwardWord();
 	void moveCursorBackwardWord();
/*
 * Methods: copy, paste 
 * Usage: buffer.copy(n)
 * 		  buffer.paste
 * ----------------------------------
 * These function provide the facility that allows user to copy a section
 * of the buffer text into an internal storage area and then paste it back
 * in at some other position.
 */
 	void copy(int n);
 	void paste();
/*
 * Method: search
 * Usage: buffer.search(str)
 * ----------------------------------
 * The function search the array to figure out whether the string exists in
 * the array.
 */
 	bool search(std::string str);
#include "editorbufferpriv.h"
};

#endif
