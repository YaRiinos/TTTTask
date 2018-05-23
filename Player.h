//
// Created by yarin665 on 21/05/18.
//

#ifndef TTTTASK_MASTER_PLAYER_H
#define TTTTASK_MASTER_PLAYER_H

#include "Board.h"


class Player {
public:
    virtual const string name() const  { return playerName; }

    virtual const Coordinate play(const Board& board) ;

    char myChar;
    string playerName;
    bool won;

    char getChar() const;

    void setMyChar(char myChar);

    Player& operator=(const Player& obj);
};

#endif //TTTTASK_MASTER_PLAYER_H
