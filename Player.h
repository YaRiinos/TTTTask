#ifndef TTTTASK_MASTER_PLAYER_H
#define TTTTASK_MASTER_PLAYER_H

#include "Board.h"


class Player {
public:
    char myChar;

    virtual const string name() const=0;
    virtual const Coordinate play(const Board& board)=0;
    char getChar()const {return myChar;}
};

#endif //TTTTASK_MASTER_PLAYER_H
