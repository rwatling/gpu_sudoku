#include "../include/sudoku.cuh"

__device__ int sudoku::getGlobalID() {
    return blockDim.x * blockIdx.x + threadIdx.x;
}