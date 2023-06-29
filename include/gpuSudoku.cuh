#ifndef GPU_SUDOKU_CUH
#define GPU_SUDOKU_CUH

#include "globals.hpp"
#include "cudaIncludes.cuh"

namespace gpuSudoku {
    __device__ unsigned int getGlobalID();
}

#endif