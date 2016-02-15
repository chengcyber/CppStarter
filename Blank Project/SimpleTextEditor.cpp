/*
 * File: SimpleTextEditor.cpp
 * --------------------------
 * This program implements a simple command-driven text editor, which is
 * used to test the EditorBuffer class.
 */
#include <iostream>
#include <string>
#include <cctype>
#include "editorbuffer.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;
/* Function prototypes */
void executeCommand(EditorBuffer & buffer, string line);
/* Main program */
int main() {
   EditorBuffer buffer;
   while (true) {
      string cmd = getLine("*");
      if (cmd != "") executeCommand(buffer, cmd);
      buffer.showContents();
   }
   return 0;
}
/*
 * Function: executeCommand
 * Usage: executeCommand(buffer, line);
 * ------------------------------------
 * Executes the command specified by line on the editor buffer.
 */
void executeCommand(EditorBuffer & buffer, string line) {
  int num = 0;
  int index = 0;
  for(int i = 0; i < line.length(); i++){
    if(line[i] >= '0' && line[i] <= '9') {
      num = num * 10 + line[i] - '0';
    } else {
      index = i;
      break;
    }
  }
  if(num == 0) num = 1;
  line = line.substr(index);
   switch (toupper(line[0])) {
    case 'I': for (int i = 1; i < line.length(); i++) {
                buffer.insertCharacter(line[i]);
              }
              break;
    case 'D': for(int i = 0; i < num; i++ ) {
                buffer.deleteCharacter(); 
              }
              break;
    case 'F': for(int i = 0; i < num; i++ ) {
                buffer.moveCursorForward();
              } 
              break;
    case 'B': for(int i = 0; i < num; i++ ) {
                buffer.moveCursorBackward();
              }
              break;
    case 'W': if(toupper(line[1]) == 'F') {
                buffer.moveCursorForwardWord();
              } else if(toupper(line[1]) == 'B') {
                buffer.moveCursorBackwardWord(); 
              } else if(toupper(line[1]) == 'D') {
                buffer.deleteWord();
              }
              break;
    case 'J': buffer.moveCursorToStart(); break;
    case 'E': buffer.moveCursorToEnd(); break;
    case 'T': buffer.showContents();break;
    case 'Q': exit(0);
    default:  cout << "Illegal command" << endl; break;
   }
}