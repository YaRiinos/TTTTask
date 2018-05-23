CCX=g++ -std=c++11


a.out: Board.o Coordinate.o Element.o IllegalCharException.o IllegalCoordinateException.o TicTacToe.o Player.o DummyPlayers.o Champion.o
		$(CCX) main.cpp *.o 
		
Board.o: Board.cpp Board.h
		$(CCX) -c Board.cpp
		
Coordinate.o: Coordinate.cpp Coordinate.h
		$(CCX) -c Coordinate.cpp
		
Element.o: Element.cpp Element.h
		$(CCX) -c Element.cpp

IllegalCharException.o: IllegalCharException.cpp
		$(CCX) -c IllegalCharException.cpp

IllegalCoordinateException.o: IllegalCoordinateException.cpp
		$(CCX) -c IllegalCoordinateException.cpp

TicTacToe.o: TicTacToe.cpp TicTacToe.h
		$(CCX) -c TicTacToe.cpp

Player.o: Player.cpp Player.h
		$(CCX) -c Player.cpp

DummyPlayers.o: DummyPlayers.cpp DummyPlayers.h
		$(CCX) -c DummyPlayers.cpp
		
Champion.o: Champion.cpp Champion.h
		$(CCX) -c Champion.cpp		

Clean:
		rm *.o a.out
