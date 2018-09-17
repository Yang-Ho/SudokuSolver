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
            int val = digit - '0' - 1;
            if (val > 9) {
                val -= 6;
            }
            board.fillCell(i, j, val);
        }
    }

    cout<<"Finished reading in sudoku board\n";
    board.printBoard();

    Solver solver;
    if (board.isValid()) {
        cout<<"Valid board\n";
    } else {
        cout<<"Invalid board\n";
    }
    solver.solve(board);
    board.printBoard();
    if (board.isFilled() && board.isValid()) {
        cout<<"Solved board\n";
    } else {
        cout<<"Unsolved board\n";
    }
}
//  [Last modified: 2018 09 17 at 18:59:04 EDT]
