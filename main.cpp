/*
 * main.cpp
 *
 *  Created on: May 14, 2022
 *      Author: algo2
 */

#include <iostream>
#include "Lista.h"
#include "Tablero.h"

int main(){
	Tablero * miTablero=new Tablero(2,5,5);
	miTablero->getCasilla(2,3,2)->setFicha(Avion);
	miTablero->getCasilla(1,3,2)->setFicha(Barco);
	miTablero->printTablero();
	delete miTablero
	return 0;
}


