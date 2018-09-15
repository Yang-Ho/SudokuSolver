#ifndef BOARD_H
#define BOARD_H 

#include<vector>
#include<unordered_set>

using namespace std;

struct Cell
{
    int value;
    vector<bool> marks;
};

class SudokuBoard 
{
    private:
        int block_size;
        vector<vector<Cell>> board;
    public:
        SudokuBoard();
        SudokuBoard(int N);
        ~SudokuBoard();

        void printBoard();
        void printMarkings();

        void fillCell(int row, int col, int val);
        void markCell(int row, int col, int candidate, bool val);
        
        int getBlockSize() { return block_size; };
        int getBoardSize() { return block_size * block_size; };

        const int getBlockNumber(int row, int col) const { return (row / block_size) * block_size + (col / block_size); }
        const int getBlockCell(int row, int col) const { return (row % block_size) * block_size + (col % block_size); }

        const int getCellValue(int row, int col) const { return board[row][col].value; };
        const vector<bool> getCellMarks(int row, int col) const { return board[row][col].marks; };

        bool isValid();
};

#endif /* BOARD_H */
//  [Last modified: 2018 09 15 at 17:06:04 EDT]
