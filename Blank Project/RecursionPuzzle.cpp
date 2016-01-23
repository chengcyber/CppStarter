/*
 * File: RecursionPuzzle.cpp
 * -------------------------
 * You have been given a puzzle consisting of a row of squares each containing an integer, like this:
 * 3 6 4 1 3 4 2 5 3 0
 * The circle on the initial square is a marker that can move to other squares along the row. At each step
 * in the puzzle, you may move the marker the number of squares indicated by the integer in the square
 * it currently occupies. The marker may move either left or right along the row but may not move past
 * either end. For example, the only legal first move is to move the marker three squares to the right
 * because there is no room to move three spaces to the left.
 * The goal of the puzzle is to move the marker to the 0 at the far end of the row. In this configuration,
 * you can solve the puzzle by making the following set of moves:
 * Starting	3 6 4 1 3 4 2 5 3 0
 * position	3 6 4 1 3 4 2 5 3 0
 * Step 1:		3 6 4 1 3 4 2 5 3 0
 * Move right	3 6 4 1 3 4 2 5 3 0
 * Step 2:		3 6 4 1 3 4 2 5 3 0
 * Move left	3 6 4 1 3 4 2 5 3 0	
 * Step 3:		3 6 4 1 3 4 2 5 3 0
 * Move right	3 6 4 1 3 4 2 5 3 0	
 * Step 4:		3 6 4 1 3 4 2 5 3 0
 * Move right	3 6 4 1 3 4 2 5 3 0	
 * Step 5:		3 6 4 1 3 4 2 5 3 0
 * Move left	3 6 4 1 3 4 2 5 3 0	
 * Step 6:		3 6 4 1 3 4 2 5 3 0
 * Move right	3 6 4 1 3 4 2 5 3 0	
 * Even though this puzzle is solvable¡ªand indeed has more than one solution¡ªsome puzzles of this
 * form may be impossible, such as the following one:
 * 3 1 2 3 0
 * In this puzzle, you can bounce between the two 3¡¯s, but you cannot reach any other squares.
 */

#include <iostream>
#include <string>
#include "simpio.h"
#include "vector.h"

using namespace std;

bool Solvable(int start, Vector<int> & squares);

int main()
{
	Vector<int> puzzle1, puzzle2;
	puzzle1 += 3, 6, 4, 1, 3, 4, 2, 5, 3, 0;
	puzzle2 +=3, 1, 2, 3, 0;

	cout << "puzzle: " << endl;
	cout << puzzle1.toString() << endl;
	cout << puzzle2.toString() << endl;
	
	// cout << puzzle.size();
	cout << Solvable(0, puzzle1) << endl;
	cout << puzzle1.toString() << endl;
	cout << Solvable(0, puzzle2) << endl;
	cout << puzzle2.toString() << endl;

	return 0;
}

bool Solvable(int start, Vector<int> & squares) {
	if (start < 0 || start >= squares.size()) return false;
	if (start == squares.size() - 1) return true;
	if (squares[start] == 0) return false;
	int ip = squares[start];
	squares[start] = 0;
	if(Solvable((start + ip), squares) || Solvable((start - ip), squares))
		return true;
	squares[start] = ip;
	return false;
}