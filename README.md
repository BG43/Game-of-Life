# Game-of-Life
https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life

## Goals

To make our version of Conway's Game of Life, and in the process, use the concepts learned about
C++ features.

## Tasks

### Current Tasks

* On Board:
    * Add a field, which can hold 20x20 cells
    * Add a method, which will print the current board on screen
* Test it by changing main() to :
    * Create a board instance
    * Show it

### Create a board

We need a SIZExSIZE board that we can represent in memory.

With the board, we will need to be able to:
1. show it on Console
2. test whether a cell (x,y) is alive or not
3. change the status of a cell (x,y)
4. move to the next generation (apply the four rules to every cell on the board)

#### Design Notes

C++ features we will be using:
* Class (Board); the declarations for this class will be on a file: Board.h (a header file).
* We want the board to be dynamic in size.

### Create a driver program

1. drops some groups of living cells on an initially empty board
2. progresses on generations, showing the intermediate results
3. after a number of generations, shows some final statistics

#### Design Notes

Driver program: a main function. It will be using the board.
