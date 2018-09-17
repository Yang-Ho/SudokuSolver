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
    depth = 0;

    processSudokuBoard(root);
    if (!root.isFilled()) {
        if (root.isValid()) {
            recursiveSolve(root);
        }
    } else {
        if (root.isValid()) {
            cout<<"Sudoku solved at root\n";
        }
    }
}

void Solver::recursiveSolve(SudokuBoard& board)
{
    depth += 1;
#ifdef DEBUG
    cout<<"Recursive solve depth: "<<depth<<'\n';
#endif
    int boardSize = board.getBoardSize();

    // Store copy of the "original" state and get the ideal branching candidate
    int branch_row, branch_column;
    int max_marks = boardSize;
    vector<Cell> original_cell_state;
    original_cell_state.reserve(boardSize * boardSize);

    for (int row = 0; row != boardSize; row++) {
        for (int column = 0; column != boardSize; column++) {
            original_cell_state.push_back(board.getCell(row, column));
            if (board.getCellValue(row, column) < 0) {
                int cell_count = board.getCellCount(row, column);
                if (cell_count < max_marks) {
                    max_marks = cell_count;
                    branch_row = row;
                    branch_column = column;
                }
            }
        }
    }

    // "Branch"/Recursive step
    vector<bool> branch_marks(board.getCellMarks(branch_row, branch_column));

#ifdef DEBUG
    cout<<"Branching cell: "<<branch_row<<" "<<branch_column<<'\n';
    cout<<"Branching marks: ";
    for (bool mark : branch_marks) {
        cout<<mark;
    }
    cout<<'\n';
#endif

    for (int candidate = 0; candidate != boardSize; candidate++) {
        if (branch_marks[candidate]) {
            // Set cell to a value
            board.fillCell(branch_row, branch_column, candidate);
            processSudokuBoard(board);
#ifdef DEBUG
            cout<<"Before recursive call\n";
            board.printBoard();
#endif
            if (!board.isFilled()) {
                if (board.isValid()) {
                    recursiveSolve(board);
                    depth -= 1;
#ifdef DEBUG
                    cout<<"Leaving depth: "<<depth<<'\n';
#endif
                }
            } else {
                if (board.isValid()) {
                    cout<<"Sudoku solved\n";
                    return;
                }
            }
            if (!board.isFilled() || !board.isValid()) {
                // Restore
                board.setCells(original_cell_state);
            } else {
                return;
            }
        }
    }
}

void Solver::processSudokuBoard(SudokuBoard& board)
{
    bool state_changed = true;
    while (state_changed) {
        if (single_candidate_rule->apply(board)) {
            continue;
        }
        if (basic_row_rule->apply(board)) {
            continue;
        }
        if (basic_column_rule->apply(board)) {
            continue;
        }
        if (basic_block_rule->apply(board)) {
            continue;
        }
        state_changed = false;
    }
}

//  [Last modified: 2018 09 17 at 18:27:34 EDT]
