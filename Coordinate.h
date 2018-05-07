//
// Created by yarin665 on 04/05/18.
//

#ifndef TICTACTOE_COORDINATE_H
#define TICTACTOE_COORDINATE_H

class Coordinate
{
private:
    int row, col;
public:
    Coordinate();
    Coordinate(int newRow, int newCol);

    ~Coordinate();

    int getRow() const;

    int getCol() const;

};



#endif //TICTACTOE_INDEX_H
