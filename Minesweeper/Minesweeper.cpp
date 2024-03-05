#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "Tile.h"
#include "Board.h"

using namespace std;

int countDigits(int original) {
    int count = 0;
    while (original > 0) {
        original = original / 10;
        count++;
    }
    return count;
}


void setMineCounter(int mines, int flags, sf::Texture& digitsTexture, Board& board, vector<sf::Sprite>& digitSprites) {
    digitSprites.clear();
    int counter = mines - flags;    
    int numOfDigits = countDigits(counter);
    if (counter > 0) {
        if (numOfDigits == 1) {
            sf::Sprite digit1Sprite(digitsTexture);
            digit1Sprite.setTextureRect(sf::IntRect(0, 0, 21, 32));
            digit1Sprite.setPosition(0, board.grid.size() * 32);
            digitSprites.push_back(digit1Sprite);

            sf::Sprite digit2Sprite(digitsTexture);
            digit2Sprite.setTextureRect(sf::IntRect(0, 0, 21, 32));
            digit2Sprite.setPosition(21, board.grid.size() * 32);
            digitSprites.push_back(digit2Sprite);

            sf::Sprite digit3Sprite(digitsTexture);
            digit3Sprite.setTextureRect(sf::IntRect(counter * 21, 0, 21, 32));
            digit3Sprite.setPosition(42, board.grid.size() * 32);
            digitSprites.push_back(digit3Sprite);
        }
        else if (numOfDigits == 2) {
            sf::Sprite digit1Sprite(digitsTexture);
            digit1Sprite.setTextureRect(sf::IntRect(0, 0, 21, 32));
            digit1Sprite.setPosition(0, board.grid.size() * 32);
            digitSprites.push_back(digit1Sprite);

            int digit2 = counter / 10;
            int digit3 = counter % 10;
            sf::Sprite digit2Sprite(digitsTexture);
            digit2Sprite.setTextureRect(sf::IntRect(digit2 * 21, 0, 21, 32));
            digit2Sprite.setPosition(21, board.grid.size() * 32);
            digitSprites.push_back(digit2Sprite);

            sf::Sprite digit3Sprite(digitsTexture);
            digit3Sprite.setTextureRect(sf::IntRect(digit3 * 21, 0, 21, 32));
            digit3Sprite.setPosition(42, board.grid.size() * 32);
            digitSprites.push_back(digit3Sprite);
        }
        else if (numOfDigits == 3) {
            int digit3 = counter % 10;
            counter = counter / 10;
            int digit2 = counter % 10;
            int digit1 = counter / 10;

            sf::Sprite digit1Sprite(digitsTexture);
            digit1Sprite.setTextureRect(sf::IntRect(digit1 * 21, 0, 21, 32));
            digit1Sprite.setPosition(0, board.grid.size() * 32);
            digitSprites.push_back(digit1Sprite);


            sf::Sprite digit2Sprite(digitsTexture);
            digit2Sprite.setTextureRect(sf::IntRect(digit2 * 21, 0, 21, 32));
            digit2Sprite.setPosition(21, board.grid.size() * 32);
            digitSprites.push_back(digit2Sprite);

            sf::Sprite digit3Sprite(digitsTexture);
            digit3Sprite.setTextureRect(sf::IntRect(digit3 * 21, 0, 21, 32));
            digit3Sprite.setPosition(42, board.grid.size() * 32);
            digitSprites.push_back(digit3Sprite);
        }
    }
    else if (counter == 0) {
        sf::Sprite digit1Sprite(digitsTexture);
        digit1Sprite.setTextureRect(sf::IntRect(0, 0, 21, 32));
        digit1Sprite.setPosition(0, board.grid.size() * 32);
        digitSprites.push_back(digit1Sprite);

        sf::Sprite digit2Sprite(digitsTexture);
        digit1Sprite.setTextureRect(sf::IntRect(0, 0, 21, 32));
        digit1Sprite.setPosition(21, board.grid.size() * 32);
        digitSprites.push_back(digit1Sprite);

        sf::Sprite digit3Sprite(digitsTexture);
        digit1Sprite.setTextureRect(sf::IntRect(0, 0, 21, 32));
        digit1Sprite.setPosition(42, board.grid.size() * 32);
        digitSprites.push_back(digit1Sprite);
    }
    else if (counter < 0) {
        counter = abs(counter);
        numOfDigits = countDigits(counter);
        if (numOfDigits == 1) {
            sf::Sprite signSprite(digitsTexture);
            signSprite.setTextureRect(sf::IntRect(210, 0, 21, 32));
            signSprite.setPosition(0, board.grid.size() * 32);
            digitSprites.push_back(signSprite);

            sf::Sprite digit1Sprite(digitsTexture);
            digit1Sprite.setTextureRect(sf::IntRect(0, 0, 21, 32));
            digit1Sprite.setPosition(21, board.grid.size() * 32);
            digitSprites.push_back(digit1Sprite);

            sf::Sprite digit2Sprite(digitsTexture);
            digit2Sprite.setTextureRect(sf::IntRect(0, 0, 21, 32));
            digit2Sprite.setPosition(42, board.grid.size() * 32);
            digitSprites.push_back(digit2Sprite);

            sf::Sprite digit3Sprite(digitsTexture);
            digit3Sprite.setTextureRect(sf::IntRect(counter * 21, 0, 21, 32));
            digit3Sprite.setPosition(63, board.grid.size() * 32);
            digitSprites.push_back(digit3Sprite);
        }
        else if (numOfDigits == 2) {
            sf::Sprite signSprite(digitsTexture);
            signSprite.setTextureRect(sf::IntRect(210, 0, 21, 32));
            signSprite.setPosition(0, board.grid.size() * 32);
            digitSprites.push_back(signSprite);

            sf::Sprite digit1Sprite(digitsTexture);
            digit1Sprite.setTextureRect(sf::IntRect(0, 0, 21, 32));
            digit1Sprite.setPosition(21, board.grid.size() * 32);
            digitSprites.push_back(digit1Sprite);

            int digit2 = counter / 10;
            int digit3 = counter % 10;
            sf::Sprite digit2Sprite(digitsTexture);
            digit2Sprite.setTextureRect(sf::IntRect(digit2 * 21, 0, 21, 32));
            digit2Sprite.setPosition(42, board.grid.size() * 32);
            digitSprites.push_back(digit2Sprite);

            sf::Sprite digit3Sprite(digitsTexture);
            digit3Sprite.setTextureRect(sf::IntRect(digit3 * 21, 0, 21, 32));
            digit3Sprite.setPosition(63, board.grid.size() * 32);
            digitSprites.push_back(digit3Sprite);
        }
        else if (numOfDigits == 3) {
            int digit3 = counter % 10;
            counter = counter / 10;
            int digit2 = counter % 10;
            int digit1 = counter / 10;

            sf::Sprite signSprite(digitsTexture);
            signSprite.setTextureRect(sf::IntRect(210, 0, 21, 32));
            signSprite.setPosition(0, board.grid.size() * 32);
            digitSprites.push_back(signSprite);

            sf::Sprite digit1Sprite(digitsTexture);
            digit1Sprite.setTextureRect(sf::IntRect(digit1 * 21, 0, 21, 32));
            digit1Sprite.setPosition(21, board.grid.size() * 32);
            digitSprites.push_back(digit1Sprite);


            sf::Sprite digit2Sprite(digitsTexture);
            digit2Sprite.setTextureRect(sf::IntRect(digit2 * 21, 0, 21, 32));
            digit2Sprite.setPosition(42, board.grid.size() * 32);
            digitSprites.push_back(digit2Sprite);

            sf::Sprite digit3Sprite(digitsTexture);
            digit3Sprite.setTextureRect(sf::IntRect(digit3 * 21, 0, 21, 32));
            digit3Sprite.setPosition(63, board.grid.size() * 32);
            digitSprites.push_back(digit3Sprite);
        }
    }
}
void SetAdjacentTilesMain(Board& board) {
    for (int i = 0; i < board.grid.size(); i++) {
        for (unsigned int j = 0; j < board.grid[i].size(); j++) {
            
            if ((i == 0) && (j == 0)) {
                //test for vector out of bounds
                //cout << "i: " << i << endl;
                //cout << "j: " << j << endl;
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i][j + 1]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i + 1][j + 1]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i + 1][j]);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
            }
            else if ((i == 0) && (j == (board.grid[i].size() - 1))) {
                //test for vector out of bounds
                //cout << "i: " << i << endl;
                //cout << "j: " << j << endl;
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i + 1][j]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i + 1][j - 1]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i][j - 1]);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
            }
            else if ((i == (board.grid.size() - 1)) && (j == (board.grid[i].size() - 1))) {
                //test for vector out of bounds
                //cout << "i: " << i << endl;
                //cout << "j: " << j << endl;
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i - 1][j]);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i][j - 1]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i - 1][j - 1]);
            }
            else if ((i == (board.grid.size() - 1)) && (j == 0)) {
                //test for vector out of bounds
                //cout << "i: " << i << "problem?" << endl;
                //cout << "j: " << j << endl;
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i - 1][j]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i - 1][j + 1]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i][j + 1]);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
            }
            else if (i == 0) {
                //test for vector out of bounds
                //cout << "i: " << i << endl;
                //cout << "j: " << j << endl;
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i][j + 1]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i + 1][j + 1]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i + 1][j]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i + 1][j - 1]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i][j - 1]);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
            }
            else if (j == (board.grid[i].size() - 1)) {
                //test for vector out of bounds
                //cout << "i: " << i << endl;
                //cout << "j: " << j << endl;
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i + 1][j]);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i - 1][j]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i - 1][j - 1]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i][j - 1]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i + 1][j - 1]);
            }
            else if (i == (board.grid.size() - 1)) { //fix nullptrs are in wrong place
                //test for vector out of bounds
                //cout << "i: " << i << endl;
                //cout << "j: " << j << endl;
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i][j + 1]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i - 1][j + 1]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i - 1][j]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i - 1][j - 1]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i][j - 1]);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
            }
            else if (j == 0) {
                //test for vector out of bounds
                //cout << "i: " << i << endl;
                //cout << "j: " << j << endl;
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i - 1][j]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i - 1][j + 1]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i][j + 1]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i + 1][j + 1]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i + 1][j]);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
                board.grid[i][j].adjacentTiles.push_back(nullptr);
            }
            else {
                //test for vector out of bounds
                //cout << "i: " << i << endl;
                //cout << "j: " << j << endl;
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i - 1][j]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i - 1][j + 1]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i][j + 1]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i + 1][j + 1]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i + 1][j]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i + 1][j - 1]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i][j - 1]);
                board.grid[i][j].adjacentTiles.push_back(&board.grid[i - 1][j - 1]);
            }
        }
    }
}

void Reveal(Tile& currTile) {
    int x = currTile.GetPosX();
    int y = currTile.GetPosY();    
    currTile.VisitTile();
    currTile.SetReveal(true);
    currTile.SetNumber(currTile.GetAdjacentMines());
    if (currTile.GetNumber() == 0) {        
        for (unsigned int i = 0; i < currTile.adjacentTiles.size(); i++) {
            if (currTile.adjacentTiles[i] != nullptr) {
                if (currTile.adjacentTiles[i]->GetVisited() == false && currTile.adjacentTiles[i]->GetFlag() == false) {
                    Reveal(*currTile.adjacentTiles[i]);
                }
            }
        }
    }
  
}

void SetBoard(Board& board, vector<sf::Sprite>& tileHiddenSprites, vector<sf::Sprite>& tileRevealedSprites, vector<sf::Sprite>& mineSprites, vector<sf::Sprite>& numberSprites, vector<sf::Sprite>& flagSprites, vector<sf::Sprite>& buttonSprites, vector<sf::Texture>& numberTextures, sf::Texture& tileHiddenTexture, sf::Texture& tileRevealedTexture, sf::Texture& mineTexture, sf::Texture& flagTexture, sf::Texture& debugTexture, sf::Texture& happyFaceTexture, sf::Texture& winFaceTexture, sf::Texture& loseFaceTexture, sf::Texture& test_1Texture, sf::Texture& test_2Texture, sf::Texture test_3Texture) {
    tileHiddenSprites.clear();
    //flagSprites.clear();
    tileRevealedSprites.clear();
    numberSprites.clear();
    //mineSprites.clear();
    buttonSprites.clear();

    bool hiddenFound = false;
    bool mineRevealed = false;
    for (unsigned int i = 0; i < board.grid.size(); i++) {
        for (unsigned int j = 0; j < board.grid[i].size(); j++) {
            if (board.grid[i][j].GetMine() == true && board.grid[i][j].GetRevealed() == true) {
                mineRevealed = true;
            }
            else if (board.grid[i][j].GetMine() == false && board.grid[i][j].GetRevealed() == false) {
                hiddenFound = true;
            }
        }
    }
   

    
    for (unsigned int i = 0; i < board.grid.size(); i++) {
        for (unsigned int j = 0; j < board.grid[i].size(); j++) {
            Tile currTile = board.grid[i][j];
            if (currTile.GetRevealed() == true) {
                sf::Sprite tileRevealed(tileRevealedTexture);
                tileRevealed.setPosition(currTile.GetPosX() * 32, currTile.GetPosY() * 32);
                tileRevealedSprites.push_back(tileRevealed);
                if (currTile.GetMine() == true) {
                    sf::Sprite mineSprite(mineTexture);
                    mineSprite.setPosition(currTile.GetPosX() * 32, currTile.GetPosY() * 32);
                    mineSprites.push_back(mineSprite);
                }
                else if (currTile.GetNumber() == 1) {
                    sf::Sprite num1(numberTextures[0]);
                    num1.setPosition(currTile.GetPosX() * 32, currTile.GetPosY() * 32);
                    numberSprites.push_back(num1);
                }
                else if (currTile.GetNumber() == 2) {
                    sf::Sprite num2(numberTextures[1]);
                    num2.setPosition(currTile.GetPosX() * 32, currTile.GetPosY() * 32);
                    numberSprites.push_back(num2);
                }
                else if (currTile.GetNumber() == 3) {
                    sf::Sprite num3(numberTextures[2]);
                    num3.setPosition(currTile.GetPosX() * 32, currTile.GetPosY() * 32);
                    numberSprites.push_back(num3);
                }
                else if (currTile.GetNumber() == 4) {
                    sf::Sprite num4(numberTextures[3]);
                    num4.setPosition(currTile.GetPosX() * 32, currTile.GetPosY() * 32);
                    numberSprites.push_back(num4);
                }
                else if (currTile.GetNumber() == 5) {
                    sf::Sprite num5(numberTextures[4]);
                    num5.setPosition(currTile.GetPosX() * 32, currTile.GetPosY() * 32);
                    numberSprites.push_back(num5);
                }
                else if (currTile.GetNumber() == 6) {
                    sf::Sprite num5(numberTextures[5]);
                    num5.setPosition(currTile.GetPosX() * 32, currTile.GetPosY() * 32);
                    numberSprites.push_back(num5);
                }
                else if (currTile.GetNumber() == 7) {
                    sf::Sprite num7(numberTextures[6]);
                    num7.setPosition(currTile.GetPosX() * 32, currTile.GetPosY() * 32);
                    numberSprites.push_back(num7);
                }
                else if (currTile.GetNumber() == 8) {
                    sf::Sprite num8(numberTextures[7]);
                    num8.setPosition(currTile.GetPosX() * 32, currTile.GetPosY() * 32);
                    numberSprites.push_back(num8);
                }
            }
            else {
                sf::Sprite tileHidden(tileHiddenTexture);
                tileHidden.setPosition(currTile.GetPosX() * 32, currTile.GetPosY() * 32);
                tileHiddenSprites.push_back(tileHidden);

                if (currTile.GetFlag() == true) {
                    sf::Sprite flag(flagTexture);
                    flag.setPosition(currTile.GetPosX() * 32, currTile.GetPosY() * 32);
                    flagSprites.push_back(flag);
                }


            }

        }
    }

}

void LoadNewBoard(string filePath, Board& board) {
    ifstream inFile(filePath);
    string tempLine;
    vector<vector<char>> newBoard;    

    if (inFile.is_open()) {
        while (getline(inFile, tempLine)) {
            vector<char> c;
            for (unsigned int i = 0; i < tempLine.length(); i++) {
                c.push_back(tempLine.at(i));
            }
            newBoard.push_back(c);
        }
    }
    for (unsigned int i = 0; i < board.grid.size(); i++) {
        for (unsigned int j = 0; j < board.grid[i].size(); j++) {
            board.grid[i][j].ResetTile();
            if (newBoard[i][j] == '1') {
                board.grid[i][j].SetMine(true);
            }
        }
    }

    
}

void RevealAllMines(Board& board) {    
    for(unsigned int i = 0; i < board.grid.size(); i++){
        for (unsigned int j = 0; j < board.grid[i].size(); j++) {
            if (board.grid[i][j].GetMine() == true && board.grid[i][j].GetRevealed() == false) {
                board.grid[i][j].SetReveal(true);
            }
            else if (board.grid[i][j].GetMine() == true && board.grid[i][j].GetRevealed() == true) {
                board.grid[i][j].SetReveal(false);
            }
        }
    }
}

void ResetBoard(Board& board, int rows, int columns, int mines) {
    
    for (unsigned int i = 0; i < board.grid.size(); i++) {        
        for (unsigned int j = 0; j < board.grid[i].size(); j++) {
            board.grid[i][j].ResetTile();            
        }
        
    }
    int tempMines = 0;
    while (tempMines < mines) {
        int randRow = rand() % rows;
        int randColumn = rand() % columns;
        if (board.grid[randRow][randColumn].GetMine() == false) {
            board.grid[randRow][randColumn].SetMine(true);
            tempMines++;
        }
    }
}

bool CheckForWin(Board& board, int rows, int columns, int mines) {

    int hiddenCount = (rows * columns) - mines;
    for (unsigned int i = 0; i < board.grid.size(); i++) {
        for (unsigned int j = 0; j < board.grid[i].size(); j++) {
            if (board.grid[i][j].GetRevealed() == true && board.grid[i][j].GetMine() == false) {
                hiddenCount--;
            }
            
        }
    }
    if (hiddenCount == 0) {
        return true;
    }
    return false;
}

void ToggleDebug(Board& board, vector<sf::Sprite>& mineSprites, sf::Texture& mineTexture) {
    
    if (mineSprites.size() == 0) {
        for (unsigned int i = 0; i < board.grid.size(); i++) {
            for (unsigned int j = 0; j < board.grid[i].size(); j++) {
                if (board.grid[i][j].GetMine() == true) {
                    sf::Sprite mineSprite(mineTexture);
                    mineSprite.setPosition(board.grid[i][j].GetPosX() * 32, board.grid[i][j].GetPosY() * 32);
                    mineSprites.push_back(mineSprite);
                }
            }
        }
    }
    else if (mineSprites.size() > 0) {
        mineSprites.clear();
    }
}

int main()
{
    srand(time(0)); // start the random number generator based on the current system time

    bool lose = false;
    bool win = false;
    bool debugMode = false;

    //read in borad data and create it
    ifstream inFile("boards/config.cfg");
    int columns;
    int rows;
    int mines;
    inFile >> columns;
    inFile >> rows;
    inFile >> mines;

   

    
    

    Board board = Board(rows, columns);
    int height = (rows * 32) + 88;
    int width = (columns * 32);

    SetAdjacentTilesMain(board);

    //place mines in the board randomly
    int tempMines = 0;
    while(tempMines < mines) {
        int randRow = rand() % rows;
        int randColumn = rand() % columns;
        if (board.grid[randRow][randColumn].GetMine() == false) {
            board.grid[randRow][randColumn].SetMine(true);
            tempMines++;
        }
    }

    //create window for the game
    sf::RenderWindow window(sf::VideoMode(width, height), "Minesweeper");
    

    //create all texture to be used throughout the game
    sf::Texture tileHiddenTexture;
    sf::Texture tileRevealedTexture;
    sf::Texture flagTexture;
    sf::Texture mineTexture;
    sf::Texture digitsTexture;
    sf::Texture number_1Texture;
    sf::Texture number_2Texture;
    sf::Texture number_3Texture;
    sf::Texture number_4Texture;
    sf::Texture number_5Texture;
    sf::Texture number_6Texture;
    sf::Texture number_7Texture;
    sf::Texture number_8Texture;
    sf::Texture debugTexture;
    sf::Texture happyFaceTexture;
    sf::Texture winFaceTexture;
    sf::Texture loseFaceTexture;
    sf::Texture test_1Texture;
    sf::Texture test_2Texture;
    sf::Texture test_3Texture;



    
    tileHiddenTexture.loadFromFile("images/tile_hidden.png");
    tileRevealedTexture.loadFromFile("images/tile_revealed.png");
    flagTexture.loadFromFile("images/flag.png");
    mineTexture.loadFromFile("images/mine.png");
    digitsTexture.loadFromFile("images/digits.png");
    number_1Texture.loadFromFile("images/number_1.png");
    number_2Texture.loadFromFile("images/number_2.png");
    number_3Texture.loadFromFile("images/number_3.png");
    number_4Texture.loadFromFile("images/number_4.png");
    number_5Texture.loadFromFile("images/number_5.png");
    number_6Texture.loadFromFile("images/number_6.png");
    number_7Texture.loadFromFile("images/number_7.png");
    number_8Texture.loadFromFile("images/number_8.png");
    debugTexture.loadFromFile("images/debug.png");
    happyFaceTexture.loadFromFile("images/face_happy.png");
    winFaceTexture.loadFromFile("images/face_win.png");
    loseFaceTexture.loadFromFile("images/face_lose.png");
    test_1Texture.loadFromFile("images/test_1.png");
    test_2Texture.loadFromFile("images/test_2.png");
    test_3Texture.loadFromFile("images/test_3.png");


    vector<sf::Texture> numberTextures;
    numberTextures.push_back(number_1Texture);
    numberTextures.push_back(number_2Texture);
    numberTextures.push_back(number_3Texture);
    numberTextures.push_back(number_4Texture);
    numberTextures.push_back(number_5Texture);
    numberTextures.push_back(number_6Texture);
    numberTextures.push_back(number_7Texture);
    numberTextures.push_back(number_8Texture);


    vector<sf::Sprite> tileHiddenSprites;
    vector<sf::Sprite> tileRevealedSprites;
    vector<sf::Sprite> flagSprites;
    vector<sf::Sprite> mineSprites;
    vector<sf::Sprite> digitSprites;
    vector<sf::Sprite> numberSprites;
    vector<sf::Sprite> buttonSprites;

    
    



    
    //set initial positions for the tiles
    /*
    for (unsigned int i = 0; i < board.grid.size(); i++) {
        for (unsigned int j = 0; j < board.grid[i].size(); j++) {
            Tile currTile = board.grid[i][j];
            if (currTile.GetRevealed() == true) {
                sf::Sprite tileRevealed(tileRevealedTexture);
                tileRevealed.setPosition(currTile.GetPosX() * 32, currTile.GetPosY() * 32);
                tileSprites.push_back(tileRevealed);
            }
            else {
                sf::Sprite tileHidden(tileHiddenTexture);
                tileHidden.setPosition(currTile.GetPosX() * 32, currTile.GetPosY() * 32);
                tileSprites.push_back(tileHidden);

                if (currTile.GetFlag() == true) {
                    sf::Sprite flag(flagTexture);
                    flag.setPosition(currTile.GetPosX() * 32, currTile.GetPosY() * 32);
                    flagSprites.push_back(flag);
                }

             
            }
           
        }
    }
    */
    

    SetBoard(board, tileHiddenSprites, tileRevealedSprites, mineSprites, numberSprites, flagSprites, buttonSprites, numberTextures, tileHiddenTexture, tileRevealedTexture, mineTexture, flagTexture, debugTexture, happyFaceTexture, winFaceTexture, loseFaceTexture, test_1Texture, test_2Texture, test_3Texture);

    //set buttons for the bottom of the board
    sf::Sprite debugSprite(debugTexture);
    debugSprite.setPosition(board.grid[0].size() * 16 + (32*3), board.grid.size() * 32);

    sf::Sprite test_1Sprite(test_1Texture);
    test_1Sprite.setPosition(board.grid[0].size() * 16 + (32 * 3) + 64, board.grid.size() * 32);
    
    sf::Sprite test_2Sprite(test_2Texture);
    test_2Sprite.setPosition(board.grid[0].size() * 16 + (32 * 3) + (64 * 2), board.grid.size() * 32);

    sf::Sprite test_3Sprite(test_3Texture);
    test_3Sprite.setPosition(board.grid[0].size() * 16 + (32 * 3) + (64 * 3), board.grid.size() * 32);

    sf::Sprite happyFaceSprite(happyFaceTexture);
    happyFaceSprite.setPosition(board.grid[0].size() * 16 - 32, board.grid.size() * 32);
    
    sf::Sprite loseFaceSprite(loseFaceTexture);
    loseFaceSprite.setPosition(board.grid[0].size() * 16 - 32, board.grid.size() * 32);
   
    sf::Sprite winFaceSprite(winFaceTexture);
    winFaceSprite.setPosition(board.grid[0].size() * 16 - 32, board.grid.size() * 32);   
    


    //load a new board to test
    //LoadNewBoard("boards/recursion_test.brd", board);
    //SetBoard(board, tileHiddenSprites, tileRevealedSprites, mineSprites, numberSprites, flagSprites, numberTextures, tileHiddenTexture, tileRevealedTexture, mineTexture, flagTexture);
    //SetBoard(board, tileHiddenSprites, tileRevealedSprites, mineSprites, numberSprites, flagSprites, buttonSprites, numberTextures, tileHiddenTexture, tileRevealedTexture, mineTexture, flagTexture, debugTexture, happyFaceTexture, winFaceTexture, loseFaceTexture, test_1Texture, test_2Texture, test_3Texture);

    
    while (window.isOpen()) {
        sf::Event event;
          //event loop
          while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                //it right click place flag in hidden tile was clicked
                if (event.mouseButton.button == sf::Mouse::Right && win == false && lose == false) {
                    auto mousePosition = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePosFloat(mousePosition.x, mousePosition.y);
                    for (unsigned int i = 0; i < tileHiddenSprites.size(); i++) {
                        sf::FloatRect tileRect = tileHiddenSprites[i].getGlobalBounds();
                        if (tileRect.contains(mousePosFloat)) {
                            int spriteRow = tileHiddenSprites[i].getPosition().y / 32;
                            int spriteColumn = tileHiddenSprites[i].getPosition().x / 32;
                            Tile currTile = board.GetTileFromBoard(spriteRow, spriteColumn);
                            

                            if ((board.GetTileFromBoard(spriteRow, spriteColumn).GetRevealed() == false) && (board.GetTileFromBoard(spriteRow, spriteColumn).GetFlag() == false)) {                                
                                board.GetTileFromBoard(spriteRow, spriteColumn).SetFlag(true);
                                flagSprites.clear();
                                SetBoard(board, tileHiddenSprites, tileRevealedSprites, mineSprites, numberSprites, flagSprites, buttonSprites, numberTextures, tileHiddenTexture, tileRevealedTexture, mineTexture, flagTexture, debugTexture, happyFaceTexture, winFaceTexture, loseFaceTexture, test_1Texture, test_2Texture, test_3Texture);

                            }
                            else if ((board.GetTileFromBoard(spriteRow, spriteColumn).GetRevealed() == false) && (board.GetTileFromBoard(spriteRow, spriteColumn).GetFlag() == true)) {
                                board.GetTileFromBoard(spriteRow, spriteColumn).SetFlag(false);
                                flagSprites.clear();
                                SetBoard(board, tileHiddenSprites, tileRevealedSprites, mineSprites, numberSprites, flagSprites, buttonSprites, numberTextures, tileHiddenTexture, tileRevealedTexture, mineTexture, flagTexture, debugTexture, happyFaceTexture, winFaceTexture, loseFaceTexture, test_1Texture, test_2Texture, test_3Texture);
                            }
                        }
                    }
                }
                //if left click act appropriatly
                if (event.mouseButton.button == sf::Mouse::Left) {
                    auto mousePosition = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePosFloat(mousePosition.x, mousePosition.y);

                    //check for button click
                    sf::FloatRect faceRect = happyFaceSprite.getGlobalBounds();
                    if (faceRect.contains(mousePosFloat)) {
                        mineSprites.clear();
                        flagSprites.clear();
                        ResetBoard(board, rows, columns, mines);
                        /*
                        debugSprite.setPosition(board.grid[0].size() * 16 + (32 * 3), board.grid.size() * 32);
                        test_1Sprite.setPosition(board.grid[0].size() * 16 + (32 * 3) + 64, board.grid.size() * 32);
                        test_2Sprite.setPosition(board.grid[0].size() * 16 + (32 * 3) + (64 * 2), board.grid.size() * 32);
                        test_3Sprite.setPosition(board.grid[0].size() * 16 + (32 * 3) + (64 * 3), board.grid.size() * 32);
                        happyFaceSprite.setPosition(board.grid[0].size() * 16 - 32, board.grid.size() * 32);
                        winFaceSprite.setPosition(board.grid[0].size() * 16 - 32, board.grid.size() * 32);
                        loseFaceSprite.setPosition(board.grid[0].size() * 16 - 32, board.grid.size() * 32);
                        */
                        win = false;
                        lose = false;

                        SetBoard(board, tileHiddenSprites, tileRevealedSprites, mineSprites, numberSprites, flagSprites, buttonSprites, numberTextures, tileHiddenTexture, tileRevealedTexture, mineTexture, flagTexture, debugTexture, happyFaceTexture, winFaceTexture, loseFaceTexture, test_1Texture, test_2Texture, test_3Texture);

                    }
                    sf::FloatRect test_1Rect = test_1Sprite.getGlobalBounds();
                    if (test_1Rect.contains(mousePosFloat)) {
                        mineSprites.clear();
                        flagSprites.clear();
                        LoadNewBoard("boards/testboard1.brd", board);
                        win = false;
                        lose = false;
                        /*
                        debugSprite.setPosition(board.grid[0].size() * 16 + (32 * 3), board.grid.size() * 32);
                        test_1Sprite.setPosition(board.grid[0].size() * 16 + (32 * 3) + 64, board.grid.size() * 32);
                        test_2Sprite.setPosition(board.grid[0].size() * 16 + (32 * 3) + (64 * 2), board.grid.size() * 32);
                        test_3Sprite.setPosition(board.grid[0].size() * 16 + (32 * 3) + (64 * 3), board.grid.size() * 32);
                        happyFaceSprite.setPosition(board.grid[0].size() * 16 - 32, board.grid.size() * 32);
                        winFaceSprite.setPosition(board.grid[0].size() * 16 - 32, board.grid.size() * 32);
                        loseFaceSprite.setPosition(board.grid[0].size() * 16 - 32, board.grid.size() * 32);
                        */

                        SetBoard(board, tileHiddenSprites, tileRevealedSprites, mineSprites, numberSprites, flagSprites, buttonSprites, numberTextures, tileHiddenTexture, tileRevealedTexture, mineTexture, flagTexture, debugTexture, happyFaceTexture, winFaceTexture, loseFaceTexture, test_1Texture, test_2Texture, test_3Texture);
                    }

                    sf::FloatRect test_2Rect = test_2Sprite.getGlobalBounds();
                    if (test_2Rect.contains(mousePosFloat)) {
                        mineSprites.clear();
                        flagSprites.clear();
                        LoadNewBoard("boards/testboard2.brd", board);
                        win = false;
                        lose = false;
                        /*
                        debugSprite.setPosition(board.grid[0].size() * 16 + (32 * 3), board.grid.size() * 32);
                        test_1Sprite.setPosition(board.grid[0].size() * 16 + (32 * 3) + 64, board.grid.size() * 32);
                        test_2Sprite.setPosition(board.grid[0].size() * 16 + (32 * 3) + (64 * 2), board.grid.size() * 32);
                        test_3Sprite.setPosition(board.grid[0].size() * 16 + (32 * 3) + (64 * 3), board.grid.size() * 32);
                        happyFaceSprite.setPosition(board.grid[0].size() * 16 - 32, board.grid.size() * 32);
                        winFaceSprite.setPosition(board.grid[0].size() * 16 - 32, board.grid.size() * 32);
                        loseFaceSprite.setPosition(board.grid[0].size() * 16 - 32, board.grid.size() * 32);
                        */
                        SetBoard(board, tileHiddenSprites, tileRevealedSprites, mineSprites, numberSprites, flagSprites, buttonSprites, numberTextures, tileHiddenTexture, tileRevealedTexture, mineTexture, flagTexture, debugTexture, happyFaceTexture, winFaceTexture, loseFaceTexture, test_1Texture, test_2Texture, test_3Texture);
                    }

                    sf::FloatRect test_3Rect = test_3Sprite.getGlobalBounds();
                    if (test_3Rect.contains(mousePosFloat)) {
                        mineSprites.clear();
                        flagSprites.clear();
                        LoadNewBoard("boards/testboard3.brd", board);
                        win = false;
                        lose = false;
                        /*
                        debugSprite.setPosition(board.grid[0].size() * 16 + (32 * 3), board.grid.size() * 32);
                        test_1Sprite.setPosition(board.grid[0].size() * 16 + (32 * 3) + 64, board.grid.size() * 32);
                        test_2Sprite.setPosition(board.grid[0].size() * 16 + (32 * 3) + (64 * 2), board.grid.size() * 32);
                        test_3Sprite.setPosition(board.grid[0].size() * 16 + (32 * 3) + (64 * 3), board.grid.size() * 32);
                        happyFaceSprite.setPosition(board.grid[0].size() * 16 - 32, board.grid.size() * 32);
                        winFaceSprite.setPosition(board.grid[0].size() * 16 - 32, board.grid.size() * 32);
                        loseFaceSprite.setPosition(board.grid[0].size() * 16 - 32, board.grid.size() * 32);
                        */
                        SetBoard(board, tileHiddenSprites, tileRevealedSprites, mineSprites, numberSprites, flagSprites, buttonSprites, numberTextures, tileHiddenTexture, tileRevealedTexture, mineTexture, flagTexture, debugTexture, happyFaceTexture, winFaceTexture, loseFaceTexture, test_1Texture, test_2Texture, test_3Texture);
                    }
                    
                    else if(win == false && lose == false){
                        
                    
                    sf::FloatRect debugRect = debugSprite.getGlobalBounds();
                    if (debugRect.contains(mousePosFloat)) {
                        //RevealAllMines(board);
                        ToggleDebug(board, mineSprites, mineTexture);
                        flagSprites.clear();
                        SetBoard(board, tileHiddenSprites, tileRevealedSprites, mineSprites, numberSprites, flagSprites, buttonSprites, numberTextures, tileHiddenTexture, tileRevealedTexture, mineTexture, flagTexture, debugTexture, happyFaceTexture, winFaceTexture, loseFaceTexture, test_1Texture, test_2Texture, test_3Texture);
                    }
                    /*

                    sf::FloatRect test_1Rect = test_1Sprite.getGlobalBounds();
                    if (test_1Rect.contains(mousePosFloat)) {
                        mineSprites.clear();
                        flagSprites.clear();
                        LoadNewBoard("boards/testboard1.brd", board);
                       
                       
                        SetBoard(board, tileHiddenSprites, tileRevealedSprites, mineSprites, numberSprites, flagSprites, buttonSprites, numberTextures, tileHiddenTexture, tileRevealedTexture, mineTexture, flagTexture, debugTexture, happyFaceTexture, winFaceTexture, loseFaceTexture, test_1Texture, test_2Texture, test_3Texture);
                    }

                    sf::FloatRect test_2Rect = test_2Sprite.getGlobalBounds();
                    if (test_2Rect.contains(mousePosFloat)) {
                        mineSprites.clear();
                        flagSprites.clear();
                        LoadNewBoard("boards/testboard2.brd", board);
                        
                        SetBoard(board, tileHiddenSprites, tileRevealedSprites, mineSprites, numberSprites, flagSprites, buttonSprites, numberTextures, tileHiddenTexture, tileRevealedTexture, mineTexture, flagTexture, debugTexture, happyFaceTexture, winFaceTexture, loseFaceTexture, test_1Texture, test_2Texture, test_3Texture);
                    }

                    sf::FloatRect test_3Rect = test_3Sprite.getGlobalBounds();
                    if (test_3Rect.contains(mousePosFloat)) {
                        mineSprites.clear();
                        flagSprites.clear();
                        LoadNewBoard("boards/testboard3.brd", board);
                        
                        SetBoard(board, tileHiddenSprites, tileRevealedSprites, mineSprites, numberSprites, flagSprites, buttonSprites, numberTextures, tileHiddenTexture, tileRevealedTexture, mineTexture, flagTexture, debugTexture, happyFaceTexture, winFaceTexture, loseFaceTexture, test_1Texture, test_2Texture, test_3Texture);
                    }
                    */
                    
                    for (unsigned int i = 0; i < tileHiddenSprites.size(); i++) {
                        sf::FloatRect tileRect = tileHiddenSprites[i].getGlobalBounds();
                        if (tileRect.contains(mousePosFloat)) {
                            int spriteRow = tileHiddenSprites[i].getPosition().y / 32;
                            int spriteColumn = tileHiddenSprites[i].getPosition().x / 32;
                            Tile currTile = board.GetTileFromBoard(spriteRow, spriteColumn);

                            //check if mine was clicked on and behave accordingly
                            if (board.GetTileFromBoard(spriteRow, spriteColumn).GetMine() == true) {
                                lose = true;
                                RevealAllMines(board);
                                board.GetTileFromBoard(spriteRow, spriteColumn).SetReveal(true);
                                SetBoard(board, tileHiddenSprites, tileRevealedSprites, mineSprites, numberSprites, flagSprites, buttonSprites, numberTextures, tileHiddenTexture, tileRevealedTexture, mineTexture, flagTexture, debugTexture, happyFaceTexture, winFaceTexture, loseFaceTexture, test_1Texture, test_2Texture, test_3Texture);
                            }
                            else if (board.GetTileFromBoard(spriteRow, spriteColumn).GetMine() == false && board.GetTileFromBoard(spriteRow, spriteColumn).GetFlag() == false) {
                                Reveal(board.GetTileFromBoard(spriteRow, spriteColumn));
                                SetBoard(board, tileHiddenSprites, tileRevealedSprites, mineSprites, numberSprites, flagSprites, buttonSprites, numberTextures, tileHiddenTexture, tileRevealedTexture, mineTexture, flagTexture, debugTexture, happyFaceTexture, winFaceTexture, loseFaceTexture, test_1Texture, test_2Texture, test_3Texture);
                                
                                win = CheckForWin(board, rows, columns, board.GetNumMines());



                            }
                        }
                        }
                    }
                }
            }
        }
          window.clear();

         for (unsigned int i = 0; i < tileHiddenSprites.size(); i++) {
             window.draw(tileHiddenSprites[i]);
         }
         for (unsigned int i = 0; i < tileRevealedSprites.size(); i++) {
             window.draw(tileRevealedSprites[i]);
         }
         for (unsigned int i = 0; i < numberSprites.size(); i++) {
             window.draw(numberSprites[i]);
         }

         if (lose == true) {
             window.draw(loseFaceSprite);
         }
         else if (win == true) {
             window.draw(winFaceSprite);
             flagSprites.clear();
             for (unsigned int i = 0; i < board.grid.size(); i++) {
                 for (unsigned int j = 0; j < board.grid[i].size(); j++) {
                     if (board.grid[i][j].GetMine() == true) {
                         sf::Sprite flagSprite(flagTexture);
                         flagSprite.setPosition(board.grid[i][j].GetPosX() * 32, board.grid[i][j].GetPosY() * 32);
                         flagSprites.push_back(flagSprite);
                     }
                 }
             }
         }
         else {
             window.draw(happyFaceSprite);
         }

         for (unsigned int i = 0; i < flagSprites.size(); i++) {
              window.draw(flagSprites[i]);
         }
        

         int currentMineCount = 0;
         for (unsigned int i = 0; i < board.grid.size(); i++) {
             for (unsigned int j = 0; j < board.grid[i].size(); j++) {
                 if (board.grid[i][j].GetMine() == true) {
                     currentMineCount++;
                 }
             }
         }
         
         setMineCounter(currentMineCount, flagSprites.size(), digitsTexture, board, digitSprites);
         for (unsigned int i = 0; i < digitSprites.size(); i++) {
             window.draw(digitSprites[i]);
         }

         for (unsigned int i = 0; i < mineSprites.size(); i++) {
             window.draw(mineSprites[i]);
         }

         if (lose == true) {             
             window.draw(loseFaceSprite);
         }
         /*
         else if (win == true) {            
             window.draw(winFaceSprite);
             flagSprites.clear();
             for (unsigned int i = 0; i < board.grid.size(); i++) {
                 for (unsigned int j = 0; j < board.grid[i].size(); j++) {
                     if (board.grid[i][j].GetFlag() == true) {
                         sf::Sprite flagSprite(flagTexture);
                         flagSprite.setPosition(board.grid[i][j].GetPosX() * 32, board.grid[i][j].GetPosY() * 32);
                         flagSprites.push_back(flagSprite);
                     }
                 }
             }
         }
         else {             
             window.draw(happyFaceSprite);
         }
         */
         
         window.draw(debugSprite);
         window.draw(test_1Sprite);
         window.draw(test_2Sprite);
         window.draw(test_3Sprite);

         window.display();

         

          
          
        
    }
    
}