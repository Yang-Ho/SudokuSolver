#include <iostream>

#include "Board.h"

using namespace::std;

int Cell::getMarkCount()
{
    int count = 0;
    for (bool mark : marks) {
        if (mark) {
            count += 1;
        }
    }
    return count;
}

SudokuBoard::SudokuBoard(): 
    block_size(3),
    board(9, vector<Cell>(9, {0, vector<bool>(9, true)}))
{
}

SudokuBoard::SudokuBoard(int N): 
    block_size(N),
    board(N*N, vector<Cell>(N*N, {0, vector<bool>(N*N, true)}))
{
}

SudokuBoard::~SudokuBoard()
{
}

void SudokuBoard::printBoard()
{
    int row_count = 0;
    int col_count = 0;
    cout<<'\n';
    for (vector<Cell> row : board) {
        cout<<" ";
        for (Cell cell : row) {
            int val = cell.value;
            if (val + 1 > 9) {
                char c = (char)(val + 6 + '0' + 1);
                cout<<c;
            } else {
                cout<<val + 1;
            }
            col_count += 1;
            if (col_count == block_size) {
                col_count = 0;
                cout<<" ";
            }
        }
        row_count += 1;
        if (row_count == block_size) {
            row_count = 0;
            cout<<'\n';
        }
        cout<<'\n';
    }
}

void SudokuBoard::printMarks()
{
    int row_count = 0;
    int col_count = 0;
    for (vector<Cell> row : board) {
        cout<<" ";
        for (Cell cell : row) {
            for (bool mark : cell.marks) {
                if (cell.value < 0) {
                    cout<<mark;
                } else {
                    cout<<'x';
                }
            }
            cout<<"|";
            col_count += 1;
            if (col_count == block_size) {
                col_count = 0;
                cout<<" ";
            }
        }
        row_count += 1;
        if (row_count == block_size) {
            row_count = 0;
            cout<<"\n";
        }
        cout<<endl;
    }
}

void SudokuBoard::printMarks(int row, int col)
{
    int val = getCellValue(row, col);
    for (bool mark : getCellMarks(row, col)) {
        if (val < 0) {
            cout<<mark;
        } else {
            cout<<'x';
        }
    }
    cout<<"\n";
}

void SudokuBoard::fillCell(int row, int col, int val)
{
    board[row][col].value = val;
    if (val > -1) {
        for (int i = 0; i != getBoardSize(); i++) {
            // Update markings for row and column
            markCell(row, i, val, false);
            markCell(i, col, val, false);
        }
        // Update markings for block
        int block_start_row = (getBlockNumber(row, col) / getBlockSize()) * getBlockSize();
        int block_start_col = (getBlockNumber(row, col) % getBlockSize()) * getBlockSize();
        for (int row_offset = 0; row_offset != 3; row_offset++) {
            for (int col_offset = 0; col_offset != 3; col_offset++) {
                markCell(block_start_row + row_offset, block_start_col + col_offset, val, false);
            }
        }
    }
}

void SudokuBoard::markCell(int row, int col, int val, bool mark)
{
    board[row][col].marks[val] = mark;
}

bool SudokuBoard::isValid()
{
    // Check rows 
    for (vector<Cell> row : board) {
        vector<bool> is_present(9, false);
        for (Cell cell : row) {
            if (cell.value > -1) { 
                if (is_present[cell.value]) {
                    return false;
                }
                is_present[cell.value] = true;
            }
        }
    }

    // check columns
    for (int i = 0; i != block_size * block_size; i++) {
        vector<bool> is_present(9, false);
        for (int j = 0; j != block_size * block_size; j++) {
            int val = board[j][i].value;
            if (val > 0) {
                if (is_present[val]) {
                    return false;
                }
                is_present[val] = true;
            }
        }
    }

    // check square
    for (int row = 0; row != block_size; row++) {
        for (int col = 0; col != block_size; col++) {
            vector<bool> is_present(9, false);
            for (int i = 0; i != block_size * block_size; i++) {
                int adjusted_row = i / block_size + row * 3;
                int adjusted_col = i % block_size + col * 3;
                int val = board[adjusted_row][adjusted_col].value;
                if (val > 0) {
                    if (is_present[val]) {
                        return false;
                    }
                    is_present[val] = true;
                }
            }
        }
    }
    return true;
}

bool SudokuBoard::isFilled()
{
    bool board_filled = true;
    for (int row = 0; row != getBoardSize(); row++) {
        for (int column = 0; column != getBoardSize(); column++) {
            if (board[row][column].value < 0) {
                board_filled = false;
                break;
            }
        }
        if (!board_filled) {
            break;
        }
    }
    return board_filled && isValid();
}

void SudokuBoard::setCells(vector<Cell> cells)
{
    int boardSize = getBoardSize();
    for (int row = 0; row != boardSize; row++) {
        for (int column = 0; column != boardSize; column++) {
            board[row][column].value = cells[row * boardSize + column].value;
            board[row][column].marks = cells[row * boardSize + column].marks;
        }
    }
}

//  [Last modified: 2018 09 17 at 18:58:33 EDT]
