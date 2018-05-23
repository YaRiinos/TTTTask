//
// Created by yarin665 on 21/05/18.
//

#ifndef TTTTASK_MASTER_CHAMPION_H
#define TTTTASK_MASTER_CHAMPION_H


#include "Player.h"


class Champion: public Player {
public:
    const string name() const override { return "Yarin Knafo, Eran Arviv, Maor Cohen"; }
    const Coordinate play(const Board& board) override;

};



#endif //TTTTASK_MASTER_CHAMPION_H
