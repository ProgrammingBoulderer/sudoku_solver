#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H

#include <vector>

//Create class Sudoku
class Sudoku{
    
    public:
    void printSudoku(const std::vector<std::vector<int>>& grid);

    bool isSafe(const std::vector<std::vector<int>>& grid, int row, int col, int num);

    bool solveSudoku(std::vector<std::vector<int>>& grid);

};
#endif