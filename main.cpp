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
    std::cout << "Start\n" << std::endl;

    Minefield* MF = GenerateMinefield(18, 9, 12);

    return 0;
}

Minefield* GenerateMinefield(unsigned int width, unsigned int height, unsigned int count)
{
    // generate random seed
    srand(time(NULL));

    // initialize a minefield where all cells are empty
    Minefield* GeneratedMineField = new Minefield(height, width);
    for (unsigned int i = 0; i < height; i++)
    {
        for (unsigned int j = 0; j < width; j++)
        {
            GeneratedMineField->Grid[GeneratedMineField->Index(i, j)] = Cell::EMPTY;
        }
    }

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
        if (GeneratedMineField->Grid[GeneratedMineField->Index(row, col)] != Cell::MINE)
        {
            GeneratedMineField->Grid[GeneratedMineField->Index(row, col)] = Cell::MINE;
            unassignedMines--;

            // increment the 8 adjacent cells **note: when called on the mine cell (m = n = 0) IncrementCellStatus does nothing**
            for (int m = -1; m <= 1; m++)
            {
                for (int n = -1; n <= 1; n++)
                {
                    if (row + m >= 0 && col + n >= 0 && (row + m) < height && (col + n) < width)     // check the cell is on the grid
                    {
                        GeneratedMineField->IncrementCellStatus(
                                GeneratedMineField->Grid[GeneratedMineField->Index(row + m, col + n)]);
                    }
                }
            }
        }

    } while (unassignedMines > 0);

    // print out the Minefield
    for (unsigned int i = 0; i < height; i++)
    {
        for (unsigned int j = 0; j < width; j++)
        {
            std::cout << GeneratedMineField->CellToChar[GeneratedMineField->GetCellAt(i,j)];
        }
        std::cout << '\n';
    }

    return GeneratedMineField;
}