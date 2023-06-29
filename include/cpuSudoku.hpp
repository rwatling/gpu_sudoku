#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include "globals.hpp"

namespace cpuSudoku {
    bool inBox(unsigned int* puzzle, unsigned int selection, unsigned int value);
    bool inRow(unsigned int* puzzle, unsigned int selection, unsigned int value);
    bool inCol(unsigned int* puzzle, unsigned int selection, unsigned int value);
    void generate(unsigned int* puzzle, Difficulty d);
}

#endif