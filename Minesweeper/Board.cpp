#include "Board.h"

Board::Board() {
	rows = 0;
	columns = 0;
}

Board::Board(int _rows, int _columns) {
	rows = _rows;
	columns = _columns;
	//creats the board object
	for (int i = 0; i < rows; i++) { //creates each row of the board
		vector<Tile> v;
		for (int j = 0; j < columns; j++) { //creates the tiles in each row
			Tile t = Tile(j, i);
			v.push_back(t);
		}
		grid.push_back(v);
	}
	
	//sets the adjacentTiles vector for each tile
	/*
    for (int i = 0; i < grid.size(); i++) {
		for (unsigned int j = 0; j < columns; j++) { //loops through the board going to each tile
			Tile t = grid[i][j];
			if ((i == 0) && (j == 0)) { //makes adjacentTiles vector for the top left corner
				//test for vector out of bounds
				//cout << "i: " << i << endl;
				//cout << "j: " << j << endl;
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(&grid[i][j + 1]);
				t.adjacentTiles.push_back(&grid[i + 1][j + 1]);
				t.adjacentTiles.push_back(&grid[i + 1][j]);
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(nullptr);
			}
			else if ((i == 0) && (j == (columns - 1))) { //makes vector for top right corner
				//test for vector out of bounds
				//cout << "i: " << i << endl;
				//cout << "j: " << j << endl;
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(&grid[i + 1][j]);
				t.adjacentTiles.push_back(&grid[i + 1][j - 1]);
				t.adjacentTiles.push_back(&grid[i][j - 1]);
				t.adjacentTiles.push_back(nullptr);
			}
			else if ((i == (rows - 1)) && (j == (columns - 1))) { //bottom right corner
				//test for vector out of bounds
				//cout << "i: " << i << endl;
				//cout << "j: " << j << endl;
				t.adjacentTiles.push_back(&grid[i - 1][j]);
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(&grid[i][j - 1]);
				t.adjacentTiles.push_back(&grid[i - 1][j - 1]);
			}
			else if ((i == (rows - 1)) && (j == 0)) { //bottom left coner
				//test for vector out of bounds
				//cout << "i: " << i << "problem?" << endl;
				//cout << "j: " << j << endl;
				t.adjacentTiles.push_back(&grid[i - 1][j]);
				t.adjacentTiles.push_back(&grid[i - 1][j + 1]);
				t.adjacentTiles.push_back(&grid[i][j + 1]);
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(nullptr);
			}
			else if (i == 0) { //makes adjacentTile vector for all remaining top row tiles
				//test for vector out of bounds
				//cout << "i: " << i << endl;
				//cout << "j: " << j << endl;
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(&grid[i][j + 1]);
				t.adjacentTiles.push_back(&grid[i + 1][j + 1]);
				t.adjacentTiles.push_back(&grid[i + 1][j]);
				t.adjacentTiles.push_back(&grid[i + 1][j - 1]);
				t.adjacentTiles.push_back(&grid[i][j - 1]);
				t.adjacentTiles.push_back(nullptr);
			}
			else if (j == (columns - 1)) { //makes vector for remaining right column tiles
				//test for vector out of bounds
				//cout << "i: " << i << endl;
				//cout << "j: " << j << endl;
				t.adjacentTiles.push_back(&grid[i + 1][j]);
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(&grid[i - 1][j]);
				t.adjacentTiles.push_back(&grid[i - 1][j - 1]);
				t.adjacentTiles.push_back(&grid[i][j - 1]);
				t.adjacentTiles.push_back(&grid[i + 1][j - 1]);
			}
			else if (i == (rows - 1)) { //remaining bottom row tiles
				//test for vector out of bounds
				//cout << "i: " << i << endl;
				//cout << "j: " << j << endl;
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(&grid[i][j + 1]);
				t.adjacentTiles.push_back(&grid[i - 1][j + 1]);
				t.adjacentTiles.push_back(&grid[i - 1][j]);
				t.adjacentTiles.push_back(&grid[i - 1][j - 1]);
				t.adjacentTiles.push_back(&grid[i][j - 1]);
				t.adjacentTiles.push_back(nullptr);
			}
			else if (j == 0) { // remaining left column tiles
				//test for vector out of bounds
				//cout << "i: " << i << endl;
				//cout << "j: " << j << endl;
				t.adjacentTiles.push_back(&grid[i + 1][j]);
				t.adjacentTiles.push_back(&grid[i + 1][j + 1]);
				t.adjacentTiles.push_back(&grid[i][j + 1]);
				t.adjacentTiles.push_back(&grid[i - 1][j + 1]);
				t.adjacentTiles.push_back(&grid[i - 1][j]);
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(nullptr);
				t.adjacentTiles.push_back(nullptr);
			}
			else { //makes adjacentTiles vector for all remaining tiles
			//test for vector out of bounds
			//cout << "i: " << i << endl;
			//cout << "j: " << j << endl;
				t.adjacentTiles.push_back(&grid[i - 1][j]);
				t.adjacentTiles.push_back(&grid[i - 1][j + 1]);
				t.adjacentTiles.push_back(&grid[i][j + 1]);
				t.adjacentTiles.push_back(&grid[i + 1][j + 1]);
				t.adjacentTiles.push_back(&grid[i + 1][j]);
				t.adjacentTiles.push_back(&grid[i + 1][j - 1]);
				t.adjacentTiles.push_back(&grid[i][j - 1]);
				t.adjacentTiles.push_back(&grid[i - 1][j - 1]);
			}
		}
	}
	*/
}

Tile& Board::GetTileFromBoard(int row, int column) {
	return grid[row][column];
}

int Board::GetNumMines() {
	int count = 0;
	for (unsigned int i = 0; i < grid.size(); i++) {
		for (unsigned int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j].GetMine() == true) {
				count++;
			}
		}
	}
	return count;
}

void Board::ClearBoard() {
	for (unsigned int i = 0; i < grid.size(); i++) {
		grid[i].clear();
	}
	grid.clear();
}

void Board::RebuildBoard(vector<vector<char>> newBoard) {
	for (unsigned int i = 0; i < newBoard.size(); i++) {
		vector<Tile> v;
		for (unsigned int j = 0; j < newBoard[i].size(); j++) {
			Tile t = Tile(j, i);			
			if (newBoard[i][j] == '0') {				
				v.push_back(t);
			}
			else if (newBoard[i][j] == '1') {
				t.SetMine(true);
				v.push_back(t);
			}
			
		}
		grid.push_back(v);
	}
}

