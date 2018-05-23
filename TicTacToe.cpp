#include "TicTacToe.h"


void TicTacToe::play(Player &xPlayer, Player &oPlayer) {

    this->setTurn('X');
    this->gameBoard = '.';
    xPlayer.myChar = 'X';
    oPlayer.myChar = 'O';

    this->xPlayer = &xPlayer;
    this->oPlayer = &oPlayer;


    int countX = 0, countO = 0;
    Coordinate coordinate;
    Coordinate c{0,0};

    do{
        //X turn
        if(this->getTurn() == 'X'){
            if(typeid(*this->xPlayer) == typeid(ExceptionPlayer)){
                setWinner('O');
                break;
            }
            coordinate = xPlayer.play(this->gameBoard);

            //illigal player
            if(gameBoard[coordinate] != '.'){
                setWinner('O');
                break;
            }
            this->gameBoard[coordinate] = 'X';
            countX++;
            //check win
            if(countX >= getBoardSize()){
                if (this->checkWinner(xPlayer)){
                    setWinner('X');
                    break;
                }
                else if((countX+countO) == (getBoardSize()*getBoardSize())){
                    setWinner('O');
                    break;
                }

            }

            setTurn('O');
        }

            //O turn
        else{
            if(typeid(*this->oPlayer) == typeid(ExceptionPlayer)){
                setWinner('X');
                break;
            }

            coordinate = oPlayer.play(this->gameBoard);
            if(gameBoard[coordinate] != '.'){
                setWinner('X');
                break;
            }

            gameBoard[coordinate] = 'O';
            countO++;

            if(countO >= getBoardSize()){
                if (this->checkWinner(oPlayer)){
                    setWinner('O');
                    break;
                }
            }
            setTurn('X');
        }
    }while((countO+countX) != (gameBoard.size()*gameBoard.size()));

    if((countO+countX) == (gameBoard.size()*gameBoard.size())){
        setWinner('O');
    }
}
//
bool TicTacToe::checkWinner(Player &thePlayer) {

    if(rowIsFull(thePlayer.myChar))
        return true;

    if(colIsFull(thePlayer.myChar))
        return true;

    if(firstDiagonalIsFull(thePlayer.myChar))
        return true;

    if(secondDiagonalIsFull())
        return true;



}



bool TicTacToe::rowIsFull(char charP) {
    for (int i = 0; i <  this -> gameBoard.size() ; i++){
        bool same = true;
        for (int j = 1; j < this -> gameBoard.size(); j++){
            if ((this->gameBoard[{i,0}] != this->gameBoard[{i,j}]) || (gameBoard[{i,0}] == '.' )){
                same = false;
                break;
            }
        }

        if(same){
            return true;
        }
    }
    return false;


}

bool TicTacToe::colIsFull(char charP) {
    for (int j = 0; j < this->getBoardSize(); j++){
        bool same = true;
        for (int i = 1; i < this -> getBoardSize(); i++){
            if ((gameBoard[{0,j}] != gameBoard[{i,j}]) || (gameBoard[{0,j}] == '.' )){
                same = false;
                break;
            }
        }

        if(same){
            return true;

        }
    }
    return false;


}

bool TicTacToe::firstDiagonalIsFull(char charP) {
    bool same = true;
    for (int i = 1; i < this->getBoardSize(); i++){
        if (gameBoard[{0,0}] != gameBoard[{i,i}]){
            same = false;
            break;
        }
    }
    if(same){
        return true;
    }
    return false;

}

bool TicTacToe::secondDiagonalIsFull() {

    bool same = true;
    for (int i = 1; i < this->getBoardSize(); i++){
        if (gameBoard[{0,this->getBoardSize()-1}] != gameBoard[{i,this->getBoardSize() - i - 1}]){
            same = false;
            break;
        }
    }
    if(same){
        return true;
    }
    return false;
}

const Player &TicTacToe::winner() const {
    if(this->getWinner() == 'X')
        return (*this->xPlayer);
    else
        return (*this->oPlayer);
}
