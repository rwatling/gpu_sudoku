#include "../include/timer.hpp"
#include "../include/globals.hpp"
#include "../include/utilities.hpp"
#include "../include/gpuSudoku.cuh"
#include "../include/cpuSudoku.hpp"
#include "../include/argumentParsing.hpp"
#include "../include/gpuErrorCheck.cuh"
#include "../include/cudaIncludes.cuh"

int main (int argc, char** argv) {
    ArgumentParser arguments(argc, argv);

    int puzzle[SUDOKU_SIZE][SUDOKU_SIZE];

    for (int i =0; i < SUDOKU_SIZE; i++) {
        for (int j =0; j < SUDOKU_SIZE; j++) {
            puzzle[i][j]=0;
        }
    }

    if (arguments.debug) utilities::PrintSudoku(puzzle);

    cpuSudoku::generate(puzzle, arguments.diff);
    
    if (arguments.debug) utilities::PrintSudoku(puzzle);

    /*cpuSudoku::solve(puzzle);

    if (arguments.debug) utilities::PrintSudoku(puzzle);*/

    return 0;
}