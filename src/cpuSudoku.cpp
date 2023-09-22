#include "../include/cpuSudoku.hpp"

bool cpuSudoku::inBox(unsigned int* puzzle, unsigned int selection, unsigned int value) {
    unsigned int row = selection / SUDOKU_SIZE;
    unsigned int col = selection % SUDOKU_SIZE;

    // Top of box
    if (row % 3 == 0) {
        // Left
        if (col % 3 == 0) {
            if(puzzle[selection+10] == value) return true;
            if(puzzle[selection+11] == value) return true;
            if(puzzle[selection+19] == value) return true;
            if(puzzle[selection+20] == value) return true;
        // Middle
        } else if (col % 3 == 1) {
            if(puzzle[selection+8] == value) return true;
            if(puzzle[selection+10] == value) return true;
            if(puzzle[selection+17] == value) return true;
            if(puzzle[selection+19] == value) return true;
        // Right
        } else if (col % 3 == 2 ) {
            if(puzzle[selection+7] == value) return true;
            if(puzzle[selection+8] == value) return true;
            if(puzzle[selection+16] == value) return true;
            if(puzzle[selection+17] == value) return true;
        }

    // Middle of box
    } else if (row % 3 == 1) {
        // Left
        if (col % 3 == 0) {
            if (puzzle[selection-8] == value) return true;
            if (puzzle[selection-7] == value) return true;
            if (puzzle[selection+10] == value) return true;
            if (puzzle[selection+11] == value) return true;
        // Middle
        } else if (col % 3 == 1) {
            if (puzzle[selection-10] == value) return true;
            if (puzzle[selection-8] == value) return true;
            if (puzzle[selection+8] == value) return true;
            if (puzzle[selection+10] == value) return true;
        // Right
        } else if (col % 3 == 2 ) {
            if (puzzle[selection-10] == value) return true;
            if (puzzle[selection-11] == value) return true;
            if (puzzle[selection+7] == value) return true;
            if (puzzle[selection+8] == value) return true;
        }

    // Bottom of box
    } else if (row % 3 == 2) {
        //Left
        if (col % 3 == 0) {
            if (puzzle[selection-17] == value) return true;
            if (puzzle[selection-16] == value) return true;
            if (puzzle[selection-8] == value) return true;
            if (puzzle[selection-7] == value) return true;
        //Middle
        } else if (col % 3 == 1) {
            if (puzzle[selection-19] == value) return true;
            if (puzzle[selection-17] == value) return true;
            if (puzzle[selection-10] == value) return true;
            if (puzzle[selection-8] == value) return true;
        //Right
        } else if (col % 3 == 2 ) {
            if (puzzle[selection-20] == value) return true;
            if (puzzle[selection-19] == value) return true;
            if (puzzle[selection-11] == value) return true;
            if (puzzle[selection-10] == value) return true;
        }
    }

    return false;
}

bool cpuSudoku::inRow(unsigned int* puzzle, unsigned int selection, unsigned int value) {
    unsigned int row = selection / SUDOKU_SIZE;

    for (unsigned int i = 0; i < SUDOKU_SIZE; i++) {
        unsigned int index = row * SUDOKU_SIZE + i;
        
        if (index != selection) { 
            if (puzzle[index] == value) {
                return true;
            }
        }
    }
    
    return false;
}

bool cpuSudoku::inCol(unsigned int* puzzle, unsigned int selection, unsigned int value) {
    unsigned int col = selection % SUDOKU_SIZE;

    for (int i = 0; i < SUDOKU_SIZE; i++) {
        unsigned int index = i * SUDOKU_SIZE + col;

        if (index != selection) { 
            if (puzzle[index] == value) {
                return true;
            }
        }
    }

    return false;
}

void cpuSudoku::generate(unsigned int* puzzle, Difficulty d){
    unsigned int numSelected;

    // Difficulty is determined by how many cells are filled in
    switch (d) {
        case EASY:
            numSelected = 35;
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
        unsigned int selection = rand() % totalCells;
        unsigned int value = (rand() % SUDOKU_SIZE) + 1;

        if (puzzle[selection] == 0) {
            for (int i = 0; i < SUDOKU_SIZE; i++) {
                if (!inBox(puzzle, selection, value) &&
                    !inRow(puzzle, selection, value) && 
                    !inCol(puzzle, selection, value)) {

                    puzzle[selection] = value;
                    numSelected--;
                    break;
                } else {
                    value = (value + 1) % SUDOKU_SIZE;
                }
            }
        }
    }
}

void cpuSudoku::serialSolve(unsigned int* puzzle, vector<Guess> gVec) {
}