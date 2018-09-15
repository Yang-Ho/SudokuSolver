#include <iostream>

#include "Board.h"
#include "Solver.h"

int main() 
{
    int size;
    cin>>size;

    cout<<"Initializing sudoku board\n";
    SudokuBoard board(size);
    
    cout<<"reading in board\n";
    for (int i = 0; i < size * size; i++) {
        for (int j = 0; j < size * size; j++) {
            char digit;
            cin>>digit;
            int val = digit - '0';
            board.fillCell(i, j, val);
        }
    }

    cout<<"Finished reading in sudoku board\n";
    board.printBoard();

    Solver solver;
    if (solver.isValidBoard((board))) {
        cout<<"Valid board\n";
    } else {
        cout<<"Invalid board\n";
    }
    solver.processSudokuBoard(board);
    board.printBoard();
    if (solver.isValidBoard((board))) {
        cout<<"Valid board\n";
    } else {
        cout<<"Invalid board\n";
    }
}
//  [Last modified: 2018 09 15 at 17:19:29 EDT]
