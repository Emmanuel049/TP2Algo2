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
		* pre: jugador debe existir y ser distinto de NULL. Objeto ficha debe estar inicializado
		* pos: asigna el jugador a la ficha
		*/
		void setJugador(Jugador* jugador);
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
		* pre: la ficha debe estar inicializada
		* pos: Elimina la ficha
		*/
		~Ficha();

};

#endif /* FICHA_H_ */

