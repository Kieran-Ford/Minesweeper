#pragma once
#include <vector>
#include "Tile.h"

using namespace std;

class Board
{
	int rows;
	int columns;

public:
	vector<vector<Tile>> grid;

	Board();

	Board(int _rows, int _columns);

	Tile& GetTileFromBoard(int row, int column);

	int GetNumMines();

	void ClearBoard();

	void RebuildBoard(vector<vector<char>> newBoard);
};
