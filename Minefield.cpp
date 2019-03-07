
#include <iostream>
#include <string>
#include <map>
#include "Minefield.h"

Minefield::Cell Minefield::Open(unsigned int x, unsigned int y) {

    return MINE;
}

Minefield::Cell Minefield::GetCellAt(unsigned int x, unsigned int y) const {

    return MINE;
}

Minefield::CellIndex* Minefield::GenerateMinefield(unsigned int width, unsigned int height, unsigned int count) {

    CellIndex* Grid = new CellIndex[width];

    for (unsigned int i = 0; i < width; i++)
    {
        for (unsigned int j = 0; j < height; j++)
        {
            Grid[i+j].Column = i;
            Grid[i+j].Row = j;
            Grid[i+j].Status = GetRandomCellStatus();
            std::string CellString = GetCellAsString(Grid[i+j].Status);
            std::cout << CellString;
        }
        std::cout << "\n";
    }

    return Grid;
}

Minefield::Cell Minefield::GetRandomCellStatus() {

    Cell RandomCell = static_cast<Cell>(rand() % MINE);
    return RandomCell;
}

std::string Minefield::GetCellAsString(Minefield::Cell cell) {
    std::map<Minefield::Cell, std::string> CellToString{
        {EMPTY, "."},
        {M1,"1"},
        {M2,"2"},
        {M3,"3"},
        {M4,"4"},
        {M5,"5"},
        {M6,"6"},
        {M7,"7"},
        {M8,"8"},
        {M9,"9"},
        {MINE,"M"},
        {CLOSED,"CLOSED"}
    };
    return CellToString[cell];
}

Minefield::CellIndex::CellIndex() = default;
