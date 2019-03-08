
#include <iostream>
#include <map>
#include "Minefield.h"

Minefield::Cell Minefield::Open(unsigned int x, unsigned int y)
{
    return MINE;
}

void Minefield::IncrementCellStatus(Minefield::Cell &cell)
{
    switch (cell)
    {
        case EMPTY:
            cell = M1;
            break;
        case M1:
            cell = M2;
            break;
        case M2:
            cell = M3;
            break;
        case M3:
            cell = M4;
            break;
        case M4:
            cell = M5;
            break;
        case M5:
            cell = M6;
            break;
        case M6:
            cell = M7;
            break;
        case M7:
            cell = M8;
            break;
        case M8:
            cell = M9;
            break;
        case M9:
        case MINE:
        case CLOSED:
            break;
    }
}

void Minefield::PrintMinefield()
{
    for (unsigned int row = 0; row < Height; row++)
    {
        for (unsigned int col = 0; col < Width; col++)
        {
            std::cout << CellToChar[GetCellAt(row,col)];
        }
        std::cout << '\n';
    }
}
