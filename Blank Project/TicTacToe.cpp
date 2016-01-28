/*
 * File: TicTacToeGame.cpp
 * -------------------------
 * The  game  of  tic-tac-toe  is  played  by  two  players  who  take  turns  placing 
 * Xs and Os in a 3×3 grid that looks like this: 
 *	  |	  |
 * ---+---+---
 *	  |	  |
 * ---+---+---
 *	  |	  |
 */

#include "gwindow.h"
#include <iostream>
#include <string>
#include "grid.h"
#include <cctype>
#include "simpio.h"
#include <cmath>
#include "vector.h"

using namespace std;

/* Constants */
const int N_GAMESIZE = 3;
const int N_GOAL = 3;
const int NO_GOOD_MOVE = -1;


/*
 * Type: Player
 * -------------------------
 * This emuerated type differentiates the huamn and computer players.
 */
enum Player { HUMAN, COMPUTER };


/*
 * Class: Move
 * -------------------------
 * 
 */
class Move {
public:
	int getSquares() {
		return squares;
	}

	void setSquares(int x) {
		squares = x;
	}

private:
	int squares;
	// friend class TicTacToe;
};

/*
 * Class: TicTacToe
 * -------------------------
 * The simple version of TicTacToe game.
 */

class TicTacToe {

public:

/*
 * Method: play
 * Usage: game.play()
 * -------------------------
 * Plays one game of TicTacToe with the human player.
 */
void play() {
	initGame(); 
	while (!gameIsOver()) { 
		showGameStatus(); 
		if (getCurrentPlayerType() == HUMAN) { 
		   makeMove(getUserMove()); 
		} else { 
		   Move move = getComputerMove(); 
		   displayMove(move); 
		   makeMove(move);
		} 
	} 
	announceResult(); 
}

/*
 * Method: showInstructions
 * Usage: game.showInstructions()
 * -------------------------
 * This method explains the rules of game to the user.
 */
void showInstructions() {
	cout << "Welcome to TicTacToe, the game of three in a row." << endl;
	cout << "I'll be X, and you'll be O." << endl;
	cout << "The squares are numbered like this:" << endl;
	cout << " 1 | 2 | 3" << endl;
	cout << "---+---+---" << endl;
	cout << " 4 | 5 | 6" << endl;
	cout << "---+---+---" << endl;
	cout << " 7 | 8 | 9" << endl;	
	cout << endl;
}

private:
/*
 * Method: initGame
 * Usage: initGame()
 * -------------------------
 * Init the game.
 */
void initGame() {
	whoseturn = COMPUTER;
	grid.resize(N_GAMESIZE, N_GAMESIZE);
	for(int i = 0; i < grid.numRows(); i++) {
		for(int j = 0; j < grid.numCols(); j++) {
			grid[i][j] = ' ';
		}
	}
}

/*
 * Method: getCurrentPlayerType
 * Usage: Player p = getCurrentPlayerType()
 * -------------------------
 * 
 */
Player getCurrentPlayerType() {
	return whoseturn;
}

/*
 * Method: makeMove
 * Usage: makeMove(move)
 * -------------------------
 * This method move the game one step
 */
void makeMove(Move & move) {
	int s = move.getSquares();
	int row = (s - 1) / N_GAMESIZE;
	int col = (s - 1) % N_GAMESIZE;
	if(whoseturn == HUMAN) grid[row][col] = 'O';
	else grid[row][col] = 'X';
	whoseturn = (whoseturn == HUMAN) ? COMPUTER : HUMAN;
}


/*
 * Method: displayMove
 * Usage: displayMove(move)
 * -------------------------
 * show the computer decision.
 */
void displayMove(Move & move) {
	int s = move.getSquares();
	cout << "I choose square " << s << endl;
}

/*
 * Method: getUserMove
 * Usage: Move move = getUserMove()
 * -------------------------
 * Returns a move class to stroe the user decision.
 */
Move getUserMove() {
	cout << "Your turn." << endl;
	int max = N_GAMESIZE * N_GAMESIZE;
	Move move;
	int s;
	while (true) {
		s = getInteger("Choose a square to move:");
		if (0 < s && s <= max) {
			int row = (s - 1) / N_GAMESIZE;
			int col = (s - 1) % N_GAMESIZE;
			if(grid[row][col] == ' ') break;
			cout << "***  Already choosed ! Try another.  ***" << endl;
		} else {
			cout << "***  out of range! Try again.   ***" << endl;
			cout << "***  Range: 1 - " << max << "   ***" << endl; 
		}
	}
	move.setSquares(s);
	return move;
}

/*
 * Method: getComputerMove
 * Usage: Move move = getComputerMove()
 * -------------------------
 * Returns a move class to store the computer decision.
 */
Move getComputerMove() {
	Move move;
	int s = findGoodMove(grid);
	if (s == NO_GOOD_MOVE) {
		s = getAvailablePosition(grid)[0];
	}
	move.setSquares(s);
	return move;
}

int findGoodMove(Grid<char> & grid) {
	Vector<int> available = getAvailablePosition(grid);
	cout << "available: "<< available.toString() << endl;
	for(int i = 0 ; i < available.size(); i++){
		int s = available[i];
		int row = (s - 1) / N_GAMESIZE;
		int col = (s - 1) % N_GAMESIZE;
		Grid<char> rest = grid;
		rest[row][col] = 'X';
		// cout << rest.toString() << endl;
		// available.remove(i);
		if(checkWin('X', rest)) return s;
		rest[row][col] = 'O';
		if(isBadPosition(rest)) return s;
		rest[row][col] = ' ';
		// cout << rest.toString() << endl;
		// available.add(i);
	}
	return NO_GOOD_MOVE;
}

bool isBadPosition(Grid<char> & grid) {
	// if(getAvailablePosition(grid).isEmpty()) return false;
	if(checkWin('O', grid)) return true;
	return findGoodMove(grid) == NO_GOOD_MOVE;
}

Vector<int> getAvailablePosition(Grid<char> & grid) {
	Vector<int> result;
	for(int i = 0; i < grid.numRows(); i++) {
		for(int j = 0; j < grid.numCols(); j++) {
			if (grid[i][j] == ' ') {
				int s = i * N_GAMESIZE + j + 1;
				result.add(s);
			}
		}
	}
	return result;
}


/*
 * Method: showGameStatus
 * Usage: showGameStatus()
 * -------------------------
 * This method show the status of the game process.
 */
void showGameStatus() {
	cout << "The game now look likes this:" << endl;
	for(int i = 0 ; i < N_GAMESIZE; i ++) {
		for(int j = 0; j < N_GAMESIZE; j++) {
			if (j == 0) cout << " ";
			cout << grid[i][j];
			if (j != N_GAMESIZE  - 1) cout << " | ";
			else cout << endl;
		}
		if ( i != N_GAMESIZE - 1)
		cout << "---+---+---" << endl;
	}
	cout << endl;
}

/*
 * Method: gameIsOver
 * Usage: gameisOver()
 * -------------------------
 * This method returns true if one of the player win or the game draw.
 */
bool gameIsOver() {
	/* draw */
	bool draw = true;
	foreach(char ch in grid) {
		if (ch == ' ') {
			draw = false;
			break;
		}
	}
	/* someone win */
	bool com = checkWin('X', grid);
	bool hum = checkWin('O', grid);
	/* Set winner */
	if (hum) winner = HUMAN;
	if (com) winner = COMPUTER;
	return draw || hum || com;
}

bool checkWin(char ch, Grid<char> & grid) {
	int cnt_win = 0;
	for(int i = 0; i < grid.numRows(); i++) {
		for(int j = 0; j < grid.numCols(); j++) {
			/* Check horizontally | */
			if( j <= grid.numCols() - N_GOAL) {
				for(int h = 0; h < N_GOAL; h++) {
					if(grid[i][j+h] == ch)
						cnt_win++;
				}
				if(cnt_win == 3) return true;
				else cnt_win = 0;
			}
			/* Check verticallly --- */
			if( i <= grid.numRows() - N_GOAL) {
				for(int v = 0; v < N_GOAL; v++) {
					if(grid[i+v][j] == ch)
						cnt_win++;
				}
				if(cnt_win == 3) return true;
				else cnt_win = 0;
			}
			/* Check diagonally \\\ */
			if( i <= grid.numRows() - N_GOAL && j <= grid.numCols() - N_GOAL) {
				for(int d = 0; d< N_GOAL; d++) {
					if(grid[i+d][j+d] == ch)
						cnt_win++;
				}
				if(cnt_win == 3) return true;
				else cnt_win = 0;
			}
			/* Check diagonally /// */
			if(i >= N_GOAL - 1 && j <= grid.numCols() - N_GOAL) {
				for(int e = 0; e < N_GOAL; e++) {
					if(grid[i-e][j+e] == ch)
						cnt_win++;
				}
				if(cnt_win == 3) return true;
				else cnt_win = 0;
			}
		}
	}
	return false;
}

/*
 * Method: announceResult
 * Usage: announceResult()
 * -------------------------
 * This method announce the final result.
 */
void announceResult() {
	cout << "The final position look like this:" << endl;
	showGameStatus();
	if(winner == HUMAN) cout << "I lose :(" << endl;
	else if (winner == COMPUTER) cout << "I win :)" << endl;
	else cout << "Game draw ." << endl;
}

/* instatnce variables */
	Grid<char> grid;
	Player whoseturn;
	Player winner;
};

/* Main program */
int main()
{
	TicTacToe ttt;
	ttt.showInstructions();
	ttt.play();
	return 0;
}




