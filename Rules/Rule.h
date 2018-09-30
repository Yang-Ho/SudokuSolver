#ifndef RULE_H
#define RULE_H 

#include <string>

using namespace::std;

class Rule
{
    protected:
        string rule_name;
    public:
        Rule(string name) : rule_name(name) {};
        virtual ~Rule() {};

        virtual bool apply(SudokuBoard& board) = 0; // Apply the rule to fill in candidates/squares

        string getName() { return rule_name; };
};

// Basic rules

/**
 * Naked Candidate: A cell only has one possible candidate
 */
class NakedCandidateRule : public Rule
{
    public:
        NakedCandidateRule() : Rule("Naked_Candidate_Rule") {};

        bool apply(SudokuBoard& board);
};

/**
 * Naked Candidate (Row): For a number, there is only one cell in the row where it is a candidate
 */
class NakedCandidateRowRule : public Rule
{
    public:
        NakedCandidateRowRule() : Rule("Naked_Candidate_Row_Rule") {};

        bool apply(SudokuBoard& board);
};

/**
 * Naked Candidate (Column): For a number, there is only one cell in the column where it is a candidate
 */
class NakedCandidateColumnRule : public Rule
{
    public:
        NakedCandidateColumnRule() : Rule("Naked_Candidate_Column_Rule") {};

        bool apply(SudokuBoard& board);
};

/**
 * Naked Candidate (Block): For a number, there is only one cell in the block where it is a candidate
 */
class NakedCandidateBlockRule : public Rule
{
    public:
        NakedCandidateBlockRule() : Rule("Naked_Candidate_Block_Rule") {};

        bool apply(SudokuBoard& board);
};

// Other naked rules (non-trivial/non-basic)

/**
 * Naked Single (Row): 
 *   Given a row, if there is a N such that all row 
 *   markings for N belong to the same block B, 
 *   then all other cells of B cannot have N as a candidate.
 */
class NakedSingleRowRule : public Rule
{
    public:
        NakedSingleRowRule() : Rule("Naked_Pair_Row_Rule") {};

        bool apply(SudokuBoard& board);
};

/**
 * Naked Single (Column): 
 *   Given a column, if there is a N such that all column 
 *   markings for N belong to the same block B, 
 *   then all other cells of B cannot have N as a candidate.
 */
class NakedSingleColumnRule : public Rule
{
    public:
        NakedSingleColumnRule() : Rule("Naked_Pair_Column_Rule") {};

        bool apply(SudokuBoard& board);
};

/**
 * Naked Single (Block): 
 *   Given a block, if there is a N such that all block 
 *   markings for N belong to the same row/column R/C, 
 *   then all other cells of R/C cannot have N as a candidate.
 */
class NakedSingleBlockRule : public Rule
{
    public:
        NakedSingleBlockRule() : Rule("Naked_Pair_Block_Rule") {};

        bool apply(SudokuBoard& board);
};

#endif /* RULE_H */
//  [Last modified: 2018 09 30 at 12:25:30 EDT]
