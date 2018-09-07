#include <iostream>

#include "Board.h"

using namespace::std;

//vector<vector<vector<int>>> candidates; // Used to keep track of candidates of a cell

SudokuBoard::SudokuBoard(): 
    grid_size(3),
    board(9, vector<int>(9, -1)),
    candidates(9, vector<vector<int>>(9, vector<int>(9, -1)))
{
}

SudokuBoard::SudokuBoard(int N): 
    grid_size(N),
    board(N * N, vector<int>(N * N, -1)),
    candidates(N * N, vector<vector<int>>(N * N, vector<int>(N * N, -1)))
{
}

SudokuBoard::~SudokuBoard()
{
}

void SudokuBoard::printBoard()
{
    int row_count = 0;
    int col_count = 0;
    for (vector<int> row : board) {
        cout<<" ";
        for (int val : row) {
            cout<<val;
            col_count += 1;
            if (col_count == grid_size) {
                col_count = 0;
                cout<<" ";
            }
        }
        row_count += 1;
        if (row_count == grid_size) {
            row_count = 0;
            cout<<"\n";
        }
        cout<<endl;
    }
}

//  [Last modified: 2018 09 07 at 13:17:18 EDT]
