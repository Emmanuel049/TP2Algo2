/*
 * Vector
 *
 *  Created on: May 14, 2022
 *      Author: algo2
 */
#include <iostream>
#include <string>
#ifndef VECTOR
#define VECTOR


template<class T> class Vector {
private:
		T * datos;
		unsigned int longitud;

public:

	/**
	 * pre: la longitud es mayor o igual a 1. Y el dato inicial puede ser NULL si es un puntero
	 * pos: deja un vector con las posiciones solicitadas
	 */
	Vector(int longitud, T datoInicial) {
		if (longitud < 1) {
			throw "La longitud debe ser mayor o igual a 1";
		}
		this->datos = new T[longitud];
		this->longitud = longitud;
		for(unsigned int i = 0; i < this->longitud; i++){
			this->datos[i] = datoInicial;
		}
	}
	Vector(int longitud) {
			if (longitud < 1) {
				throw "La longitud debe ser mayor o igual a 1";
			}
			this->datos = new T[longitud];
			this->longitud = longitud;
		}

	/**
	 * pre:
	 * post: libera la memoria
	 */
	virtual ~Vector() {
		delete [] this->datos;
	}

	/**
	 * pre:
	 * post: devuelve la longitud actual del vector
	 */
	unsigned int getLongitud() {
		return this->longitud;
	}

	/**
	 * pre: la posicion esta entre 1 y n (inclusive)
	 * pos: guarda el dato en la posicion indicada, sino devuelve error
	 */
	void agregar(unsigned int posicion, T dato) {
		if ((posicion < 1) ||
		   (posicion > this->longitud)) {
			throw "Posicion no se encuentra en rango determinado";
		}
		this->datos[posicion - 1] = dato;
	}

	/**
	 * pre: la posicion esta entre 1 y n (inclusive)
	 * pos: guarda el dato en la posicion indicada, sino devuelve error
	 */
	T& obtener(unsigned int posicion) {
		if ((posicion < 1) ||
		   (posicion > this->longitud)) {
			throw "Posicion no se encuentra en rango determinado";
		}
		return this->datos[posicion - 1];
	}
};

#endif /* VECTOR_H_ */




