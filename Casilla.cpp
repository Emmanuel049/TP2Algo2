
#include "Casilla.h"

Casilla::Casilla(unsigned int x, unsigned int y,unsigned int z, TipoDeCasilla tipoCasilla, Ficha ficha){
	if(x<=0){
		throw "x deben ser numeros enteros mayores que 0";
	}
	if(y<=0){
			throw "y deben ser numeros enteros mayores que 0";
		}
	if(z<=0){
			throw "z deben ser numeros enteros mayores que 0";
		}
	this->x=x;
	this->y=y;
	this->z=z;
	this->tipo=tipoCasilla;
	this->estado=Vacio;
	this->ficha=ficha;
}
EstadoDeCasilla Casilla::getEstado() const {
	return this->estado;
}

void Casilla::setEstado(EstadoDeCasilla estado) {
	this->estado = estado;
}

TipoDeCasilla Casilla::getTipo() const {
	return this->tipo;
}

void Casilla::setTipo(TipoDeCasilla tipo) {
	this->tipo = tipo;
}

unsigned int Casilla::getX() const {
	return this->x;
}

unsigned int Casilla::getY() const {
	return this->y;
}

unsigned int Casilla::getZ() const {
	return this->z;
}
void Casilla::vaciar(EstadoDeCasilla estado){
	if (this->ficha==Vacia){
		throw "Debe haber una ficha en la casilla par poder moverla";
	}
	this->estado=estado;
	this->ficha=Vacia;
}

Ficha Casilla::getFicha() const {
	return this->ficha;
}

void Casilla::setFicha(Ficha ficha) {
	if (this->estado==Inactivo){
		throw" No se puede colocar una ficha en una casilla con estado inactivo";
	}else if (this->estado==Ocupado){
		throw" No se puede colocar una ficha en una casilla con estado ocupado";
	}
	if(ficha==Vacia){
		throw "Para inicializarla la ficha debe ser distinta que Vacia";
	}
	this->ficha = ficha;
}

