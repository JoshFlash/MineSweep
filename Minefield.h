#ifndef MINESWEEP_MINEFIELD_H
#define MINESWEEP_MINEFIELD_H

#include <stdlib.h>
#include <map>

class Minefield
{
public:
    Minefield(unsigned int height, unsigned int width)
    {
        Height = height;
        Width = width;

        Grid = new Cell[width * height * sizeof(Cell)];
        GameField = new Cell[width * height * sizeof(Cell)];
    };

    ~Minefield()
    {
        delete[] Grid;
        delete[] GameField;
    };

    enum Cell
    {
        EMPTY,
        M1,
        M2,
        M3,
        M4,
        M5,
        M6,
        M7,
        M8,
        M9,
        MINE,
        CLOSED
    };

    std::map<Minefield::Cell, char> CellToChar
    {
        {Cell::EMPTY,  '.'},
        {Cell::M1,     '1'},
        {Cell::M2,     '2'},
        {Cell::M3,     '3'},
        {Cell::M4,     '4'},
        {Cell::M5,     '5'},
        {Cell::M6,     '6'},
        {Cell::M7,     '7'},
        {Cell::M8,     '8'},
        {Cell::M9,     '+'},
        {Cell::MINE,   'M'},
        {Cell::CLOSED, '#'}
    };

    Cell* Grid;
    Cell* GameField;

    unsigned int Height;
    unsigned int Width;

    size_t Index(int x, int y) const { return x + Width * y; };

    Cell GetCellAt(unsigned int x, unsigned int y) const { return Grid[Index(x, y)]; };

    Cell Open(unsigned int x, unsigned int y);

    bool IsCellOnGrid(int x, int y) const { return x >= 0 && y >= 0 && x < Height && y < Width; };

    void IncrementCellStatus(Cell &cell);

    void PrintMinefield();

    void PrintGameField();

};


#endif //MINESWEEP_MINEFIELD_H
