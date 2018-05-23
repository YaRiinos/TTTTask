//
// Created by yarin665 on 04/05/18.
//

#ifndef TICTACTOE_ILLEGALCHAREXCEPTION_H
#define TICTACTOE_ILLEGALCHAREXCEPTION_H

#include <exception>
using namespace std;

//Class to handle illegal char insertions. Using function 'setCh' by the Board Class '=' operator function.
class IllegalCharException:public exception{
    char temp;

public:
    const char* theChar() const throw ();
    void setCh(char);
};
#endif //TICTACTOE_ILLEGALCHAREXCEPTION_H
