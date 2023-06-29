#ifndef SUDOKU_CUH
#define SUDOKU_CUH

#include "globals.hpp"

namespace gpuSudoku {
    __device__ unsigned int getGlobalID();
}

#endif