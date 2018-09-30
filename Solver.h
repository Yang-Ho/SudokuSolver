#ifndef SOLVER_H
#define SOLVER_H 
#include <string>
#include <vector>

#include "Board.h"
#include "Rules/Rule.h"

using namespace::std;

class Solver 
{
    private:
        vector<Rule*> rules;
        Rule* naked_candidate_row_rule;
        Rule* naked_candidate_column_rule;
        Rule* naked_candidate_block_rule;
        Rule* naked_candidate_rule;
        int depth = 0;
    protected:
        SudokuBoard* global_root_board;
    public:
        Solver();
        Solver(vector<Rule*> r);
        ~Solver();

        void solve(SudokuBoard& root);
        void recursiveSolve(SudokuBoard& board); 

        void processSudokuBoard(SudokuBoard& board);
};

#endif /* SOLVER_H */

//  [Last modified: 2018 09 30 at 12:11:01 EDT]
