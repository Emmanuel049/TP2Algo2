#ifndef FICHA_H_
#define FICHA_H_

#include "Jugador.h"

enum TipoFicha{
	Soldado,
	Avion,
	Barco
};


class Ficha {
	private:
		TipoFicha tipo;
		Jugador *jugador; 
	public:
		/*
		* pre: el jugador no debe estar vacio
		* pos: Inicializa una ficha asignandole su tipo y el jugador dueño de la misma
		*/
		Ficha(TipoFicha tipo, Jugador* jugador);
		/*
		* pre:
		* pos: Devuelve el tipo de ficha
		*/
		TipoFicha getTipo();
		/*
		* pre:
		* pos: Devuelve el jugador dueño de la ficha
		*/
		Jugador* getJugador();
		/*
		* pre: la ficha debe estar con estado activa
		* pos: Elimina la ficha
		*/
		~Ficha();

};

#endif /* FICHA_H_ */
