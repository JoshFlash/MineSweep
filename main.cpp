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

    Minefield* MF = GenerateMinefield(5, 6, 3);

    return 0;
}

Minefield* GenerateMinefield(unsigned int width, unsigned int height, unsigned int count)
{
    // generate random seed
    srand(time(NULL));

    // initialize a minefield where all cells are empty
    Minefield* GeneratedMineField = new Minefield(height, width);
    for (unsigned int i = 0; i < width; i++)
    {
        for (unsigned int j = 0; j < height; j++)
        {
            GeneratedMineField->Grid[GeneratedMineField->Index(i, j)] = Cell::EMPTY;
        }
    }

    // we cannot have more mines than cells
    if (count > width * height)
    {
        count = width * height;
    }

    // assign mines to random cells and calculate adjacent cell status
    for (unsigned int k = 0; k < count; k++)
    {
        int x = rand() % width;
        int y = rand() % height;

        GeneratedMineField->Grid[GeneratedMineField->Index(x, y)] = Cell::MINE;

        for (int m = -1; m <= 1; m++ )
        {
            for (int n = -1; n <= 1; n++ )
            {
                if ( x + m >= 0 && y + n >= 0 && (x + m) <  width && (y + n) < height )
                {
                    GeneratedMineField->IncrementCellStatus(
                            GeneratedMineField->Grid[GeneratedMineField->Index(x + m, y + n)]);
                }
            }
        }
    }

    for (unsigned int i = 0; i < width; i++)
    {
        for (unsigned int j = 0; j < height; j++)
        {
            std::cout << GeneratedMineField->CellToChar[GeneratedMineField->GetCellAt(i,j)];
        }
        std::cout << '\n';
    }

    return GeneratedMineField;
}