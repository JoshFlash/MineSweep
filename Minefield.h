#ifndef MINESWEEP_MINEFIELD_H
#define MINESWEEP_MINEFIELD_H

#include <stdlib.h>

class Minefield {
public:
    Minefield() = default;
    ~Minefield();

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

    struct CellGrid
    {
        Cell* GridArr;

        unsigned int Height;
        unsigned int Width;

        size_t Index( int x, int y ) const { return x + Width * y; }

        CellGrid(unsigned int height, unsigned int width) {

            Height = height;
            Width = width;

            GridArr = new Cell[height*width];
        }

        ~CellGrid()
        {
            delete [] GridArr;
        }
    };

    Cell Open(unsigned int x, unsigned int y);
    Cell GetCellAt(unsigned int x, unsigned int y) const;

    Cell GetRandomCellStatus();

};


#endif //MINESWEEP_MINEFIELD_H
