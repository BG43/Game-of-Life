// Game_of_Life.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Board.h"
#include "guiboard.h"

int main()
{
    std::cout << "Conway's Game of Life\n";
    Board board; //creating a board object of the class Board

    // GuiBoard bd(20,20, 
    //     [&](int x, int y) { return board.getCell(x,y); },
    //     [&](int x, int y, bool val) { board.setCell(x,y,val);});
    // bd.setup();

    board.setCell(0,0,true);

    // for these tests, we will run a simulaton 100 times
    for (int g = 0; g < 100; ++g) {
        board.print();
        std::cin.get();
        board = board.next();
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
