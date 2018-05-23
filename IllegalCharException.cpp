#include "IllegalCharException.h"


const char* IllegalCharException :: theChar() const throw (){
    const char* ans =  &temp;
    return ans;
}

void IllegalCharException :: setCh(char t){ this ->temp = t;}
