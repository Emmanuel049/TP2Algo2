#include <iostream>
#include "Lista.h"
#include "Tablero.h"

int main(){
	Tablero * miTablero=new Tablero(2,5,5);
	Jugador * jugador;
	miTablero->getCasilla(2,3,2)->setFicha(Ficha(Avion, jugador));
	miTablero->getCasilla(1,3,2)->setFicha(Ficha(Barco, jugador));
	miTablero->printTablero();
	delete miTablero;
	return 0;
}

