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

    vector<Guess> gVec;

    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            Guess tempGuess;
            tempGuess.x = i;
            tempGuess.y = j;
            tempGuess.values = (bool*) calloc(SUDOKU_SIZE, sizeof(bool));

            if (puzzle[i*SUDOKU_SIZE+j] == 0) {
                for (int k = 0; k < SUDOKU_SIZE; k++) {
                    tempGuess.values[k] = true;
                }
                gVec.push_back(tempGuess);
            }
        }
    }

    cpuSudoku::serialSolve(puzzle, gVec);
}