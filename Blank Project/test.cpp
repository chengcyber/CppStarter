#include "grid.h"
#include <iostream>

using namespace std;

int main()
{
	Grid<char> grid;
	grid.resize(3,3);
	for(int i = 0; i < grid.numRows(); i++) {
		for(int j = 0; j < grid.numCols(); j++) {
			grid[i][j] = ' ';
		}
	}
	cout << grid.toString() << endl;
	return 0;
}