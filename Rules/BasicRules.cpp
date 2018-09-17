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
    int row = 0;
    while (row != board.getBoardSize()) {
        vector<int> counts(board.getBoardSize(), 0);
        for (int column = 0; column != board.getBoardSize(); column++) {
            if (board.getCellValue(row, column) < 0) {
                candidate = 0;
                for (bool mark : board.getCellMarks(row, column)) {
                    if (mark) {
                        counts[candidate] += 1;
                    }
                    candidate += 1;
                }
            }
        }
        candidate = 0;
        bool one_count = false;
        for (int count : counts) {
            if (count == 1) {
                for (int column = 0; column != board.getBoardSize(); column++) {
                    if (board.getCellValue(row, column) < 0) {
                        if (board.getCellMarks(row, column)[candidate]) {
                            one_count = true;
                            state_changed = true;
                            board.fillCell(row, column, candidate);
                        }
                    }
                }
            }
            candidate += 1;
        }
        if (one_count) {
            row = 0;
        } else {
            row += 1;
        }
    }
    return state_changed;
}

bool BasicColumnRule::apply(SudokuBoard& board)
{
    bool state_changed = false;
    int candidate = 0;
    int column = 0;
    while (column != board.getBoardSize()) {
        vector<int> counts(board.getBoardSize(), 0);
        for (int row = 0; row != board.getBoardSize(); row++) {
            if (board.getCellValue(row, column) < 0) {
                candidate = 0;
                for (bool mark : board.getCellMarks(row, column)) {
                    if (mark) {
                        counts[candidate] += 1;
                    }
                    candidate += 1;
                }
            }
        }
        candidate = 0;
        bool one_count = false;
        for (int count : counts) {
            if (count == 1) {
                for (int row = 0; row != board.getBoardSize(); row++) {
                    if (board.getCellValue(row, column) < 0) {
                        if (board.getCellMarks(row, column)[candidate]) {
                            one_count = true;
                            state_changed = true;
                            board.fillCell(row, column, candidate);
                        }
                    }
                }
            }
            candidate += 1;
        }
        if (one_count) {
            column = 0;
        } else {
            column += 1;
        }
    }
    return state_changed;
}

bool BasicBlockRule::apply(SudokuBoard& board)
{
    bool state_changed = false;
    int candidate = 0;
    int row_start = 0;
    int column_start = 0;
    while (row_start != board.getBoardSize()) {
        while (column_start != board.getBoardSize()) {
            vector<int> counts(board.getBoardSize(), 0);
            for (int row_offset = 0; row_offset != 3; row_offset++) {
                for (int column_offset = 0; column_offset != 3; column_offset++) {
                    int row = row_start + row_offset;
                    int column = column_start + column_offset;
                    candidate = 0;
                    if (board.getCellValue(row, column) < 0) {
                        for (bool mark : board.getCellMarks(row, column)) {
                            if (mark) {
                                counts[candidate] += 1;
                            }
                            candidate += 1;
                        }
                    }
                }
            }
            candidate = 0;
            bool count_one = false;
            for (int count : counts) {
                if (count == 1) {
                    for (int row_offset = 0; row_offset != 3; row_offset++) {
                        for (int column_offset = 0; column_offset != 3; column_offset++) {
                            int row = row_start + row_offset;
                            int column = column_start + column_offset;
                            if (board.getCellValue(row, column) < 0) {
                                if (board.getCellMarks(row, column)[candidate]) {
                                    board.fillCell(row, column, candidate);
                                    count_one = true;
                                    state_changed = true;
                                }
                            }
                        }
                    }
                }
                candidate += 1;
            }
            if (count_one) {
                column_start = 0;
                row_start = 0;
            } else {
                column_start += 3;
            }
        }
        row_start += 3;
    }
    return state_changed;
}
//  [Last modified: 2018 09 17 at 15:40:14 EDT]
