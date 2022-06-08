#include <iostream>
#include "Lista.h"
#include "Tablero.h"
#include "Jugador.h"

int main(){
	Tablero * miTablero=new Tablero(2,5,5);
	Jugador * miJugador=new Jugador(1);
	miTablero->getCasilla(2,3,5)->setFicha(Avion);
	miTablero->getCasilla(1,2,1)->setFicha(Soldado);
	miTablero->getCasilla(1,4,2)->setFicha(Soldado);
	miTablero->getCasilla(1,3,3)->setFicha(Barco);
	std::cout<<miTablero->getxMaximo();
	miTablero->BMPdeTablero(miJugador);
	std::cout<<miTablero->getxMaximo();
	unsigned char* x=miTablero->leerBMP("Nivel1.bmp");
	std::cout<<*x<<std::endl;
	miTablero->escribirTableroTexto();
	miTablero->leerTableroTexto("Tablero.txt");
	delete x;
	delete []myTablero;
	delete miJugador;
	return 0;
}

