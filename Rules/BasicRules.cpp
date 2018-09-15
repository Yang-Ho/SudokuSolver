#include <iostream>

#include "../Board.h"
#include "Rule.h"

using namespace::std;

bool SingleCandidateRule::apply(SudokuBoard& board)
{
    bool state_changed = false;
    for (int row = 0; row != board.getBoardSize(); row++) {
        for (int column = 0; column != board.getBoardSize(); column++) {
            if (board.getCellValue(row, column) == 0) {
                int value = 1;
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
    return true;
}

bool BasicColumnRule::apply(SudokuBoard& board)
{
    return true;
}

bool BasicBlockRule::apply(SudokuBoard& board)
{
    return true;
}
//  [Last modified: 2018 09 15 at 17:11:44 EDT]
