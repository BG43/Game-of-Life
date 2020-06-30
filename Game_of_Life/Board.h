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
        auto previous = board[x][y];
        board[x][y] = state; 
        return previous;
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
        

        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 19; j++) {

                if (board[i][j]) {
                    auto t = board[i][j];
                    result.setCell(i, j, false);
                    result.setCell(i + 1, j + 1, t);
                    break;
                }
            }
        }

        // use it to change the result board
        return result;
    }
    void print() {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 19; j++) {
                cout << board[i][j];
            }
            cout << endl;
        }
    }
};

