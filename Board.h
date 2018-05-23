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
public:
    Element** board;
    int boardSize;

    void setBoardSize(int boardSize);

    Board();
    Board(Board& ob);
    Board(int size);
    ~Board();

     void Initialize();
    
    int size()const;

    Board& operator=(const Board& obj);
    Board& operator=(char newVal);
    Element& operator [](Coordinate index);
    char operator[] (Coordinate c) const;

    friend bool operator== (Board const& X, Board const& Y);
    friend bool operator!= (Board const& X, Board const& Y);


    bool full();

    void del();
};

inline ostream&  operator<<(ostream& out, const Board& a){
    for(int i = 0; i < a.size();i++){
        for(int j = 0; j < a.size();j++){
            out << a.board[i][j];
        }
        out<<endl;
    }
    return out;
}
#endif //TICTACTOE_BOARD_H
