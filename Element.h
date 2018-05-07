//
// Created by yarin665 on 04/05/18.
//

#ifndef TICTACTOE_ELEMENT_H
#define TICTACTOE_ELEMENT_H

#include <iostream>
#include "Coordinate.h"
#include "IllegalCharException.h"

using namespace std;

class Element {

private:
    char val;
public:
    Element();
    Element(char newVal); //check input - throw execption
    ~Element();

    friend ostream& operator<<(ostream& os, const Element& obj);

    // void operator=(const Element& newVal);
    void operator= (char newVal);

    friend bool operator== (Element const& X, Element const& Y);
    friend bool operator== (Element const& x, char const& val);
    friend bool operator== (char const& val, Element const& x);

     operator char() const { return val; }

    void setVal(char val);
};



#endif //TICTACTOE_ELEMENT_H
