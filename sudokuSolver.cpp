#include <iostream>

#include "Board.h"

int main() 
{
    int size;
    cin>>size;

    SudokuBoard board(size);
    
    for (int i = 0; i < size * size; i++) {
        for (int j = 0; j < size * size; j++) {
            char digit;
            cin>>digit;
            int val = digit - '0';
            board.fillSquare(i, j, val);
        }
    }

    board.printBoard();
    if (board.checkCorrectness()) {
        cout<<"Valid board\n";
    } else {
        cout<<"Invalid board\n";
    }
}
//  [Last modified: 2018 09 07 at 15:11:53 EDT]
