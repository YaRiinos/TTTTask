#include "IllegalCharException.h"


char IllegalCharException::theChar() const{
    return ch;
}

//Function for setting value in ch.
void IllegalCharException::setCh(const char& c){
    this->ch=c;
}