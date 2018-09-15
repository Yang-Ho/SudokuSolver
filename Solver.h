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
    protected:
        SudokuBoard* global_root_board;
    public:
        Solver();
        Solver(vector<Rule*> r);
        ~Solver();

        void solve(SudokuBoard& root);
        void recursiveSolve(SudokuBoard& board); 

        bool processSudokuBoard(SudokuBoard& board);

        bool isValidBoard(SudokuBoard& board);
};

#endif /* SOLVER_H */

//  [Last modified: 2018 09 15 at 13:50:32 EDT]
