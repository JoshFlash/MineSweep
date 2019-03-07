#ifndef MINESWEEP_MINEFIELD_H
#define MINESWEEP_MINEFIELD_H

class Minefield {
public:
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

    int Width;
    int Height;

    Cell Open(unsigned int x, unsigned int y);

    Cell GetCellAt(unsigned int x, unsigned int y) const;

    void GenerateMinefield(unsigned int width, unsigned int height, unsigned int count);
};


#endif //MINESWEEP_MINEFIELD_H
