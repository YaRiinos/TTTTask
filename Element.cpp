#include "Element.h"



Element::Element()
{
    val ='.';
}

Element::Element(char newVal)
{
    if (newVal =='X' || newVal == 'O' || newVal == '.'){
        val = newVal;
    } else{
        IllegalCharException ce;
        ce.setCh(newVal);
        throw ce;
    }
}

Element::~Element(){}

ostream& operator<<(ostream& os, const Element& obj)
{

    return os << obj.val;

}




void Element::operator= (char newVal){
    if (newVal =='X' || newVal == 'O' || newVal == '.'){
        val = newVal;
    } else{
        IllegalCharException ce;
        ce.setCh(newVal);
        throw ce;
    }

}

bool operator== (Element const& x, Element const& y){
    return x.val==y.val;
}
bool operator== (Element const& x, char const& val){
    return x.val==val;
}
bool operator== (char const& val, Element const& x){
    return x.val==val;
}

void Element::setVal(char newVal) {
        Element::val = newVal;
}
