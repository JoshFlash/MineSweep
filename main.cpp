#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include <time.h>
#include "Minefield.h"

using Cell = Minefield::Cell;

Minefield* GenerateMinefield(unsigned int width, unsigned int height, unsigned int count);
void GetRandomIndex(int height, int width, int& row, int& column);
bool SolveMinefieldGame(Minefield* MinefieldGame);
void MarkAdjacentMines(Minefield* MinefieldGame, Cell currentCell, int row, int col);

int main()
{
    int width = 18;
    int height = 9;
    int count = 10;

    Minefield* MinefieldGame = GenerateMinefield(width, height, count);

    MinefieldGame->PrintMinefield();

    MinefieldGame->PrintGameField();

    bool didWin = SolveMinefieldGame(MinefieldGame);

    std::cout << "did win: " << didWin << std::endl;


    return 0;
}

Minefield* GenerateMinefield(unsigned int width, unsigned int height, unsigned int count)
{
    // generate random seed
    srand(time(NULL));

    // initialize a minefield where all cells are empty
    Minefield* NewMinefield = new Minefield(height, width);
    for (unsigned int i = 0; i < height; i++)
    {
        for (unsigned int j = 0; j < width; j++)
        {
            NewMinefield->Grid[NewMinefield->Index(i, j)] = Cell::EMPTY;
            NewMinefield->GameField[NewMinefield->Index(i, j)] = Cell::CLOSED;
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
        int row;
        int col;
        GetRandomIndex(height, width, row, col);

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
                    if (NewMinefield->IsCellOnGrid(row + m, col + n))
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

void GetRandomIndex(int height, int width, int& row, int& column)
{
    row = rand() % height;
    column = rand() % width;
}

bool SolveMinefieldGame(Minefield* MinefieldGame)
{
    unsigned int width = MinefieldGame->Width;
    unsigned int height = MinefieldGame->Height;

    int closedCells;;
    int x, y;
    Cell openCell = Cell::EMPTY;

    do {
        // get random closed cell
        do {
            GetRandomIndex(height, width, x, y);
            openCell = MinefieldGame->GameField[MinefieldGame->Index(x, y)];

        } while (openCell != Cell::CLOSED);

        openCell = MinefieldGame->Open(x, y);

        MinefieldGame->PrintGameField();

        closedCells = 0;
        // check for known mines
        for (unsigned int row = 0; row < height; row++)
        {
            for (unsigned int col = 0; col < width; col++)
            {
                Cell currentCell = MinefieldGame->GameField[MinefieldGame->Index(row, col)];
                if (currentCell != Cell::CLOSED)
                {
                    MarkAdjacentMines(MinefieldGame, currentCell, row, col);
                }
                else
                {
                    // open safe closed cells
                    for (int m = -1; m <= 1; m++)
                    {
                        for (int n = -1; n <= 1; n++)
                        {
                            if (MinefieldGame->IsCellOnGrid(row + m, col + n)) 
                            {
                                if (MinefieldGame->GameField[MinefieldGame->Index(row + m, col + n)] == Cell::EMPTY)
                                {
                                    MinefieldGame->Open(row, col);
                                }
                            }
                        }
                    }
                }
            }
        }

        // Get closed cell count after marking mines and opening safe cells
        for (unsigned int row = 0; row < height; row++)
        {
            for (unsigned int col = 0; col < width; col++)
            {
                Cell currentCell = MinefieldGame->GameField[MinefieldGame->Index(row, col)];
                if (currentCell == Cell::CLOSED)
                {
                    closedCells++;
                }
            }
        }

    } while (openCell != Cell::MINE && closedCells > 0);

    // if there are no closed cells and we haven't opened a mine cell, we win!
    return closedCells == 0;
}

void MarkAdjacentMines(Minefield* MinefieldGame, Cell currentCell, int row, int col)
{
    int adjacentClosedCells = 0;
    for (int m = -1; m <= 1; m++)
    {
        for (int n = -1; n <= 1; n++)
        {
            if (MinefieldGame->IsCellOnGrid(row + m, col + n)) 
            {
                if (MinefieldGame->GameField[MinefieldGame->Index(row + m, col + n)] == Cell::CLOSED)
                {
                    adjacentClosedCells++;
                }
            }
        }
    }
    if (adjacentClosedCells == (int)currentCell)
    {
        for (int m = -1; m <= 1; m++)
        {
            for (int n = -1; n <= 1; n++)
            {
                if (MinefieldGame->IsCellOnGrid((int)row + m, (int)col + n)) 
                {
                    if (MinefieldGame->GameField[MinefieldGame->Index(row + m, col + n)] == Cell::CLOSED)
                    {
                        //assign mine but do not open it
                        MinefieldGame->GameField[MinefieldGame->Index(row + m, col + n)] = Cell::MINE;
                    }
                }
            }
        }
    }
}