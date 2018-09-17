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
        Rule* basic_row_rule;
        Rule* basic_column_rule;
        Rule* basic_block_rule;
        Rule* single_candidate_rule;
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

//  [Last modified: 2018 09 17 at 18:22:43 EDT]
