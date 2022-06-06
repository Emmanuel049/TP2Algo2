#include "Jugador.h"
#include "Ficha.h"

#include <iostream>

Jugador::Jugador(unsigned int numJugador){
    this->cantSoldados = 0;
    this->numJugador = numJugador;
}
Jugador::~Jugador(){
    this->cantSoldados = 0;
    this->numJugador = 0;
}
void Jugador::setNumJugador(unsigned int num){
    this->numJugador = num;
}
void Jugador::eliminarSoldado(){
    this->cantSoldados--;
}
unsigned int Jugador::getNumJugador(){
    return this->numJugador;
}
unsigned int Jugador::getCantSoldados(){
    return this->cantSoldados;
}
void Jugador::setCantSoldados(unsigned int soldados){
    this->cantSoldados = soldados;
}