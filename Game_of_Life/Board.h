#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

class Board {
    bool board[21][21]{ 0 };
    int neighbourCount{ 0 };
public:
    // setCell will change the state (false|true) of a certain cell
    // it will return the previous state of the cell just modified
    bool setCell(int x, int y, bool state) 
    {
        x %= 21;
        y %= 21;
        auto previous = board[x][y];
        board[x][y] = state; 
        return previous;
    }

    bool getCell(int x, int y)
    {
        return board[y % 21][x % 21];
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

        static const int neighbourOffsets[8][2] {
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
        for (int i = 1; i < 21; i++) {
            for (int j = 1; j < 21; j++) {
                // => count its neighbourgs
                // given i,j apply neighbourOffsets to them
                // ? how do we count the neighbours?
                // 8 neighbours: (i,j)
                // north: (i-1,j)
                // north-east: (i-1,j+1)

                for (int k = 0; k < 8; k++) {
                    auto temp_i{ 0 };
                    auto temp_j{ 0 };
                    for (int l = 0; l < 2; l++) {
                     
                        if (l == 0)  temp_i = result.board[i][j] + neighbourOffsets[k][l];
                        if (l == 1)  temp_j = result.board[i][j] + neighbourOffsets[k][l];
                        if (0 < l) {
                            if (result.board[i + temp_i][j + temp_j]) {
                                neighbourCount++;
                                result.board[i - temp_i][j - temp_j];
                            }
                        }
                    }
                
                }



                // I do not understand this????? 
                /*auto neighbours = std::count_if(neighbourOffsets,
                    neighbourOffsets + 8,
                    [&](const int offset[2]){ return board[i+offset[0]][j+offset[1]]; });*/

                // => decide, depending on the count:

                // 2 or 3 => Any live cell with two or three live neighbours survives.
                // 3 => Any dead cell with three live neighbours becomes a live cell.
                if ((neighbourCount == 2 || neighbourCount == 3) || ((result.board[i][j] == false && neighbourCount == 3))) {

                    result.board[i][j] = true;
                }

                // any other => All other live cells die in the next generation. 
                //      Similarly, all other dead cells stay dead.
                else {
                    result.board[i][j] = false;
                }
                // result started with all cells dead (all false)
                // for each cell that needs to be alive on the next generation,
                //
                


            }
        }
        return result;
	// cout<<
	}
    void print() {
        for (int i = 1; i < 21; i++) {
            for (int j = 1; j < 21; j++) {
                cout << board[i][j];
            }
            cout << endl;
        }
    }
};

