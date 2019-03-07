#ifndef MINESWEEP_MINEFIELD_H
#define MINESWEEP_MINEFIELD_H

#include <stdlib.h>

class Minefield {
public:
    Minefield(unsigned int height, unsigned int width) {

            Height = height;
            Width = width;

            Grid = new Cell[height*width];
    };
    ~Minefield() {
        delete [] Grid;
    };

    enum Cell {
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

    Cell* Grid;

    unsigned int Height;
    unsigned int Width;

    size_t Index(int row, int col) const { return row + Width * col; };
    Cell GetCellAt(unsigned int x, unsigned int y) const { return Grid[x + Width * y]; };

    Cell Open(unsigned int x, unsigned int y);

    Cell GetRandomCellStatus();

};


#endif //MINESWEEP_MINEFIELD_H
