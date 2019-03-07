
#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include <time.h>
#include "Minefield.h"

Minefield::Cell Minefield::Open(unsigned int x, unsigned int y) {

    return MINE;
}

Minefield::Cell Minefield::GetCellAt(unsigned int x, unsigned int y) const {

    return MINE;
}

Minefield::CellIndex *Minefield::GenerateMinefield(unsigned int width, unsigned int height, unsigned int count) {

    CellIndex *Grid = new CellIndex[width];
    srand(time(NULL));

    for (unsigned int m = 0; m < count; m++) {
        // do nothing right now
    }

    Grid[rand() % (width*height)].Status = MINE;

    for (unsigned int i = 0; i < width; i++) {
        for (unsigned int j = 0; j < height; j++) {
            Grid[i + j].Column = i;
            Grid[i + j].Row = j;
            if (Grid[i + j].Status != MINE) {
                Grid[i + j].Status = GetRandomCellStatus();
            }
            std::string CellString = GetCellAsString(Grid[i + j].Status);
            std::cout << CellString;
        }
        std::cout << "\n";
    }

    return Grid;
}

Minefield::Cell Minefield::GetRandomCellStatus() {

    return static_cast<Cell>(rand() % MINE);
}