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
{Delete();}


void Board:: Delete(){

    for (int i = 0; i < boardSize; i++){
        delete[] board[i];
    }
    delete[] board;
}

Board& Board::operator=(const Board& obj)
{
    if (this==&obj){
        return *this;
    }

    Delete();

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

string Board::draw(int pixel) {

    //Define Img properties
    string fileName = "boardPic.ppm";
    ofstream thePic(fileName, ios::out | ios::binary);
    thePic << "P6" << endl << pixel <<" " << pixel << endl << 255 << endl;

    RGB image[pixel*pixel];

    for (int j = 0; j < pixel; ++j)  {  // row
        for (int i = 0; i < pixel; ++i) { // column
            image[pixel*j+i].red = (255);
            image[pixel*j+i].green = (255);
            image[pixel*j+i].blue = (255);
        }
    }

    //Drawing rows and columns


    //Drawing the columns
    for (int i = 0; i < boardSize; ++i) {

        int Xfrom = i * (pixel/boardSize);

        for (int r = 0; r < pixel ; ++r) {

            image[pixel * (r) + Xfrom].red = (121);
            image[pixel * (r) + Xfrom].green = (160);
            image[pixel * (r) + Xfrom].blue = (40);
        }
    }

    //Drawing the rows
    for (int j = 0; j < boardSize; ++j) {

        int Yfrom = j * (pixel/boardSize) ;

        for (int r = 0; r < pixel ; ++r) {

            image[(r) + Yfrom * pixel].red = (121);
            image[(r) + Yfrom * pixel].green = (160);
            image[(r) + Yfrom * pixel].blue = (40);
        }
    }

    for (int row = 0; row < boardSize; ++row) {
        for (int column = 0; column < boardSize; ++column) {

            int Xfrom = column * (pixel/boardSize);
            int Xto = (column + 1) * (pixel/boardSize);
            int Yfrom = row * (pixel/boardSize) ;
            int Yto = (row + 1) * (pixel/boardSize);

            if (board[row][column] == 'X') {

                //Drawing X
                for (int r = 10; r < Yto - Yfrom - 10 ; ++r) {

                    //Drawing \ diagonal of X
                    image[pixel * (r + Yfrom) + Xfrom + r].red = (44);
                    image[pixel * (r + Yfrom) + Xfrom + r].green = (133);
                    image[pixel * (r + Yfrom) + Xfrom + r].blue = (91);

                    //Drawing / diagonal of X
                    image[pixel * (r + Yfrom) + Xto - (r)].red = (44);
                    image[pixel * (r + Yfrom) + Xto - (r)].green = (133);
                    image[pixel * (r + Yfrom) + Xto - (r)].blue = (91);

                }
            }
            else if(board[row][column] == 'O'){

                int R = (Xto - Xfrom) / 2;
                int Ox = (Xto - Xfrom) / 2;
                int Oy = (Yto - Yfrom) / 2;

                for (int X = 10; X < Yto - Yfrom  ; ++X) {

                    auto Y = static_cast<int>(sqrt(R * R - (X - Ox) * (X - Ox)) + Oy);

                    int attach = 20;

                    //Drawing bottom size of the circle
                    image[pixel * (Y + Yfrom - attach) + Xfrom + X].red = (0);
                    image[pixel * (Y + Yfrom - attach) + Xfrom + X].green = (25);
                    image[pixel * (Y + Yfrom - attach) + Xfrom + X].blue = (15);

                    image[pixel * (Yto - Y + attach) + Xfrom + X].red = (0);
                    image[pixel * (Yto - Y + attach) + Xfrom + X].green = (28);
                    image[pixel * (Yto - Y + attach) + Xfrom + X].blue = (15);

                }
            }
        }
    }

    thePic.write(reinterpret_cast<char*>(&image), 3*pixel*pixel);
    thePic.close();

    return fileName;
}

istream &operator>>(istream &in, Board &X)
{
    int counter=0,tempSize=0;
    char c;
    bool flag = true;
    vector<char> allChars;
    while(cin.get(c)){
        if(flag&&(c=='\n')){
            tempSize = counter;
            flag = false;
        }
        counter++;
        allChars.push_back(c);
    }
    Board temp{tempSize};
    int k = 0;

    for(int i=0;i<temp.size();++i){
        for(int j=0;j<temp.size();++j){
            if(allChars.at(k)!='\n'){
                temp.board[i][j] = allChars.at(k);
            }
            else{
                temp.board[i][j] = allChars.at(++k);
            }
            k++;
        }
    }
    X = temp;
    return in;
}
