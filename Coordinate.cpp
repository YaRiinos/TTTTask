#include "Coordinate.h"



Coordinate::Coordinate()
{
    row=0;
    col=0;
}

Coordinate::Coordinate(int newRow, int newCol)
{

    row=newRow;
    col=newCol;
}

int Coordinate::getRow() const {
    return row;
}

int Coordinate::getCol() const {
    return col;
}

Coordinate::~Coordinate()
{
}