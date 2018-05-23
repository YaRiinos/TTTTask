#include "Champion.h"

const Coordinate Champion::play(const Board& board){

	if(this->myChar == 'X'){//we start
		for (uint x=0; x<board.size(); ++x) {
			Coordinate c{static_cast<int>(x),static_cast<int>(x)};
			if (board[c]=='.') {
				return c;
			}
		}
	}

	else{// O and  the second

		int j = board.size()-2;

		Coordinate c{1,j};

		if(board[c] == '.'){
			return c;
		}

		if (board[{0,1}] == 'X'){
			for (uint i = 0; i < board.size(); ++i) {
				Coordinate c{static_cast<int>(i),static_cast<int>(board.size()-i-1)};
				if (board[c] == '.') {
					return c;
				}
			}

		}

		else if(board[{1,0}] == 'X' ){
			for(uint i=board.size()-1; i >= 0; i--){
				Coordinate c{static_cast<int>(i),static_cast<int>(board.size()-1-i)};
				if (board[c]=='.') {
					return c;
				}
			}
		}

	}
	return {0,0};  // did not find an empty square - play on the top-left



}
