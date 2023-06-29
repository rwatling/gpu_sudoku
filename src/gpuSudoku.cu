#include "../include/gpuSudoku.cuh"

__device__ unsigned int gpuSudoku::getGlobalID() {
    return blockDim.x * blockIdx.x + threadIdx.x;
}