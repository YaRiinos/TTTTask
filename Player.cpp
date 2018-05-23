//
// Created by yarin665 on 21/05/18.
//
#include "Player.h"

const Coordinate Player::play(const Board &board) {
    return Coordinate();
}

char Player::getChar() const {
    return myChar;
}

void Player::setMyChar(char myChar) {
    Player::myChar = myChar;
}

Player &Player::operator=(const Player &obj) {
    playerName=obj.playerName;
    myChar=obj.myChar;

    return *this;
}