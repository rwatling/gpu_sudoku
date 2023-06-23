#include "../include/sudoku.cuh"

__host__ void sudoku::cpuGenerate(uint8_t* puzzle, Difficulty d){
    uint8_t numSelected;

    // Difficulty is determined by how many cells are filled in
    switch (d) {
        case EASY:
            numSelected = 35;
            break;
        case MEDIUM:
            numSelected = 30;
            break;
        case HARD:
            numSelected = 25;
            break;
        case EXPERT:
            numSelected = 20;
            break;
        default:
            numSelected = 0;
            break;
    }

    // Difficulty can vary by 5 cell entries
    if (numSelected) {
        srand((unsigned) time(NULL));
        unsigned int random = rand() % 5;

        numSelected += random;
    }
}

__device__ uint8_t sudoku::getGlobalID() {
    return blockDim.x * blockIdx.x + threadIdx.x;
}