
#include "utilities.hpp"

void PrintHelper() {
	for (int i = 0; i < 3; i++) {
		cout << "+-----";
	}
	cout << "+\n";
}

void utilities::PrintSudoku(unsigned int* puzzle)
{
	unsigned int rowSize = 9;
	for (int i = 0; i < rowSize; i++) {
		if ((i % 3 == 0)) {
			PrintHelper();
		}

		for (int j = 0; j < rowSize; j++) {

			if (j % 3 == 0) {
				cout << "|";
			}

			if (puzzle[i*rowSize+j] == 0) {
				cout << "-";
			} else {
				cout << puzzle[i*rowSize + j];
			}

			if (j % 3 !=  2) {
				cout << " ";
			}
		}
		cout << "|\n";
	}
	PrintHelper();
}