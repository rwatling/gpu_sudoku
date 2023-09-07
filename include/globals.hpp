#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <string>
#include <ctime>
#include <random>
#include <stdio.h>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <chrono>
#include <stdexcept>
#include <iostream>
#include <sstream> 
#include <climits>
#include <stdint.h>

#define SUDOKU_SIZE 9

using namespace std;

typedef unsigned int uint;

enum Difficulty : unsigned char {
    EASY = 1,
    MEDIUM = 2,
    HARD = 3,
    EXPERT = 4
};

typedef struct Guess {
    unsigned int x;
    unsigned int y;
    bool* values;
} Guess;

#endif 	//	GLOBALS_HPP
