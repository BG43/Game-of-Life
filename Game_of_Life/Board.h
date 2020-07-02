#pragma once
#include <iostream>
#include <algorithm>

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
        return board[y % 20][x % 20];
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

                // int neighboursBasic = 
                //     board[i-1][j] ? 1 : 0 +
                //     board[i-1][j+1] ? 1 : 0 +
                //     board[i][j+1] ? 1 : 0 +
                //     board[i+1][j+1] ? 1 : 0 +
                //     board[i-1][j] ? 1 : 0 +
                //     board[i-1][j] ? 1 : 0 +
                //     board[i-1][j] ? 1 : 0 +
                //     board[i-1][j] ? 1 : 0;

        static const int neighbourOffsets[][2] {
            {-1,0}, // N
            {-1,1}, // NE
            {0,1},  // E
            {1,1},  // SE
            {1,0},  // S
            {1,-1}, // SW
            {0,-1}, // W
            {-1,-1} // NW
        };

        
        // three rules
        // => for each of the cells
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                // => count its neighbourgs
                // ? how do we count the neighbours?
                // 8 neighbours: (i,j)
                // north: (i-1,j)
                // north-east: (i-1,j+1)


                auto neighbours = std::count_if(neighbourOffsets,
                    neighbourOffsets + 8,
                    [&](const int offset[2]){ return board[i+offset[0]][j+offset[1]]; });

                // => decide, depending on the count:
                // 2 or 3 => Any live cell with two or three live neighbours survives.
                // 3 => Any dead cell with three live neighbours becomes a live cell.
                // any other => All other live cells die in the next generation. 
                //      Similarly, all other dead cells stay dead.
                
                // result started with all cells dead (all false)
                // for each cell that needs to be alive on the next generation,
                result.board[i][j] = false;
                result.board[i][j] = true;


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

