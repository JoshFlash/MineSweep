#pragma once

#include <iostream>
#include <string>
#include "Minefield.h"

Minefield* TheMineField;

int main() {
    std::cout << "Start" << std::endl;

    Minefield::CellIndex* CellGrid = TheMineField->GenerateMinefield(7,8,6);

    return 0;
}

