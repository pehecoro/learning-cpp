#include <iostream>

/*
	
	Rat in a Maze - Backtracking

	+------>(x)
	|
	|
	v (y)
	
*/
const int SIZE = 4;

const int maze[SIZE][SIZE] = { { 1,1,0,1 },
							{ 0,1,1,1 },
							{ 0,0,0,1 },
							{ 0,1,0,1 } };

bool isLegal(int x, int y) {
	if (maze[x][y] == 0 || (x > SIZE || x < 0 || y < 0 || y > SIZE)) {
		return false;
	}
	return true;
}

bool solveMaze(int x, int y, int sol[SIZE][SIZE]) {
	if (x == (SIZE - 1) && y == (SIZE - 1)) { // Goal
		sol[x][y] = 1;
		return true;
	}if (isLegal(x, y)) {
		sol[x][y] = 1;

		if (solveMaze(x + 1, y, sol))return true;
		if (solveMaze(x, y + 1, sol))return true;

		sol[x][y] = 0;//Backtrack
	}
	return false;
}

int main() {

	int x = 0, y = 0;
	int sol[SIZE][SIZE] = { { 0,0,0,0 },
					{ 0,0,0,0 },
					{ 0,0,0,0 },
					{ 0,0,0,0 } };
	
	if (!solveMaze(x, y, sol)) {
		std::cout << "Impossible to solve" << std::endl;
	}
	else {
		for (int y = 0; y < 4; ++y) {
			for (int x = 0; x < 4; ++x) {
				std::cout << sol[x][y];
			}
			std::cout << std::endl;
		}
	}

	std::cin.get();
}