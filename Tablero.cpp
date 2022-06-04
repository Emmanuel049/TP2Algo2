#include "Tablero.h"
#include <iostream>

Tablero::Tablero(unsigned int xMaximo,unsigned int yMaximo,unsigned int zMaximo){
	if (xMaximo<1){
		throw"El parametro x debe ser mayor que 0";
	}
	if (yMaximo<1){
		throw"El parametro y debe ser mayor que 0";
	}
	if (zMaximo<1){
		throw"El parametro z debe ser mayor que 0";
	}
	this->xMaximo=xMaximo;
	this->yMaximo=yMaximo;
	this->zMaximo=zMaximo;
	unsigned int x,y,z;
	this->casilleros = new Lista<Lista<Lista<Casilla *>*>*>();
	for (x=1;x<=this->xMaximo;x++){
		this->casilleros->add(new Lista<Lista<Casilla*>*>(),x);
		for (y=1;y<=this->yMaximo;y++){
			this->casilleros->get(x)->add(new Lista<Casilla*>(),y);
			for (z=1;z<=this->zMaximo;z++){
						this->casilleros->get(x)->get(y)->add(new Casilla(x,y,z, General, NULL),z);
			}
		}
	}
}

Casilla * Tablero::getCasilla(unsigned int x,unsigned int y,unsigned int z) {
	if(x<=0){
		throw "x deben ser numeros enteros mayores que 0";
	}
	if(y<=0){
			throw "y deben ser numeros enteros mayores que 0";
		}
	if(z<=0){
			throw "z deben ser numeros enteros mayores que 0";
		}
	return this->casilleros->get(x)->get(y)->get(z);
}

Tablero::~Tablero(){
	unsigned int x,y,z;
	for (x=1;x<=this->xMaximo;x++){
			for (y=1;y<=this->yMaximo;y++){
				for (z=1;z<=this->zMaximo;z++){
							delete this->casilleros->get(x)->get(y)->get(z);
				}
				delete this->casilleros->get(x)->get(y);
			}
			delete this->casilleros->get(x);
		}
	delete[] this->casilleros;
}

unsigned int Tablero::getxMaximo() const {
	return this->xMaximo;
}

unsigned int Tablero::geytMaximo() const {
	return this->yMaximo;
}

unsigned int Tablero::getzMaximo() const {
	return this->zMaximo;
}

void Tablero::printTablero(){
	unsigned int x,y,z;
	for (x=1;x<=this->xMaximo;x++){
		std::cout<<"-------------------------------"<<std::endl;
			for (y=1;y<=this->yMaximo;y++){
				std::cout<<"|  ";
				for (z=1;z<=this->zMaximo;z++){
					if(this->casilleros->get(x)->get(y)->get(z)->getFicha()==Soldado){
							std::cout<<"S"<<"  |  ";
					}
					else if(this->casilleros->get(x)->get(y)->get(z)->getFicha()==Avion){
						std::cout<<"A"<<"  |  ";
					}
					else if(this->casilleros->get(x)->get(y)->get(z)->getFicha()==Barco){
						std::cout<<"B"<<"  |  ";
					}
					else{
						std::cout<<" "<<"  |  ";
					}
				}
				std::cout<<std::endl;
			}

		}
	std::cout<<"-------------------------------"<<std::endl;
}


void Tablero::validarRango(unsigned int x,unsigned int y,unsigned int z){
	if(x<=0){
		throw "x deben ser numeros enteros mayores que 0";
	}
	if(y<=0){
			throw "y deben ser numeros enteros mayores que 0";
		}
	if(z<=0){
			throw "z deben ser numeros enteros mayores que 0";
		}

	if(x>xMaximo){
		std::string str1=" "+this->xMaximo;
		throw  "El x debe ser menor o igual a" + str1;
	}
	if(y>yMaximo){
		std::string str1=" " + this->yMaximo;
			throw "El y debe ser menor o igual a" + str1;
	}
	if(z>zMaximo){
		std::string str1=" " + this->zMaximo;
			throw "El z debe ser menor o igual a " + str1;
	}
}
