#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include <time.h>
#include "Minefield.h"

using Cell = Minefield::Cell;

Minefield* GenerateMinefield(unsigned int width, unsigned int height, unsigned int count);

int main()
{
    int width = 18;
    int height = 9;
    int count = 12;

    Minefield* MinefieldKey = GenerateMinefield(width, height, count);

    MinefieldKey->PrintMinefield();

    Minefield* MinfieldGame = new Minefield(height, width);
    MinfieldGame->InitializeCellGrid(Cell::CLOSED);

    return 0;
}

Minefield* GenerateMinefield(unsigned int width, unsigned int height, unsigned int count)
{
    // generate random seed
    srand(time(NULL));

    // initialize a minefield where all cells are empty
    Minefield* NewMinefield = new Minefield(height, width);
    NewMinefield->InitializeCellGrid(Cell::EMPTY);

    // we cannot have more mines than cells
    if (count > width * height)
    {
        count = width * height;
    }

    // assign mines to random cells
    int unassignedMines = count;
    do {
        int row = rand() % height;
        int col = rand() % width;

        // skip and get another random index if the cell is already a mine
        if (NewMinefield->Grid[NewMinefield->Index(row, col)] != Cell::MINE)
        {
            NewMinefield->Grid[NewMinefield->Index(row, col)] = Cell::MINE;
            unassignedMines--;

            // increment status of 8 adjacent cells **note: when called on a mine cell IncrementCellStatus does nothing**
            for (int m = -1; m <= 1; m++)
            {
                for (int n = -1; n <= 1; n++)
                {
                    if (row + m >= 0 && col + n >= 0 && (row + m) < height && (col + n) < width) // is cell on the grid
                    {
                        NewMinefield->IncrementCellStatus(
                                NewMinefield->Grid[NewMinefield->Index(row + m, col + n)]);
                    }
                }
            }
        }
    } while (unassignedMines > 0);

    return NewMinefield;
}