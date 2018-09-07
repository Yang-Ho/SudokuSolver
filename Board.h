#ifndef BOARD_H
#define BOARD_H 
#endif /* BOARD_H */

#include<vector>

using namespace std;

class SudokuBoard 
{
    private:
        int grid_size; // For convience
        vector<vector<int>> board;
        vector<vector<vector<int>>> candidates; // Used to keep track of candidates of a cell
    public:
        SudokuBoard();
        SudokuBoard(int N);
        ~SudokuBoard();

        void printBoard();

        /*
        void fillSquare(int i, int j, int val);
        bool isSafe(int i, int j, int val);
        bool checkCorrectness();
        */

};

//  [Last modified: 2018 09 07 at 13:02:54 EDT]
