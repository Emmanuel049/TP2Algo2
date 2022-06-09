all: tp2

tp2: main.o batallacampal.o tablero.o casilla.o ficha.o jugador.o
	g++ -Wall -g main.o BatallaCampal.o Tablero.o Casilla.o Ficha.o Jugador.o -o tp2 -lm

main.o: main.cpp BatallaCampal.h Lista.h
	g++ -Wall -c -g main.cpp

batallacampal.o: BatallaCampal.cpp BatallaCampal.h Tablero.h Array.h Jugador.h
	g++ -Wall -c -g BatallaCampal.cpp

tablero.o: Tablero.cpp Tablero.h Lista.h Casilla.h EasyBMP.h Ficha.h Vector.h
	g++ -Wall -c -g Tablero.cpp

casilla.o: Casilla.cpp Casilla.h Ficha.h
	g++ -Wall -c -g Casilla.cpp

ficha.o: Ficha.cpp Ficha.h Jugador.h
	g++ -Wall -c -g Ficha.cpp

jugador.o: Jugador.cpp Jugador.h
	g++ -Wall -c -g Jugador.cpp
