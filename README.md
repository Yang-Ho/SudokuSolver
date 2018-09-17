# SudokuSolver
A sudoku solver written in C++

### Rules:

#### Basic:
1) Single Candidate Rule:
    - If a cell is marked with only one candidate, then the cell's value must be that candidate
2) Basic Row/Column/Block:
    - If a candidate only has 1 mark in a row/column/block's markings, then the cell containing that mark must be that candidate
