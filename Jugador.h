#ifndef JUGADOR_H_
#define JUGADOR_H_

#ifndef NULL
#define NULL 0
#endif /* NULL */

#include <string>

class Jugador{
private:

	unsigned int identificador; //numero de jugador
	std::string nombre;
	int cantidadfichas;
	int CantidadCartas;
	
public:
	
	/*
	* pre: identificador debe ser mayor o igual a 1. Nombre no puede estar vacio
	* post: Crea el jugador con un id, nombre y lista de fichas vacia.
	*/
	Jugador(int identificador, std::string nombre);


	/*
	* pre: no tiene
	* post: Devuelve el nombre del jugador
	*/
	std::string obtenerNombre();

	/*
	* pre: no tiene
	* post: Devuelve el identificador del jugador
	*/	
	unsigned int obtenerId();

	/*
	* pre: el nuevo nombre no debe estar vacio
	* post: Cambia el nombre del jugador
	*/
	void modificarNombre(std::string);


	/*
	* pre: el nuevo ID no debe ser menor a 1
	* post: Cambia el identificador del jugador
	*/
	void modificarId(unsigned int);

	
	/*
	* pre: no tiene 
	* post: Agrega una ficha en la cantidad de Fichas 
	*/
	void agregarFicha();


	/*
	* pre: No tiene 
	* post: suma 1 en la cantidad de cartas 
	*/
	void levantarCarta();

	/*
	* pre: No tiene
	* post: Disminuye en 1 cantidad de fichas 
	*/
	void quitarFicha();


	/*
	* pre: No tiene 
	* post: disminuye en 1 la cantidad de cartas 
	*/
	void quitarCarta();

	/*
	* pre: No tiene 
	* post:Setea el jugador a id = 0,  nombre vacio y delete listas
	*/
	void eliminar();

};

#endif /* JUGADOR_H_  */
