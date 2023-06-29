#include "../include/cpuSudoku.hpp"

bool cpuSudoku::inBox(unsigned int* puzzle, unsigned int selection, unsigned int value) {
    unsigned int row = selection / 9;
    unsigned int col = selection % 9;

    // Top of box
    if (row % 3 == 0) {
        // Left
        if (col % 3 == 0) {
            //puzzle[selection+10]
            //puzzle[selection+11]
            //puzzle[selection+19]
            //puzzle[selection+20]
        // Middle
        } else if (col % 3 == 1) {
            //puzzle[selection+8]
            //puzzle[selection+10]
            //puzzle[selection+17]
            //puzzle[selection+19]
        // Right
        } else if (col % 3 == 2 ) {
            //puzzle[selection+7]
            //puzzle[selection+8]
            //puzzle[selection+16]
            //puzzle[selection+17]
        }

    // Middle of box
    } else if (row % 3 == 1) {
        // Left
        if (col % 3 == 0) {
            /*puzzle[selection+10]
            puzzle[selection+11]
            puzzle[selection+19]
            puzzle[selection+20]*/
        // Middle
        } else if (col % 3 == 1) {
            /*puzzle[selection+10]
            puzzle[selection+11]
            puzzle[selection+19]
            puzzle[selection+20]*/
        // Right
        } else if (col % 3 == 2 ) {
            /*puzzle[selection+10]
            puzzle[selection+11]
            puzzle[selection+19]
            puzzle[selection+20]*/
        }

    // Bottom of box
    } else if (row % 3 == 2) {
        if (col % 3 == 0) {
            /*puzzle[selection+10]
            puzzle[selection+11]
            puzzle[selection+19]
            puzzle[selection+20]*/
        } else if (col % 3 == 1) {
            /*puzzle[selection+10]
            puzzle[selection+11]
            puzzle[selection+19]
            puzzle[selection+20]*/
        } else if (col % 3 == 2 ) {
            /*puzzle[selection+10]
            puzzle[selection+11]
            puzzle[selection+19]
            puzzle[selection+20]*/
        }
    }

    return false;
}

bool cpuSudoku::inRow(unsigned int* puzzle, unsigned int selection, unsigned int value) {
    unsigned int row = selection / 9;

    for (unsigned int i = 0; i < 9; i++) {
        unsigned int index = row * 9 + i;
        
        if (puzzle[index] != selection) { 
            if (puzzle[index] == value) {
                return true;
            }
        }
    }
    
    return false;
}

bool cpuSudoku::inCol(unsigned int* puzzle, unsigned int selection, unsigned int value) {
    unsigned int col = selection % 9;

    for (int i = 0; i < 9; i++) {
        unsigned int index = i * 9 + col;

        if (puzzle[index] != selection) { 
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
        unsigned int value = (rand() % 9) + 1;

        if (puzzle[selection] == 0) {
            for (int i = 0; i < 9; i++) {
                if (!inBox(puzzle, selection, value) &&
                    !inRow(puzzle, selection, value) && 
                    !inCol(puzzle, selection, value)) {

                    puzzle[selection] = value;
                    numSelected--;
                    break;
                } else {
                    value = (value + 1) % 9;
                }
            }
        }
    }
}