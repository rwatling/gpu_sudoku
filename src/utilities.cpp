
#include "utilities.hpp"

void PrintHelper() {
	for (int i = 0; i < 3; i++) {
		cout << "+-----";
	}
	cout << "+\n";
}

void utilities::PrintSudoku(int puzzle[SUDOKU_SIZE][SUDOKU_SIZE])
{
	unsigned int rowSize = SUDOKU_SIZE;
	for (int i = 0; i < rowSize; i++) {
		if ((i % 3 == 0)) {
			PrintHelper();
		}

		for (int j = 0; j < rowSize; j++) {

			if (j % 3 == 0) {
				cout << "|";
			}

			if (puzzle[i][j] == 0) {
				cout << "-";
			} else {
				cout << puzzle[i][j];
			}

			if (j % 3 !=  2) {
				cout << " ";
			}
		}
		cout << "|\n";
	}
	PrintHelper();
}