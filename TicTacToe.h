//
// Created by yarin665 on 21/05/18.
//

#ifndef TTTTASK_MASTER_TICTACTOE_H
#define TTTTASK_MASTER_TICTACTOE_H

#include <iostream>
using namespace std;
#include <vector>
#include "Board.h"
#include "Player.h"
#include "Coordinate.h"
#include "DummyPlayers.h"
#include <typeinfo>


class TicTacToe {
    Board gameBoard;
    Player* xPlayer;
    Player* oPlayer;
    int boardSize;
    char win;
    char turn;



public:
    TicTacToe(int size):
            gameBoard(size),
            boardSize(size),
            win('-') {}

    void play(Player& xPlayer, Player& oPlayer);

    bool rowIsFull(char charP);
    bool colIsFull(char charP);
    bool firstDiagonalIsFull(char charP);
    bool secondDiagonalIsFull();

    bool checkWinner(Player &thePlayer);


    const Board& board() const {
        return gameBoard;
    }

    const Player& winner() const;

    void setWinner(char w){ this -> win = w;}
    void setTurn(char turn){ this->turn = turn;}
    int getBoardSize() const{ return this->boardSize;}
    char getWinner() const{ return this->win;}
    char getTurn() const{ return this->turn;}
};

#endif //TTTTASK_MASTER_TICTACTOE_H
