#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

	class Tile
	{
		bool mine;
		bool flag;
		bool revealed;
		bool visited = false;
		int number;
		int posX;
		int posY;
		int adjacentMines = 0;
				


	public:
		vector<Tile*> adjacentTiles;

		Tile();

		Tile(int _posX, int _posY);

		Tile(bool _mine, bool _flag, bool _revealed, int _number);

		bool GetMine();

		bool GetFlag();

		bool GetRevealed();

		bool GetVisited();

		int GetNumber();

		int GetPosX();

		int GetPosY();

		int GetAdjacentMines();

		vector<Tile*>& GetAdjacentTiles();

		void SetMine(bool mineSetting);

		void SetFlag(bool flagSetting);

		void SetNumber(int numSetting);

		void SetAdjacentTiles(vector<Tile*>& _adjacentTiles);

		void SetReveal(bool revealSerring);

		void VisitTile();

		void ResetTile();
	};

