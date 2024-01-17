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

//Function to solve the Sudoku using backtracking
bool solveSudoku(vector<vector<int>>& grid)
{
    for(int row = 0; row < 9; ++row)
    {
        for(int col = 0; col < 9; ++col)
        {
            // Find an empty cell
            if(grid[row][col] == 0)
            {
                //Try placing a number from 1 to 9
                for(int num = 1; num <= 9; ++num)
                {
                    //Check if the number can be placed
                    if(isSafe(grid, row, col, num))
                    {
                        //place the number
                        grid[row][col] = num
                    
                        //Recursive call to solve the rest of the puzzle
                        if(solveSudoku(grid))
                        {
                            return true; //If successful, puzzle is completed
                        }

                        //If placing the number doesn't lead to solution, backtrack
                        grid[row][col] = 0;
                    }
                }

                //If no number can be placed, backtrack
                return false;
            }
        }
    }
    
    //If entire grid filled, puzzle solved
    return true;
}