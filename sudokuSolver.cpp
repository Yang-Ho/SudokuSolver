#include <iostream>

#include "Board.h"

int main() 
{
    int N;
    cin>>N;

    SudokuBoard board(N);
    board.printBoard();
}
//  [Last modified: 2018 09 07 at 12:51:18 EDT]
