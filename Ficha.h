#ifndef FICHA_H_
#define FICHA_H_

#ifndef NULL
#define NULL 0
#endif /* NULL */

#include "Jugador.h"

enum TipoFicha{
	Soldado,
	Avion,
	Barco
};

enum EstadoFicha{
	Activa,
	Eliminada
};

class Ficha {
private:

	TipoFicha tipo;
	Jugador *jugador;
	EstadoFicha estado;
public:
	/*
	 * pre: el jugador no debe estar vacio
	 * pos: Inicializa una ficha asignandole su tipo y el jugador dueño de la misma
	 */
	Ficha(TipoFicha tipo, Jugador *jugador, EstadoFicha estado);
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
	 * pre:
	 * pos: Devuelve el estado de la ficha
	 */
	EstadoFicha getEstado() const;
	/*
	 * pre:
	 * pos: cambia el estado de la ficha
	 */
	void setEstado(EstadoFicha estado);
	/*
	 * pre: la ficha debe estar con estado activa
	 * pos: Elimina la ficha
	 */
	void Eliminar();
};

#endif /* FICHA_H_ */
