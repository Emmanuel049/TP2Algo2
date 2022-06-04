#include "Ficha.h"
#include "Jugador.h"

Ficha::Ficha(TipoFicha tipo, Jugador *jugador, EstadoFicha estado){
	if (jugador == NULL){
		throw "El jugador no puede estar vacio";
	}
	this->tipo=tipo;
	this->jugador=jugador;
	this->estado=estado;

}

TipoFicha Ficha::getTipo(){
	return this->tipo;
}

Jugador* Ficha::getJugador(){
	return this->jugador;
}

EstadoFicha Ficha::getEstado() const{
	return estado;
}

void Ficha::setEstado(EstadoFicha estado){
	this->estado=estado;
}

void Ficha::Eliminar(){
	if (this->estado== Eliminada){
		throw "La ficha ya esta eliminada";
	}
	this->estado=Eliminada;
}

