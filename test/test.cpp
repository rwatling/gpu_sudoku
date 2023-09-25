#include <catch2/catch_test_macros.hpp>
#include "../include/globals.hpp"
#include "../include/utilities.hpp"
#include "../include/cpuSudoku.hpp"

TEST_CASE ( "Sudoku row check case 1", "[row check case 1]") {
    int puzzle[SUDOKU_SIZE][SUDOKU_SIZE];
    memset(puzzle, 0, sizeof(puzzle[0][0]) * SUDOKU_SIZE * SUDOKU_SIZE);
    int value = 3;

    puzzle[0][0] = value;
    puzzle[0][8] = value;

    REQUIRE(!cpuSudoku::validRow(puzzle, 0, 0, value));
    REQUIRE(!cpuSudoku::validRow(puzzle, 0, 8, value));
    REQUIRE(cpuSudoku::validRow(puzzle, 2, 0, value));
}

TEST_CASE ( "Sudoku row check case 2", "[row check case 2]") {
    int puzzle[SUDOKU_SIZE][SUDOKU_SIZE];
    memset(puzzle, 0, sizeof(puzzle[0][0]) * SUDOKU_SIZE * SUDOKU_SIZE);
    int value = 3;

    puzzle[0][0] = value;
    puzzle[1][5] = value;

    REQUIRE(!cpuSudoku::validRow(puzzle, 0, 0, value));
    REQUIRE(!cpuSudoku::validRow(puzzle, 0, 5, value));
    REQUIRE(!cpuSudoku::validRow(puzzle, 1, 5, value));
}

TEST_CASE ( "Sudoku row check case 3", "[row check case 3]") {
    int puzzle[SUDOKU_SIZE][SUDOKU_SIZE];
    memset(puzzle, 0, sizeof(puzzle[0][0]) * SUDOKU_SIZE * SUDOKU_SIZE);
    int value = 5;

    puzzle[3][3] = value;
    puzzle[7][5] = value + 1;

    REQUIRE(!cpuSudoku::validRow(puzzle, 3, 3, value));
    REQUIRE(cpuSudoku::validRow(puzzle, 7, 5, value));
    REQUIRE(cpuSudoku::validRow(puzzle, 1, 5, value));
}

TEST_CASE ( "Sudoku col check case 1", "[col check case 1]") {
    int puzzle[SUDOKU_SIZE][SUDOKU_SIZE];
    memset(puzzle, 0, sizeof(puzzle[0][0]) * SUDOKU_SIZE * SUDOKU_SIZE);
    int value = 3;

    puzzle[0][5] = value;
    puzzle[1][5] = value;

    REQUIRE(cpuSudoku::validCol(puzzle, 0, 0, value));
    REQUIRE(!cpuSudoku::validCol(puzzle, 0, 5, value));
    REQUIRE(!cpuSudoku::validCol(puzzle, 1, 5, value));
}

TEST_CASE ( "Sudoku col check case 2", "[col check case 2]") {
    int puzzle[SUDOKU_SIZE][SUDOKU_SIZE];
    memset(puzzle, 0, sizeof(puzzle[0][0]) * SUDOKU_SIZE * SUDOKU_SIZE);
    int value = 5;

    puzzle[3][3] = value;
    puzzle[7][5] = value + 1;

    REQUIRE(!cpuSudoku::validCol(puzzle, 2, 3, value));
    REQUIRE(cpuSudoku::validCol(puzzle, 7, 5, value));
    REQUIRE(cpuSudoku::validCol(puzzle, 1, 5, value));
}

TEST_CASE ( "Sudoku box check case 1", "[box check case 1]") {
    int puzzle[SUDOKU_SIZE][SUDOKU_SIZE];
    memset(puzzle, 0, sizeof(puzzle[0][0]) * SUDOKU_SIZE * SUDOKU_SIZE);
    int value = 3;

    puzzle[0][2] = value;
    puzzle[1][1] = value;

    REQUIRE(!cpuSudoku::validBox(puzzle, 0, 0, value));
    REQUIRE(cpuSudoku::validBox(puzzle, 4, 5, value));
    REQUIRE(cpuSudoku::validBox(puzzle, 8, 5, value));
}

TEST_CASE ( "Sudoku box check case 2", "[box check case 2]") {
    int puzzle[SUDOKU_SIZE][SUDOKU_SIZE];
    memset(puzzle, 0, sizeof(puzzle[0][0]) * SUDOKU_SIZE * SUDOKU_SIZE);
    int value = 5;

    puzzle[2][2] = value;
    puzzle[1][0] = value + 1;

    REQUIRE(!cpuSudoku::validBox(puzzle, 0, 0, value));
    REQUIRE(!cpuSudoku::validBox(puzzle, 2, 2, value+1));
    REQUIRE(cpuSudoku::validBox(puzzle, 1, 1, value+2));
}