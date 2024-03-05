#include "Tile.h"

Tile::Tile() {
	mine = false;
	flag = false;
	revealed = false;
	number = 0;
	posX = 0;
	posY = 0;

}

Tile::Tile(int _posX, int _posY) {
	mine = false;
	flag = false;
	revealed = false;
	number = 0;
	posX = _posX;
	posY = _posY;
		
}

Tile::Tile(bool _mine, bool _flag, bool _revealed, int _number) {
	mine = _mine;
	flag = _flag;
	revealed = _revealed;
	number = _number;
	posX = 0;
	posY = 0;


}

bool Tile::GetMine() {
	return mine;
}

bool Tile::GetFlag() {
	return flag;
}

bool Tile::GetRevealed() {
	return revealed;
}

bool Tile::GetVisited() {
	return visited;
}

int Tile::GetNumber() {
	return number;
}

int Tile::GetPosX() {
	return posX;
}

int Tile::GetPosY() {
	return posY;
}

int Tile::GetAdjacentMines() {
	int mineCounter = 0;
	for (unsigned int i = 0; i < adjacentTiles.size(); i++) {
		if (adjacentTiles[i] != nullptr) {
			if (adjacentTiles[i]->GetMine() == true) {
				mineCounter++;
			}
		}
	}
	return mineCounter;
}


vector<Tile*>& Tile::GetAdjacentTiles() {
	return adjacentTiles;
}

void Tile::SetMine(bool mineSetting) {
	mine = mineSetting;
}

void Tile::SetFlag(bool flagSetting) {
	flag = flagSetting;
}

void Tile::SetNumber(int numSetting) {
	number = numSetting;
}

void Tile::SetAdjacentTiles(vector<Tile*>& _adjacentTiles) {
	adjacentTiles = _adjacentTiles;
}

void Tile::SetReveal(bool revealSetting) {
	revealed = revealSetting;
}

void Tile::VisitTile() {
	visited = true;
}

void Tile::ResetTile() {
	mine = false;
	flag = false;
	revealed = false;
	visited = false;
	number = 0;	
	adjacentMines = 0;
}