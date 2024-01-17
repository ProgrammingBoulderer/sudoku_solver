#include "sudoku_solver.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //Example of sudoku puzzle (0 represents the empty cell)
    vector<vector<int>> sudokuGrid = {
        {5, 3, 0, 0, 7, 0, 0, 0 ,0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    //intialise sudoku object
    Sudoku *sudoku = new Sudoku();

    cout << "Original Sudoku Puzzle: " << endl;
    sudoku->printSudoku(sudokuGrid);

    if(sudoku->solveSudoku(sudokuGrid))
    {
        cout << "\nSolved Sudoku Puzzle: " << endl;
        sudoku->printSudoku(sudokuGrid);
    }
    else
    {
        cout << "\nNo solutions exists." << endl;
    }
    
    return 0;
}