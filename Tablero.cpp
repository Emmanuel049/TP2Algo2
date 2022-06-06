#include "Tablero.h"
#include <iostream>
#include <iomanip>

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
	if(x <= 0){
		throw "x deben ser numeros enteros mayores que 0";
	}
	if(y <= 0){
			throw "y deben ser numeros enteros mayores que 0";
		}
	if(z <= 0){
			throw "z deben ser numeros enteros mayores que 0";
		}
	return this->casilleros->get(x)->get(y)->get(z);
}

void Tablero::eliminarTablero(){
	unsigned int x,y,z;
	for ( x = 1 ; x <= this->xMaximo ; x++ ){
			for ( y = 1 ; y <= this->yMaximo; y++ ){
				for ( z = 1 ; z <= this->zMaximo ; z++ ){
							delete this->getCasilla(x, y, z);
				}
				delete this->casilleros->get(x)->get(y);
			}
			delete this->casilleros->get(x);
		}
	delete this->casilleros;
	this->casilleros = NULL;
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

void Tablero::printTableroFichas(unsigned int numJugador){
	unsigned int x,y,z;
	std::cout<<"------------------Ejército Jugador" << numJugador << "--------------" <<std::endl;
	std::cout << "Soldado: " << std::setw(8) << "S" << std::endl;
	std::cout << "Avión: " << std::setw(10) << "A" << std::endl;
	std::cout << "Barco: " << std::setw(10) << "B" << std::endl;
	std::cout << std::endl;
	
	for (x=1;x<=this->xMaximo;x++){
		std::cout << "Altura x = " << x << std::endl;
		
 		std::cout<<"-----------------------------------------"<<std::endl;
	
		for(unsigned int i = 1 ; i <= zMaximo ; i++){
			std::cout << "  " << std::setw(4) << i;
		}
		std::cout << std::endl;
			for (y=1;y<=this->yMaximo;y++){
				std::cout << std::setw(2) << y << "|  " ;
				for ( z=1 ; z <= this->zMaximo ; z++){
					if(this->casilleros->get(x)->get(y)->get(z)->getEstado() == Ocupado){
						if(this->casilleros->get(x)->get(y)->get(z)->getFicha()->getJugador()->getNumJugador() == numJugador){
							if(this->casilleros->get(x)->get(y)->get(z)->getFicha()->getTipo() == Soldado){
								std::cout<<"S"<< numJugador << " |  ";
							} else {
								if(this->casilleros->get(x)->get(y)->get(z)->getFicha()->getTipo() == Avion){
									std::cout<<"A"<< numJugador << " |  ";
								} else {
									if(this->casilleros->get(x)->get(y)->get(z)->getFicha()->getTipo() == Barco){
										std::cout<<"B"<< numJugador << " |  ";
									}
								}
							}
						} else {
							std::cout<<" "<<"  |  ";
						}
					} else{
						if(this->casilleros->get(x)->get(y)->get(z)->getEstado() == Inactivo){
							std::cout<<"X"<<"  |  ";
						} else{
							std::cout<<" "<<"  |  ";
						}
					}
				}
				std::cout << std::endl;
			}
		}
	std::cout<<"-----------------------------------------"<<std::endl<< std::endl;
}

void Tablero::printTableroTipos(){
	unsigned int x,y,z;

	std::cout<<"----------------------Mapa elegido-----------------------"<<std::endl;
	std::cout << "Tierra: " << std::setw(8) << "T" << std::endl;
	std::cout << "Aire: " << std::setw(10) << "A" << std::endl;
	std::cout << "Agua: " << std::setw(10) << "W" << std::endl;
	std::cout << std::endl;
	
	for (x=1;x<=this->xMaximo;x++){
		std::cout << std::setw(20) << "Altura x = " << x << std::endl;
 		std::cout<<"---------------------------------------------------"<<std::endl;
	
		for(unsigned int i = 1 ; i <= zMaximo ; i++){
			std::cout << "  " << std::setw(4) << i;
		}
		std::cout << std::endl;
			for (y=1;y<=this->yMaximo;y++){
				std::cout << std::setw(2) << y << "|  " ;
				for ( z=1 ; z <= this->zMaximo ; z++){
					if( this->getCasilla(x, y, z)->getTipo() == Aire ){
						std::cout<<"A"<<"  |  ";
					} else {
						if ( this->getCasilla(x, y, z)->getTipo() == Agua ){
							std::cout<<"W"<<"  |  ";
						} else {
							std::cout<<"T"<<"  |  ";
						}
					}
				}
				std::cout << std::endl;
			}
		}
	std::cout<<"---------------------------------------------------"<<std::endl<< std::endl;
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

bool Tablero::leerCoordenadas(unsigned int& a, unsigned int& b, unsigned int& c){
	std::cout << "Ingrese el valor del eje vertical x (alto): ";
	std::cin >> a;
	std::cout << "Ingrese el valor del eje profundidad y (ancho): ";
	std::cin >> b;
	std::cout << "Ingrese el valor del eje horizontal z (largo): ";
	std::cin >> c;
	if( ( a > this->xMaximo || a < 1 ) || ( b > this->yMaximo || b < 1 ) || ( c > this->zMaximo || c < 1 ) ){
		return false;
	}
	return true;
}

