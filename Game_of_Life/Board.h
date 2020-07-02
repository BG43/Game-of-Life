#pragma once
#include <iostream>

using namespace std;

class Board {
    bool board[20][20]{ 0 };
public:
    // setCell will change the state (false|true) of a certain cell
    // it will return the previous state of the cell just modified
    bool setCell(int x, int y, bool state) 
    {
        x %= 20;
        y %= 20;
        auto previous = board[x][y];
        board[x][y] = state; 
        return previous;
    }

    bool getCell(int x, int y)
    {
        return board[y][x];
    }


        // 00000     00000
        // 01000     00000
        // 00000  => 00100
        // 00000     00000
        // 00000     00000



    // go through the board and calculate the next generation
    // for our first iteration: just move each cell diagonally
    Board next() 
    {
        Board result;

        // ... take the state of the current board,

        //auto t = board[i][j]; how to read the initial board
        //result.setCell(1, 1, true); how to write into the resulting board
        
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {

                if (board[i][j]) {
                    auto t = board[i][j];
                    result.setCell(i, j, false);
                    result.setCell(i + 1, j + 1, t);
                    break;
                }
            }
        }
        return result;
	// cout<<
	}
    void print() {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                cout << board[i][j];
            }
            cout << endl;
        }
    }
};

