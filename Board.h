//
// Created by yarin665 on 04/05/18.
//

#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include <iostream>
#include <vector>
#include "Element.h"
#include "Coordinate.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"

using namespace std;

class Board
{
private:
    vector<vector<Element> > board;
    int boardSize;
public:
    void setBoardSize(int boardSize);

public:
    Board();
    Board(int size);
    ~Board();

    int size()const;

    friend ostream& operator<<(ostream& os, const Board& obj);

    Board& operator=(const Board& obj);
    Board& operator=(const char newVal);
    Element& operator [](Coordinate index);

    char operator[] (Coordinate c) const {
        if (c.getRow()>=boardSize || c.getRow()<0 || c.getCol()>=boardSize || c.getCol()<0)
            throw IllegalCoordinateException{c};
        return board[c.getRow()][c.getCol()];
    }

    bool full();

};
#endif //TICTACTOE_BOARD_H
