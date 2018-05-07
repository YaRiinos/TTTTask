CCX=g++ -std=c++11


a.out: Board.o Coordinate.o Element.o IllegalCharException.o IllegalCoordinateException.o
		$(CCX) main.cpp *.o
		
Board.o: Board.cpp Board.h
		$(CCX) -c Board.cpp
		
Coordinate.o: Coordinate.cpp Coordinate.h
		$(CCX) -c Coordinate.cpp
		
Element.o: Element.cpp Element.h
		$(CCX) -c Element.cpp

# Symbol.o: Symbol.h
# 		$(CCX) -c Symbol.h

IllegalCharException.o: IllegalCharException.cpp
		$(CCX) -c IllegalCharException.cpp

IllegalCoordinateException.o: IllegalCoordinateException.cpp
		$(CCX) -c IllegalCoordinateException.cpp
		
Clean:
		rm *.o a.out
