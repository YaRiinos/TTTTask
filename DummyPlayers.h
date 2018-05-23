//
// Created by yarin665 on 21/05/18.
//

#ifndef TTTTASK_MASTER_DUMMYPLAYERS_H
#define TTTTASK_MASTER_DUMMYPLAYERS_H


#include "Player.h"



/*
	This player scans the board looping on x then on y,
	and plays on the first empty cell.
*/
class XYPlayer: public Player {
public:
    const string name() const override { return "XYPlayer"; }
    const Coordinate play(const Board& board) override;
};


/*
	This player scans the board looping on y then on x,
	and plays on the first empty cell.
*/
class YXPlayer: public Player {
public:
    const string name() const override { return "YXPlayer"; }
    const Coordinate play(const Board& board) override;
};


/*
   This player makes illegal moves -
   it tries to override cells of the other player.
   It should always lose.
*/
class IllegalPlayer: public Player {
public:
    const string name() const override { return "YXPlayer"; }
    const Coordinate play(const Board& board) override;
};


/*
	This player always throws an exception.
	It should always lose.
*/
class ExceptionPlayer: public Player {
public:
    const string name() const override { return "YXPlayer"; }
    const Coordinate play(const Board& board) override;
};

#endif //TTTTASK_MASTER_DUMMYPLAYERS_H
