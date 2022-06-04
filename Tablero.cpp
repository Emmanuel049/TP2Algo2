#include "Tablero.h"
#include <iostream>

Tablero::Tablero(unsigned int xMaximo,unsigned int yMaximo,unsigned int zMaximo){
    
    validarParametros(xMaximo,yMaximo,zMaximo);
    
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
    //unsigned int x=1,y=1,z=1;
    this->casilleros->reiniciarCursor();
    while(this->casilleros->avanzarCursor()){
        this->casilleros->getCursor()->reiniciarCursor();
        while(this->casilleros->getCursor()->avanzarCursor()){
            this->casilleros->getCursor()->getCursor()->reiniciarCursor();
            while(this->casilleros->getCursor()->getCursor()->avanzarCursor()){
                delete this->casilleros->getCursor()->getCursor()->getCursor();
            }
            delete this->casilleros->getCursor()->getCursor();
        }
        delete this->casilleros->getCursor();
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
    this->casilleros->reiniciarCursor();
    while(this->casilleros->avanzarCursor()){
        std::cout<<"-------------------------------"<<std::endl;
        this->casilleros->getCursor()->reiniciarCursor();
        while(this->casilleros->getCursor()->avanzarCursor()){
            std::cout<<"|  ";
            this->casilleros->getCursor()->getCursor()->reiniciarCursor();
            while(this->casilleros->getCursor()->getCursor()->avanzarCursor()){
                impresionSimboloPorFicha(this->casilleros->getCursor()->getCursor()->getCursor()->getFicha());
            }
            std::cout<<std::endl;
        }
    }
    std::cout<<"-------------------------------"<<std::endl;
}


void Tablero::validarRango(unsigned int x,unsigned int y,unsigned int z){
    validarParametros(x,y,z);
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

void Tablero::validarParametros(unsigned int x,unsigned int y,unsigned int z){
    if(x<1){
        throw "x deben ser numeros enteros mayores que 0";
    }
    if(y<1){
            throw "y deben ser numeros enteros mayores que 0";
        }
    if(z<1){
            throw "z deben ser numeros enteros mayores que 0";
        }
}
void Tablero::imprimirSimboloPorFicha(Ficha* ficha){
    if(ficha->getTipo()==Soldado){
        std::cout<<"S"<<"  |  ";
    }
    else if(ficha->getTipo()==Avion){
        std::cout<<"A"<<"  |  ";
    }
    else if(ficha->getTipo()==Barco){
        std::cout<<"B"<<"  |  ";
    }
    else{
        std::cout<<" "<<"  |  ";
    }
}
    
