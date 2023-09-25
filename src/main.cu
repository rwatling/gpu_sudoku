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

    int puzzle[SUDOKU_SIZE][SUDOKU_SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (arguments.debug) utilities::PrintSudoku(puzzle);

    if (cpuSudoku::solve(puzzle)) {
        utilities::PrintSudoku(puzzle);
    } else {
        cout << "No solution" << endl;
    }

    return 0;
}