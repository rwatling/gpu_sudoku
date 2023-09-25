#include "../include/cpuSudoku.hpp"

// Returns true if value is not in box
bool cpuSudoku::validBox(int puzzle[SUDOKU_SIZE][SUDOKU_SIZE], int row, int col, int value) {
    int subgridRow = (row / 3) * 3;
    int subgridCol = (col / 3) * 3;
    
    for (int i = 0; i < (SUDOKU_SIZE / 3); i++) {
        for (int j = 0; j < (SUDOKU_SIZE / 3); j++) {
            if (puzzle[subgridRow + i][subgridCol + j] == value)
                return false;
        }
    }

    return true;
}

// Returns true if value is not in row
bool cpuSudoku::validRow(int puzzle[SUDOKU_SIZE][SUDOKU_SIZE], int row, int col, int value) {
    for (int i = 0; i < 9; i++) {
        if (puzzle[row][i] == value)
            return false;
    }

    return true;
}

// Returns true if value is not in column
bool cpuSudoku::validCol(int puzzle[SUDOKU_SIZE][SUDOKU_SIZE], int row, int col, int value) {
    for (int i = 0; i < 9; i++) {
        if (puzzle[i][col] == value)
            return false;
    }

    return true;
}

bool cpuSudoku::isValid(int puzzle[SUDOKU_SIZE][SUDOKU_SIZE], int row, int col, int value) {
    return validRow(puzzle, row, col, value) && validCol(puzzle, row, col, value) && validBox(puzzle, row, col, value);
}

bool cpuSudoku::findEmptyCell(int puzzle[SUDOKU_SIZE][SUDOKU_SIZE], int* row, int* col) {
    for (*row = 0; *row < SUDOKU_SIZE; (*row)++) {
        for (*col = 0; *col < SUDOKU_SIZE; (*col)++) {
            if (puzzle[*row][*col] == 0)
                return true;  // Found an empty cell
        }
    }
    
    return false;  // No empty cell found
}

// Recursive sudoku backtracking algorithm
bool cpuSudoku::solve(int puzzle[SUDOKU_SIZE][SUDOKU_SIZE]) {
    int row = 0;
    int col = 0;

    // Find the next empty cell or a cell with 0
    if (!findEmptyCell(puzzle, &row, &col))
        return true;  // Puzzle solved

    // Try all possible values from 1 to 9
    for (int num = 1; num <= 9; num++) {
        // Check if the current value is valid
        if (isValid(puzzle, row, col, num)) {
            // Assign the value and recursively solve
            puzzle[row][col] = num;
            
            if (solve(puzzle)) return true;  // Puzzle solved
            
            // Undo the assignment and try the next value
            puzzle[row][col] = 0;
        }
    }
    
    return false;  // No solution found
}