#ifndef SUDOKU_CUH
#define SUDOKU_CUH

#include "globals.hpp"

namespace sudoku {
    __device__ uint8_t getGlobalID();
    __host__  void cpuGenerate(uint8_t* puzzle, Difficulty d);
}

#endif