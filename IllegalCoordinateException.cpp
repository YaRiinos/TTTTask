//
// Created by yarin665 on 04/05/18.
//

#include "IllegalCoordinateException.h"

//Constructor for IllegalCoordinateException class.
IllegalCoordinateException::IllegalCoordinateException(const Coordinate& index){
    this->index=index;
}

//Function for exception throwing - returns the string printed in the exception throwing.
string IllegalCoordinateException::theCoordinate() const{
    if(numEx!=0){
        string ans=to_string(numEx);
        return ans;
    } else{
        string ans=to_string(index.getRow())+","+to_string(index.getCol());
        return ans;
    }
}

IllegalCoordinateException::IllegalCoordinateException(const int x) {
    this->numEx=x;
}
