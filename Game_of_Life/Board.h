#pragma once
#include <iostream>

using namespace std;

class Board {
    bool board[20][20] = { 0 };
public:
	void print() {
        // we need 2 loops
        // because of the way that we write in English,
        // we need to organise things as follow:
        // we write columns, grouped by rows
        // the inner loop is columns
        // the outer loop is rows
        // the outer loop has the following properties:
        // INITIALIZATION: start on the first row (0)
        // INVARIANT: until we get to the last row (19)
        // INCREMENT: get to the next row (++)
        // what do we do on the outer loop ? 
        // => execute the inner loop
        // => end line
        // the inner loop has the following properties:
        // INITIALIZATION: start on the first column (0)
        // INVARIANT: until we get to the last column (19)
        // INCREMENT: get to the next column (++)
        // what do we do in the inner loop ?
        // => we have a determinate position in the matrix, print the value that is on that position, on the board (0 or 1)

        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 19; j++) {
                cout<<board[i][j];
            }
            cout << endl;
        }

	// cout<<
	}
};

