
#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include <time.h>
#include "Minefield.h"

Minefield::Cell Minefield::Open(unsigned int x, unsigned int y) {

    return MINE;
}

Minefield::Cell Minefield::GetRandomCellStatus() {

    return static_cast<Cell>(rand() % MINE);
}