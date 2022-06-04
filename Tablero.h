#ifndef TABLERO_H_
#define TABLERO_H_
#include "Lista.h"
#include "Casilla.h"

#ifndef NULL
#define NULL 0
#endif /* NULL */

class Tablero {
private:
	Lista<Lista<Lista<Casilla *>*>*> *casilleros;
	unsigned int xMaximo;
	unsigned int yMaximo;
	unsigned int zMaximo;
public:
	/*
	 * Pre:Las dimensiones deben ser igual o mayor a 1
	 * Pos:Se crea un tablero de las dimenciones dadas con todos los casilleros vacios
	 */
	Tablero(unsigned int xMaximo,unsigned int yMaximo,unsigned int zMaximo);
	virtual ~Tablero();
	/*
	 * Pre: Las dimensiones deben ser iguales o mayores que 1
	 * Pos: Devuelve el casillero indicado
	 */
	Casilla * getCasilla(unsigned int x,unsigned int y,unsigned int z) ;
	/*
	 * Pre: Las dimension x debe estar inicializada
	 * Pos: Devuelve la dimencion x
	 */
	unsigned int getxMaximo() const;
	/*
	 * Pre: Las dimension y debe estar inicializada
	 * Pos: Devuelve la dimencion y
	 */
	unsigned int geytMaximo() const;
	/*
	 * Pre: Las dimension z debe estar inicializada
	 * Pos: Devuelve la dimencion z
	 */
	unsigned int getzMaximo() const;
	/*
	 * Pre: El tablero debe estar inicializado
	 * Pos: Se imprime el Tablero completo
	 */
	void printTablero();

private:
	/*
	 * Pre:-
 	 * Pos: Si los valores no estan en rango tira una excepcion.
 	 */
	void validarRango(unsigned int x,unsigned int y,unsigned int z);
	/*
	 * Pre:-
 	 * Pos: Si los valores no son enteros mayores o igual que 1 tira una exepcion
 	 */
	void validarParametros(unsigned int x,unsigned int y,unsigned int z);
	/*
	 * Pre:El tablero debe estar inicializado
 	 * Pos: Segun el tipo de ficha que haya en la posicion del tablero imprime su simbolo determinado
 	 */
	void imprimirSimboloPorFicha();
};


#endif /* TABLERO_H_ */
