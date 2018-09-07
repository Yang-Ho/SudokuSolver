#include <iostream>

#include "Board.h"

using namespace::std;

//vector<vector<vector<int>>> candidates; // Used to keep track of candidates of a cell

SudokuBoard::SudokuBoard(): 
    grid_size(3),
    board(9, vector<int>(9, 0)),
    candidates(9, vector<vector<int>>(9, vector<int>(9, -1)))
{
}

SudokuBoard::SudokuBoard(int N): 
    grid_size(N),
    board(N * N, vector<int>(N * N, 0)),
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

void SudokuBoard::fillSquare(int i, int j, int val)
{
    board[i][j] = val;
}

void SudokuBoard::markSquare(int i, int j, vector<int> marks)
{
    for (int mark : marks) {
        if (candidates[i][j][mark] == -1) {
            candidates[i][j][mark] = 1;
        }
    }
}

bool SudokuBoard::checkCorrectness()
{
    // Check rows 
    for (vector<int> row : board) {
        vector<bool> is_present(9, false);
        for (int val : row) {
            if (val > 0) { 
                if (is_present[val - 1]) {
                    return false;
                }
                is_present[val - 1] = true;
            }
        }
    }

    // check columns
    for (int i = 0; i != grid_size * grid_size; i++) {
        vector<bool> is_present(9, false);
        for (int j = 0; j != grid_size * grid_size; j++) {
            int val = board[j][i];
            if (val > 0) {
                if (is_present[val - 1]) {
                    return false;
                }
                is_present[val - 1] = true;
            }
        }
    }

    // check square
    for (int i = 0; i != grid_size; i++) {
        for (int j = 0; j != grid_size; j++) {
            vector<bool> is_present(9, false);
            for (int k = 0; k != grid_size * grid_size; k++) {
                int adjusted_i = k / grid_size + i * 3;
                int adjusted_j = k % grid_size + j * 3;
                int val = board[adjusted_i][adjusted_j];
                if (val > 0) {
                    if (is_present[val - 1]) {
                        return false;
                    }
                    is_present[val - 1] = true;
                }
            }
        }
    }

    return true;
}


//  [Last modified: 2018 09 07 at 15:27:04 EDT]
