#ifndef CPU_SUDOKU_HPP
#define CPU_SUDOKU_HPP

#include "globals.hpp"

namespace cpuSudoku {
    bool validBox(int puzzle[SUDOKU_SIZE][SUDOKU_SIZE], int row, int col, int value);
    bool validRow(int puzzle[SUDOKU_SIZE][SUDOKU_SIZE], int row, int col, int value);
    bool validCol(int puzzle[SUDOKU_SIZE][SUDOKU_SIZE], int row, int col, int value);
    bool isValid(int puzzle[SUDOKU_SIZE][SUDOKU_SIZE], int row, int col, int value);
    //void generate(int puzzle[SUDOKU_SIZE][SUDOKU_SIZE], Difficulty d);
    bool findEmptyCell(int puzzle[SUDOKU_SIZE][SUDOKU_SIZE], int* row, int* col);
    bool solve(int puzzle[SUDOKU_SIZE][SUDOKU_SIZE]);
}

#endif