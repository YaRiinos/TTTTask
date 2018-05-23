#include "TicTacToe.h"


void TicTacToe::play(Player &xPlayer, Player &oPlayer) {

    //X char for the player who start
    this->setTurn('X');

    //Init the game board
    this->gameBoard = '.';

    //Set chars
    xPlayer.myChar = 'X';
    oPlayer.myChar = 'O';


    this->xPlayer = &xPlayer;
    this->oPlayer = &oPlayer;


    int numOfX = 0, numOfO = 0;
    Coordinate playerMove, c{0,0};

    for (int i = 0; i < boardSize*boardSize; ++i) {
        //X turn
        if(this->getTurn() == 'X'){

            //Check if player gonna do illegal move
            if(typeid(*this->xPlayer) == typeid(ExceptionPlayer)){
                setWinner('O');
                break;
            }

            //Get the player move
            playerMove = xPlayer.play(this->gameBoard);

            //If player try to override another move
            if(gameBoard[playerMove] != '.'){
                setWinner('O');
                break;
            }

            //Put X on his place and increase X counter by 1
            this->gameBoard[playerMove] = 'X';
            numOfX++;

            //Check if win
            if(numOfX >= getBoardSize()){
                if (this->checkWinner(xPlayer)){
                    setWinner('X');
                    break;
                }
                else if((numOfX +numOfO) == (getBoardSize()*getBoardSize())){
                    setWinner('O');
                    break;
                }

            }

            setTurn('O');
        }

            //O turn
        else{

            //Check if player gonna do illegal move
            if(typeid(*this->oPlayer) == typeid(ExceptionPlayer)){
                setWinner('X');
                break;
            }

            //Get player move
            playerMove = oPlayer.play(this->gameBoard);

            //If player try to override another move
            if(gameBoard[playerMove] != '.'){
                setWinner('X');
                break;
            }

            //Put O on his place and increase O counter by 1
            gameBoard[playerMove] = 'O';
            numOfO++;

            if(numOfO >= getBoardSize()){
                if (this->checkWinner(oPlayer)){
                    setWinner('O');
                    break;
                }
            }
            setTurn('X');
        }
    }

    //Check if even, if so then O won
    if((numOfO+numOfX) == (gameBoard.size()*gameBoard.size())){
        setWinner('O');
    }
}


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
    char winnerChar='N';
    for (int i = 0; i < gameBoard.size(); ++i) {
        for (int j=1; j< gameBoard.size(); ++j) {
            if (gameBoard[{i,j}]==gameBoard[{i,j-1}] && gameBoard[{i,j}]!='.'){
                if (j==gameBoard.size()-1){
                    winnerChar=charP;
                }
            }
            else
                break;
        }
    }
    return winnerChar == charP;


}

bool TicTacToe::colIsFull(char charP) {
    char winnerChar='N';
    for (int i = 0; i < gameBoard.size(); ++i) {
        for (int j=1; j< gameBoard.size(); ++j) {
            if (gameBoard[{j,i}]==gameBoard[{j-1,i}] && gameBoard[{i,j}]!='.'){
                if (j==gameBoard.size()-1){
                    winnerChar=charP;
                }
            }
            else
                break;
        }
    }
    return winnerChar == charP;


}

bool TicTacToe::firstDiagonalIsFull(char charP) {
    char winnerChar='N';

    for (int j=1; j< gameBoard.size(); ++j) {
        if (gameBoard[{j,j}]==gameBoard[{j-1,j-1}] && gameBoard[{j,j}]!='.'){
            if (j==gameBoard.size()-1){
                winnerChar=charP;
            }
        }
        else
            break;
    }

    return winnerChar == charP;

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
