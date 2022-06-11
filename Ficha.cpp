#include "Ficha.h"

Ficha::Ficha(TipoFicha tipo, Jugador *jugador){
	if (jugador == NULL){
		throw "El jugador no puede estar vacio";
	}
	this->tipo = tipo;
	this->jugador = jugador;

}

TipoFicha Ficha::getTipo(){
	return this->tipo;
}

Jugador* Ficha::getJugador(){
	return this->jugador;
}

Ficha::~Ficha(){
	this->jugador = NULL;
}

void Ficha::setJugador(Jugador* jugador){
	this->jugador = jugador;
}
