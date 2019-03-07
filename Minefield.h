#ifndef MINESWEEP_MINEFIELD_H
#define MINESWEEP_MINEFIELD_H

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
        Cell** GridArr;

        unsigned int Height;
        unsigned int Width;

        CellGrid(unsigned int height, unsigned int width) {

            Height = height;
            Width = width;

            GridArr = new Cell*[height];
            for(int i = 0; i < height; ++i) {
                GridArr[i] = new Cell[width];
            }
        }

        ~CellGrid()
        {
            for(int i = 0; i < Height; ++i) {
                delete [] GridArr[i];
            }
            delete [] GridArr;
        }
    };

    Cell Open(unsigned int x, unsigned int y);
    Cell GetCellAt(unsigned int x, unsigned int y) const;

    Cell GetRandomCellStatus();

};


#endif //MINESWEEP_MINEFIELD_H
