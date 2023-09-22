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

    unsigned int rows = SUDOKU_SIZE;
    unsigned int columns = SUDOKU_SIZE;
    unsigned int* puzzle = (unsigned int*) calloc(rows * columns, sizeof(unsigned int));

    if (arguments.debug) utilities::PrintSudoku(puzzle);

    cpuSudoku::generate(puzzle, arguments.diff);
    
    if (arguments.debug) utilities::PrintSudoku(puzzle);
}