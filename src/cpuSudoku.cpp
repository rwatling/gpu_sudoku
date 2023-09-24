#include "../include/cpuSudoku.hpp"

bool cpuSudoku::validBox(int puzzle[SUDOKU_SIZE][SUDOKU_SIZE], int row, int col, int value) {
   // Check if the number already exists in the same 3x3 sub-grid
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

bool cpuSudoku::validRow(int puzzle[SUDOKU_SIZE][SUDOKU_SIZE], int row, int col, int value) {
    // Check if the number already exists in the same row
    for (int i = 0; i < 9; i++) {
        if (puzzle[row][i] == value)
            return false;
    }
    
    return true;
}

bool cpuSudoku::validCol(int puzzle[SUDOKU_SIZE][SUDOKU_SIZE], int row, int col, int value) {
    // Check if the number already exists in the same column
    for (int i = 0; i < 9; i++) {
        if (puzzle[i][col] == value)
            return false;
    }

    return true;
}

bool cpuSudoku::isSafe(int puzzle[SUDOKU_SIZE][SUDOKU_SIZE], int row, int col, int value) {
    return validRow(puzzle, row, col, value) && validCol(puzzle, row, col, value) && validBox(puzzle, row, col, value);
}

void cpuSudoku::generate(int puzzle[SUDOKU_SIZE][SUDOKU_SIZE], Difficulty d){
    unsigned int numSelected;

    // Difficulty is determined by how many cells are filled in
    switch (d) {
        case EASY:
            numSelected = 40;
            break;
        case MEDIUM:
            numSelected = 30;
            break;
        case HARD:
            numSelected = 25;
            break;
        case EXPERT:
            numSelected = 20;
            break;
        default:
            numSelected = 0;
            break;
    }

    // Difficulty can vary by 5 cell entries
    if (numSelected) {
        srand((unsigned) time(NULL));
        unsigned int random = rand() % 5;

        numSelected += random;
    }

    int totalCells = 81;

    while (numSelected != 0) {
        int selection = rand() % totalCells;
        int row = selection / SUDOKU_SIZE;
        int col = selection % SUDOKU_SIZE;
        int value = (rand() % SUDOKU_SIZE) + 1;

        if (puzzle[selection] == 0) {
            for (int i = 0; i < SUDOKU_SIZE; i++) {
                if (isSafe(puzzle, row, col, value)) {
                    puzzle[row][col] = value;
                    numSelected--;
                    break;
                } else {
                    value = (value + 1) % SUDOKU_SIZE;
                }
            }
        }
    }
}

bool findEmptyCell(int puzzle[SUDOKU_SIZE][SUDOKU_SIZE], unsigned int* row, unsigned int* col) {
    for (*row = 0; *row < SUDOKU_SIZE; (*row)++) {
        for (*col = 0; *col < SUDOKU_SIZE; (*col)++) {
            if (puzzle[(*row)*SUDOKU_SIZE+(*col)] == 0) {
                return true;  // Found an empty cell
            }
        }
    }

    return false;  // No empty cell found
}

// Recursive sudoku backtracking algorithm
/*bool cpuSudoku::solve(int puzzle[SUDOKU_SIZE][SUDOKU_SIZE]) {
    unsigned int row = 0;
    unsigned int col = 0;
    
    // Find the next empty cell or a cell with 0
    if (!findEmptyCell(puzzle, &row, &col))
        return true;  // Puzzle solved
    
    // Try all possible values from 1 to 9
    for (unsigned int num = 1; num <= 9; num++) {
        
        // Check if the current value is valid
        if (isSafe(puzzle, row*SUDOKU_SIZE+col, num)) {
            
            // Assign the value and recursively solve
            puzzle[row*SUDOKU_SIZE+col] = num;
            
            if (cpuSudoku::solve(puzzle))
                return true;  // Puzzle solved
            
            // Undo the assignment and try the next value if not able to solve
            puzzle[row*SUDOKU_SIZE+col] = 0;
        }
    }
    
    return false;  // No solution found
}*/