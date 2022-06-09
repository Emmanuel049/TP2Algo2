#include "Jugador.h"

Jugador::Jugador(int identificador){
    if(identificador <= 0){
	    throw "Error, id debe ser mayor o igual a 1";
	}
	this->identificador = identificador;
	this->nombre = " - ";
	cantidadFichas = 0;	
	cantidadCartas = 0;
}

Jugador::Jugador(int identificador, std::string nombre)
{
	if(identificador <= 0){
		throw "Error, id debe ser mayor o igual a 1";
	}
	if(nombre == ""){
		throw "el nombre no puede estar vacio";
	}

	this->identificador = identificador;
	this->nombre = nombre;
	cantidadFichas = 0;	
	cantidadCartas = 0;
}


std::string Jugador::obtenerNombre()
{
	return this->nombre;
}


unsigned int Jugador::obtenerId()
{
	return this->identificador;

}

void Jugador::modificarNombre(std::string nuevoNombre)
{
	if(nuevoNombre == ""){
		throw "El nombre no debe estar vacio";
	}
	this->nombre = nuevoNombre;
}

void Jugador::modificarId(unsigned int nuevoId)
{
	if(nuevoId <= 0){
		throw "El id no puede ser menor a 1";
	}
	this->identificador = nuevoId;
}

void Jugador::agregarFicha()
{
	this->cantidadFichas++;
}

void Jugador::levantarCarta()
{
	this->cantidadCartas++;
}

void Jugador::eliminarFicha()
{
	this->cantidadFichas--;
}

void Jugador::eliminarCarta()
{
	this->cantidadCartas--;
}


void Jugador::eliminar()
{
	this->identificador = 0;
	this->nombre = "";
	this->cantidadFichas=0;
	this->cantidadCartas=0;
}

unsigned int Jugador::getCantidadFichas(){
	if (this->identificador<=0){
		throw "No se encuentra inicializado";
	}
   	return this->cantidadFichas;
}

void Jugador::setCantidadFichas(unsigned int soldados){
    this->cantidadFichas = soldados;
}
