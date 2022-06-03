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
	Tablero * myTablero=new Tablero(2,5,5);
	myTablero->getCasilla(2,3,2)->setFicha(Avion);
	myTablero->getCasilla(1,3,2)->setFicha(Barco);
	myTablero->printTablero();
	return 0;
}


