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

    size_t Index(int x, int y) const { return x + Width * y; };
    Cell GetCellAt(unsigned int x, unsigned int y) const { return Grid[Index(x,y)]; };

    Cell Open(unsigned int x, unsigned int y);

    Cell GetRandomCellStatus();

};


#endif //MINESWEEP_MINEFIELD_H
