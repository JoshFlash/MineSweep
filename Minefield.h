#ifndef MINESWEEP_MINEFIELD_H
#define MINESWEEP_MINEFIELD_H

class Minefield {
public:
    Minefield() = default;

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

    struct CellIndex
    {
        CellIndex();

        int Row = 0, Column = 0;
        Cell Status = EMPTY;
    };

    int Width;
    int Height;

    Cell Open(unsigned int x, unsigned int y);
    Cell GetCellAt(unsigned int x, unsigned int y) const;

    CellIndex* GenerateMinefield(unsigned int width, unsigned int height, unsigned int count);

    Cell GetRandomCellStatus();

    std::string GetCellAsString(Cell cell);

    int GetEmptyRandomIndex(unsigned int i, CellIndex **pIndex);
};


#endif //MINESWEEP_MINEFIELD_H
