//
// Created by yarin665 on 04/05/18.
//

#ifndef TICTACTOE_ILLEGALCHAREXCEPTION_H
#define TICTACTOE_ILLEGALCHAREXCEPTION_H

#include <exception>
using namespace std;

//Class to handle illegal char insertions. Using function 'setCh' by the Board Class '=' operator function.
class IllegalCharException:public exception{
private:
    char ch;
public:
    //Function for exception throwing, returns the value in ch.
    char theChar() const;

    //Function for setting value in ch.
    void setCh(const char& c);
};
#endif //TICTACTOE_ILLEGALCHAREXCEPTION_H
