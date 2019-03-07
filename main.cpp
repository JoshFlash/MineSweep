#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include "Minefield.h"

using Cell = Minefield::Cell;

unsigned int GridWidth;
unsigned int GridHeight;

std::map<Minefield::Cell, std::string> CellToString{
            {Cell::EMPTY,  "."},
            {Cell::M1,     "1"},
            {Cell::M2,     "2"},
            {Cell::M3,     "3"},
            {Cell::M4,     "4"},
            {Cell::M5,     "5"},
            {Cell::M6,     "6"},
            {Cell::M7,     "7"},
            {Cell::M8,     "8"},
            {Cell::M9,     "9"},
            {Cell::MINE,   "M"},
            {Cell::CLOSED, "X"}
    };

void GenerateMinefield(unsigned int width, unsigned int height, unsigned int count);

int main() {

    std::cout << "Start\n" << std::endl;

    GenerateMinefield(6,7,3);

    return 0;
}

void GenerateMinefield(unsigned int width, unsigned int height, unsigned int count) {

    Cell Grid[width][height];

    srand(time(NULL));

    for (unsigned int m = 0; m < count; m++) {
        // do nothing right now
    }

    Grid[2][2] = Cell::MINE;

    for (unsigned int i = 0; i < width; i++) {
        for (unsigned int j = 0; j < height; j++) {
            Cell NextCell = Grid[i][j];
            if (NextCell != Cell::MINE) {
                NextCell = Cell::EMPTY;
            }
            std::cout << CellToString[NextCell];
        }
        std::cout << "\n";
    }

    // return Grid;
}