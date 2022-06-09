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
	int cantidadFichas;
	int cantidadCartas;
	
public:
	
	/*
	* pre: identificador debe ser mayor o igual a 1. Nombre no puede estar vacio
	* pos: Crea el jugador con un id, nombre y lista de fichas vacia.
	*/
	Jugador(int identificador, std::string nombre);

	Jugador(int identificador);
	/*
	* pre: no tiene
	* pos: Devuelve el nombre del jugador
	*/
	std::string obtenerNombre();

	/*
	* pre: no tiene
	* pos: Devuelve el identificador del jugador
	*/	
	unsigned int obtenerId();

	/*
	* pre: el nuevo nombre no debe estar vacio
	* pos: Cambia el nombre del jugador
	*/
	void modificarNombre(std::string);


	/*
	* pre: el nuevo ID no debe ser menor a 1
	* pos: Cambia el identificador del jugador
	*/
	void modificarId(unsigned int);

	
	/*
	* pre: no tiene 
	* pos: Agrega una ficha en la cantidad de Fichas 
	*/
	void agregarFicha();


	/*
	* pre: No tiene 
	* pos: suma 1 en la cantidad de cartas 
	*/
	void levantarCarta();

	/*
	* pre: No tiene
	* pos: Disminuye en 1 cantidad de fichas 
	*/
	void eliminarFicha();


	/*
	* pre: No tiene 
	* pos: disminuye en 1 la cantidad de cartas 
	*/
	void eliminarCarta();
    
    /*
	* pre: Jugador debe estar inicializado
	* pos:Devuelve la cantidad de Fichas del jugador
	*/
    unsigned int getCantidadFichas();
    /*
	* pre:-
	* pos:Iguala la cantidad de fichas al numero pasado por parametro
	*/
    void setCantidadFichas(unsigned int soldados);

	/*
	* pre: No tiene 
	* pos:Setea el jugador a id = 0,  nombre vacio y delete listas
	*/
	void eliminar();

};

#endif /* JUGADOR_H_  */
