#include <iostream>

#include "../Board.h"
#include "Rule.h"

using namespace::std;

bool SingleCandidateRule::apply(SudokuBoard& board)
{
    bool state_changed = false;
    for (int row = 0; row != board.getBoardSize(); row++) {
        for (int column = 0; column != board.getBoardSize(); column++) {
            if (board.getCellValue(row, column) < 0) {
                int value = 0;
                int candidate = 0;
                int count = 0;
                for (bool mark : board.getCellMarks(row, column)) {
                    if (mark) {
                        candidate = value;
                        count += 1;
                    }
                    value += 1;
                }
                if (count == 1) {
                    board.fillCell(row, column, candidate);
                    state_changed = true;
                }
            }
        }
    }
    return state_changed;
}

bool BasicRowRule::apply(SudokuBoard& board)
{
    bool state_changed = false;
    int candidate = 0;
    for (int row = 0; row != board.getBoardSize(); row++) {
        vector<int> counts(board.getBoardSize(), 0);
        for (int column = 0; column != board.getBoardSize(); column++) {
            if (board.getCellValue(row, column) < 0) {
                candidate = 0;
                for (bool mark : board.getCellMarks(row, column)) {
                    counts[candidate] += 1;
                    candidate += 1;
                }
            }
        }
        candidate = 0;
        for (int count : counts) {
            if (count == 1) {
                for (int column = 0; column != board.getBoardSize(); column++) {
                    if (board.getCellValue(row, column) < 0) {
                        if (board.getCellMarks(row, column)[candidate]) {
                            board.fillCell(row, column, candidate);
                        }
                    }
                }
                break;
            }
            candidate += 1;
        }
    }
    return state_changed;
}

bool BasicColumnRule::apply(SudokuBoard& board)
{
    bool state_changed = false;
    int candidate = 0;
    for (int column = 0; column != board.getBoardSize(); column++) {
        vector<int> counts(board.getBoardSize(), 0);
        for (int row = 0; row != board.getBoardSize(); row++) {
            if (board.getCellValue(row, column) < 0) {
                candidate = 0;
                for (bool mark : board.getCellMarks(row, column)) {
                    counts[candidate] += 1;
                    candidate += 1;
                }
            }
        }
        candidate = 0;
        for (int count : counts) {
            if (count == 1) {
                for (int row = 0; row != board.getBoardSize(); row++) {
                    if (board.getCellValue(row, column) < 0) {
                        if (board.getCellMarks(row, column)[candidate]) {
                            board.fillCell(row, column, candidate);
                        }
                    }
                }
                break;
            }
            candidate += 1;
        }
    }
    return state_changed;
}

bool BasicBlockRule::apply(SudokuBoard& board)
{
    bool state_changed = false;
    int candidate = 0;

    for (int row_start = 0; row_start != board.getBoardSize(); row_start += board.getBlockSize()) {
        for (int column_start = 0; column_start != board.getBoardSize(); column_start += board.getBlockSize()) {
            vector<int> counts(board.getBoardSize(), 0);
            for (int row_offset = 0; row_offset != 3; row_offset++) {
                for (int column_offset = 0; col_offset != 3; col_offset++) {
                    int row = row_start + row_offset;
                    int column = column_start + column_offset;

                    candidate = 0;

                    for (bool mark : board.getCellMarks(row, column)) {
                        counts[candidate] += 1;
                        candidate += 1;
                    }
                }
            }
            candidate = 0;
            for (int count : counts) {
                if (count == 1) {
                    for (int row_offset = 0; row_offset != 3; row_offset++) {
                        for (int column_offset = 0; col_offset != 3; col_offset++) {
                            int row = row_start + row_offset;
                            int column = column_start + column_offset;
                            if (board.getCellValue(row, column) < 0) {
                                if (board.getCellMarks(row, column)[candidate]) {
                                    board.fillCell(row, column, candidate);
                                }
                            }
                        }
                    }
                    break;
                }
                candidate += 1;
            }
        }
    }
    return state_changed;
}
//  [Last modified: 2018 09 16 at 23:18:30 EDT]
