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

class SingleCandidateRule : public Rule
{
    public:
        SingleCandidateRule() : Rule("Single_Candidate_Rule") {};

        bool apply(SudokuBoard& board);
};

class BasicRowRule : public Rule
{
    public:
        BasicRowRule() : Rule("Basic_Row_Rule") {};

        bool apply(SudokuBoard& board);
};

class BasicColumnRule : public Rule
{
    public:
        BasicColumnRule() : Rule("Basic_Column_Rule") {};

        bool apply(SudokuBoard& board);
};

class BasicBlockRule : public Rule
{
    public:
        BasicBlockRule() : Rule("Basic_Block_Rule") {};

        bool apply(SudokuBoard& board);
};

#endif /* RULE_H */
//  [Last modified: 2018 09 15 at 17:10:06 EDT]
