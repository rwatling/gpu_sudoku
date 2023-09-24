#include <catch2/catch_test_macros.hpp>
#include "../include/globals.hpp"
#include "../include/utilities.hpp"
#include "../include/cpuSudoku.hpp"

/***** Check row test cases *****/
/*TEST_CASE ( "Sudoku row check case 1", "[row check case 1]") {
    int rows = 9;
    int columns = 9;
    int puzzle[rows][columns] = {};
    int value = 3;
    int index1 = 0;
    int index2 = 8;

    puzzle[index1] = value;
    puzzle[index2] = value;

    REQUIRE(!cpuSudoku::validRow(puzzle, index1, value));
    REQUIRE(!cpuSudoku::validRow(puzzle, index2, value));
}

TEST_CASE ( "Sudoku row check case 2", "[row check case 2]") {
    int rows = 9;
    int columns = 9;
    int puzzle[rows][columns] = {};
    int value = 7;
    int index1 = 0;
    int index2 = 5;

    puzzle[index1] = value;
    puzzle[index2] = value;

    REQUIRE(!cpuSudoku::validRow(puzzle, index1, value));
    REQUIRE(!cpuSudoku::validCol(puzzle, index2, value));
}

TEST_CASE ( "Sudoku row check case 3", "[row check case 3]") {
    int rows = 9;
    int columns = 9;
    int puzzle[rows][columns] = {};
    int value = 2;
    int index1 = 0;
    int index2 = 9;

    puzzle[index1] = value;
    puzzle[index2] = value;

    REQUIRE(!cpuSudoku::inRow(puzzle, index1, value));
    REQUIRE(!cpuSudoku::inRow(puzzle, index2, value));
}

TEST_CASE ( "Sudoku row check case 4", "[row check case 4]") {
    int rows = 9;
    int columns = 9;
    int puzzle[rows][columns] = {};
    int value = 2;
    int index1 = 0;
    int index2 = 3;

    puzzle[index1] = value;
    puzzle[index2] = value + 1;

    REQUIRE(!cpuSudoku::inRow(puzzle, index1, value));
    REQUIRE(!cpuSudoku::inRow(puzzle, index2, value + 1));
}

TEST_CASE ( "Sudoku row check case 5", "[row check case 5]") {
    int rows = 9;
    int columns = 9;
    int puzzle[rows][columns] = {};
    int value = 2;
    int index1 = 0;
    int index2 = index1;

    puzzle[index1] = value;
    puzzle[index2] = value;

    REQUIRE(!cpuSudoku::inRow(puzzle, index1, value));
    REQUIRE(!cpuSudoku::inRow(puzzle, index2, value));
}*/

/***** Check column test cases *****/
/*TEST_CASE ( "Sudoku col check case 1", "[col check case 1]") {
    int rows = 9;
    int columns = 9;
    int puzzle[rows][columns] = {};
    int value = 2;
    int index1 = 3;
    int index2 = index1 + 9;

    puzzle[index1] = value;
    puzzle[index2] = value;

    REQUIRE(cpuSudoku::inCol(puzzle, index1, value));
    REQUIRE(cpuSudoku::inCol(puzzle, index2, value));
}

TEST_CASE ( "Sudoku col check case 2", "[col check case 2]") {
    int rows = 9;
    int columns = 9;
    int puzzle[rows][columns] = {};
    int value = 2;
    int index1 = 3;
    int index2 = index1 + 12;

    puzzle[index1] = value;
    puzzle[index2] = value;

    REQUIRE(!cpuSudoku::inCol(puzzle, index1, value));
    REQUIRE(!cpuSudoku::inCol(puzzle, index2, value));
}

TEST_CASE ( "Sudoku col check case 3", "[col check case 3]") {
    int rows = 9;
    int columns = 9;
    int puzzle[rows][columns] = {};
    int value = 2;
    int index1 = 3;
    int index2 = index1 + 9;

    puzzle[index1] = value;
    puzzle[index2] = value + 1;

    REQUIRE(!cpuSudoku::inCol(puzzle, index1, value));
    REQUIRE(!cpuSudoku::inCol(puzzle, index2, value + 1));
}

TEST_CASE ( "Sudoku col check case 4", "[col check case 4]") {
    int rows = 9;
    int columns = 9;
    int puzzle[rows][columns] = {};
    int value = 2;
    int index1 = 4;
    int index2 = index1;

    puzzle[index1] = value;
    puzzle[index2] = value;

    REQUIRE(!cpuSudoku::inCol(puzzle, index1, value));
    REQUIRE(!cpuSudoku::inCol(puzzle, index2, value));
}*/

/***** Check box test cases *****/
/*TEST_CASE ( "Sudoku box check case 1", "[box check case 1]") {
    int rows = 9;
    int columns = 9;
    int puzzle[rows][columns] = {};
    int value = 2;
    int index1 = 0;
    int index2 = index1 + 10;

    puzzle[index1] = value;
    puzzle[index2] = value;

    REQUIRE(cpuSudoku::inBox(puzzle, index1, value));
    REQUIRE(cpuSudoku::inBox(puzzle, index2, value));
}

TEST_CASE ( "Sudoku box check case 2", "[box check case 2]") {
    int rows = 9;
    int columns = 9;
    int puzzle[rows][columns] = {};
    int value = 2;
    int index1 = 0;
    int index2 = index1 + 11;

    puzzle[index1] = value;
    puzzle[index2] = value;

    REQUIRE(cpuSudoku::inBox(puzzle, index1, value));
    REQUIRE(cpuSudoku::inBox(puzzle, index2, value));
}

TEST_CASE ( "Sudoku box check case 3", "[box check case 3]") {
    int rows = 9;
    int columns = 9;
    int puzzle[rows][columns] = {};
    int value = 2;
    int index1 = 0;
    int index2 = index1 + 19;

    puzzle[index1] = value;
    puzzle[index2] = value;

    REQUIRE(cpuSudoku::inBox(puzzle, index1, value));
    REQUIRE(cpuSudoku::inBox(puzzle, index2, value));
}

TEST_CASE ( "Sudoku box check case 4", "[box check case 4]") {
    int rows = 9;
    int columns = 9;
    int puzzle[rows][columns] = {};
    int value = 2;
    int index1 = 0;
    int index2 = index1 + 20;

    puzzle[index1] = value;
    puzzle[index2] = value;

    REQUIRE(cpuSudoku::inBox(puzzle, index1, value));
    REQUIRE(cpuSudoku::inBox(puzzle, index2, value));
}

TEST_CASE ( "Sudoku box check case 5", "[box check case 5]") {
    int rows = 9;
    int columns = 9;
    int puzzle[rows][columns] = {};
    int value = 2;
    int index1 = 1;
    int index2 = index1 + 8;

    puzzle[index1] = value;
    puzzle[index2] = value;

    REQUIRE(cpuSudoku::inBox(puzzle, index1, value));
    REQUIRE(cpuSudoku::inBox(puzzle, index2, value));
}

TEST_CASE ( "Sudoku box check case 6", "[box check case 6]") {
    int rows = 9;
    int columns = 9;
    int puzzle[rows][columns] = {};
    int value = 2;
    int index1 = 4;
    int index2 = index1 + 10;

    puzzle[index1] = value;
    puzzle[index2] = value;

    REQUIRE(cpuSudoku::inBox(puzzle, index1, value));
    REQUIRE(cpuSudoku::inBox(puzzle, index2, value));
}

TEST_CASE ( "Sudoku box check case 7", "[box check case 7]") {
    int rows = 9;
    int columns = 9;
    int puzzle[rows][columns] = {};
    int value = 2;
    int index1 = 7;
    int index2 = index1 + 17;

    puzzle[index1] = value;
    puzzle[index2] = value;

    REQUIRE(cpuSudoku::inBox(puzzle, index1, value));
    REQUIRE(cpuSudoku::inBox(puzzle, index2, value));
}

TEST_CASE ( "Sudoku box check case 8", "[box check case 8]") {
    int rows = 9;
    int columns = 9;
    int puzzle[rows][columns] = {};
    int value = 2;
    int index1 = 1;
    int index2 = index1 + 19;

    puzzle[index1] = value;
    puzzle[index2] = value;

    REQUIRE(cpuSudoku::inBox(puzzle, index1, value));
    REQUIRE(cpuSudoku::inBox(puzzle, index2, value));
}

TEST_CASE ( "Sudoku box check case 9", "[box check case 9]") {
    int rows = 9;
    int columns = 9;
    int puzzle[rows][columns] = {};
    int value = 2;
    int index1 = 5;
    int index2 = index1 + 7;

    puzzle[index1] = value;
    puzzle[index2] = value;

    REQUIRE(cpuSudoku::inBox(puzzle, index1, value));
    REQUIRE(cpuSudoku::inBox(puzzle, index2, value));
}

TEST_CASE ( "Sudoku box check case 10", "[box check case 10]") {
    int rows = 9;
    int columns = 9;
    int puzzle[rows][columns] = {};
    int value = 2;
    int index1 = 5;
    int index2 = index1 + 8;

    puzzle[index1] = value;
    puzzle[index2] = value;

    REQUIRE(cpuSudoku::inBox(puzzle, index1, value));
    REQUIRE(cpuSudoku::inBox(puzzle, index2, value));
}

TEST_CASE ( "Sudoku box check case 11", "[box check case 11]") {
    int rows = 9;
    int columns = 9;
    int puzzle[rows][columns] = {};
    int value = 2;
    int index1 = 8;
    int index2 = index1 + 16;

    puzzle[index1] = value;
    puzzle[index2] = value;

    REQUIRE(cpuSudoku::inBox(puzzle, index1, value));
    REQUIRE(cpuSudoku::inBox(puzzle, index2, value));
}

TEST_CASE ( "Sudoku box check case 12", "[box check case 12]") {
    int rows = 9;
    int columns = 9;
    int puzzle[rows][columns] = {};
    int value = 2;
    int index1 = 8;
    int index2 = index1 + 17;

    puzzle[index1] = value;
    puzzle[index2] = value;

    REQUIRE(cpuSudoku::inBox(puzzle, index1, value));
    REQUIRE(cpuSudoku::inBox(puzzle, index2, value));
}*/