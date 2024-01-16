#include <iostream>
#include <vector>

using namespace std;

//function to print the sudoku grid
void printSudoku(const vector<vector<int>>& grid)
{
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

//function to check if number can be placed at given position
bool isSafe(const vector<vector<int>>& grid, int row, int col, int num)
{
    //check if the number is not present in the current row and column
    for(int x = 0; x < 9; ++x)
    {
        if(grid[row][x] == num || grid[x][col] == num)
        {
            return false;
        }
    }

    //Check if the number is not present in the current 3x3 subgrid
    int startRow = row -row % 3;
    int startCol = col - col % 3;
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            if(grid[i + startRow][j + startCol] == num)
            {
                return false;
            }
        }
    }
    return true;
}