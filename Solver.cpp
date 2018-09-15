#include <iostream>

#include "Solver.h"
#include "Board.h"
#include "Rules/Rule.h"

using namespace::std;

Solver::Solver():
    basic_row_rule(new BasicRowRule()),
    basic_column_rule(new BasicColumnRule()),
    basic_block_rule(new BasicBlockRule()),
    single_candidate_rule(new SingleCandidateRule())
{
}

Solver::Solver(vector<Rule*> r):
    rules(r),
    basic_row_rule(new BasicRowRule()),
    basic_column_rule(new BasicColumnRule()),
    basic_block_rule(new BasicBlockRule()),
    single_candidate_rule(new SingleCandidateRule())
{
}

Solver::~Solver()
{
    delete basic_row_rule;
    delete basic_column_rule;
    delete basic_block_rule;
    delete single_candidate_rule;
}

void Solver::solve(SudokuBoard& root)
{
    global_root_board = &root;

    //cout<<isValidBoard(*global_root_board);
}

void Solver::recursiveSolve(SudokuBoard& board)
{
}

bool Solver::processSudokuBoard(SudokuBoard& board)
{
    bool state_changed = true;
    while (state_changed) {
        state_changed = single_candidate_rule->apply(board);
    }
    return true;
}

bool Solver::isValidBoard(SudokuBoard& board)
{
    return board.isValid();
}
//  [Last modified: 2018 09 15 at 17:19:18 EDT]
