#include <iostream>
#include "BatallaCampal.h"

int main(){


	BatallaCampal* nuevoJuego = new BatallaCampal();
	nuevoJuego->inicializar();
	nuevoJuego->jugar();
	nuevoJuego->vaciarBatallaCampal();
	delete nuevoJuego;

	return 0;



}

