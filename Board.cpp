#include "Board.h"
using namespace std;

Board::Board()
{
    boardSize = 2;

    Initialize();
}

Board :: Board(Board& other){
    this -> boardSize = other.boardSize;
    this -> board = new Element*[other.boardSize];

    for (int i = 0; i < this->boardSize; ++i){
        this->board[i] = new Element[other.boardSize];
    }
    for(int i = 0; i < this->boardSize; i++){
        for(int j = 0; j < this->boardSize; j++){
            this->board[i][j] = other.board[i][j];
        }
    }
}

Board::Board(int newSize)
{
    this-> boardSize = newSize;
    this -> board = new Element*[this->boardSize];

    for (int i = 0; i < this->boardSize; ++i)
        this->board[i] = new Element[this->boardSize];

    Initialize();
}

Board::~Board()
{del();}


void Board:: del(){  //distructor

    for (int i = 0; i < boardSize; i++){ //free
        delete[] board[i];
    }
    delete[] board;
}

Board& Board::operator=(const Board& obj)
{
    if (this==&obj){
        return *this;
    }

    del();

    boardSize = obj.boardSize;
    board = new Element*[boardSize];
    for (int i = 0; i < boardSize; i++){
        board[i] = new Element[boardSize];
        for (int j = 0; j < boardSize; j++)
            board[i][j] = obj.board[i][j];
    }
    return *this;
}

Board& Board::operator=(char newVal)
{
    if(newVal == '.')
    {
        *this=Board{boardSize};
    }else{
        IllegalCharException ce;
        ce.setCh(newVal);
        throw ce;
    }

    return *this;
}


Element& Board::operator [](Coordinate index)
{
    if(index.getRow() < 0 || index.getCol() < 0 ||
       index.getRow() >= boardSize || index.getCol() >= boardSize){
        IllegalCoordinateException ce{index};
        throw ce;
    }
    return board[index.getRow()][index.getCol()];
}



int Board::size() const {
    return boardSize;
}

bool Board::full() {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if(board[i][j]=='.') return false;
        }
    }

    return true;
}

void Board::setBoardSize(int boardSize) {
    Board::boardSize = boardSize;
}

char Board::operator[](Coordinate c) const {
    if (c.getRow()>=boardSize || c.getRow()<0 || c.getCol()>=boardSize || c.getCol()<0)
        throw IllegalCoordinateException{c};
    return board[c.getRow()][c.getCol()];
}


bool operator== (Board const& x, Board const& y){
    if (x.size()!=y.size())
        return false;

    for (int i = 0; i <x.size() ; ++i) {
        for (int j = 0; j <x.size() ; ++j) {
            if(x[{i,j}]!=y[{i,j}])
                return false;
        }
    }

    return true;
}

bool operator!= (Board const& x, Board const& y){
    if (x.size()!=y.size())
        return true;

    for (int i = 0; i <x.size() ; ++i) {
        for (int j = 0; j <x.size() ; ++j) {
            if(x[{i,j}]!=y[{i,j}])
                return true;
        }
    }

    return false;
}

void Board::Initialize() {
    Element a;
    for (int x = 0; x < this->boardSize; ++x){
        for (int y = 0; y < this->boardSize; ++y){
            this->board[x][y] = a;
        }
    }

}
