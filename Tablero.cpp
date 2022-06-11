#include "Tablero.h"
#include <iostream>
#include <fstream>
#include "Ficha.h"

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
    	validarRango(x,y,z);
	return this->casilleros->get(x)->get(y)->get(z);
}

void Tablero::eliminarTablero(){
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
	delete this->casilleros;
	this->casilleros = NULL;
}

bool Tablero::leerCoordenadas(unsigned int& a, unsigned int& b, unsigned int& c,unsigned int h, unsigned int i, unsigned int j){
	std::cout << "Ingrese el valor del eje vertical x (alto): ";
	std::cin >> a;
	std::cout << "Ingrese el valor del eje profundidad y (ancho): ";
	std::cin >> b;
	std::cout << "Ingrese el valor del eje horizontal z (largo): ";
	std::cin >> c;
	try{
		validarRango(a,b,c,h,i,j);
		return true;
	}catch(...){
		return false;
	}
}

unsigned int Tablero::getxMaximo() const {
	return this->xMaximo;
}

unsigned int Tablero::getyMaximo() const {
	return this->yMaximo;
}

unsigned int Tablero::getzMaximo() const {
	return this->zMaximo;
}

void Tablero::BMPdeTablero(unsigned int numJugador){
	validarParametros(this->xMaximo,this->yMaximo,this->zMaximo);
	Vector<BMP*>* tablero=new Vector<BMP*>(this->xMaximo);
	inicializarBMP(tablero);
	unsigned int x=1,y=0,z=0;
	this->casilleros->reiniciarCursor();
	while((this->casilleros->avanzarCursor())){
		this->casilleros->getCursor()->reiniciarCursor();
		while((this->casilleros->getCursor()->avanzarCursor())){
			this->casilleros->getCursor()->getCursor()->reiniciarCursor();
			while((this->casilleros->getCursor()->getCursor()->avanzarCursor())){
				Casilla * actual=this->casilleros->getCursor()->getCursor()->getCursor();
				if(actual->getEstado()==Inactivo){
					impresionInactivoBMP(tablero,x,y,z);
				}
				else if(actual->getEstado()==Ocupado){
					if(actual->getFicha()!=NULL){
						impresionFichaBMP(tablero,numJugador,x,y,z);
					}
				}

				else{
					impresionTipoBMP(tablero,x,y,z);
				}
				z++;
			}
			z=0;
			y++;
		}
		y=0;
		x++;

	}
	guradadoEnArchivoBMP(tablero);
}


void Tablero::inicializarBMP(Vector<BMP*>* tablero){
	for(unsigned int i=1;i<this->xMaximo+1;i++){
			tablero->agregar(i,new BMP);
			tablero->obtener(i)->SetSize(this->yMaximo*10,this->zMaximo*10);
			tablero->obtener(i)->SetBitDepth(32);
		}
	return;
}
void Tablero::impresionTipoBMP(Vector<BMP*>* tablero, unsigned int x, unsigned int y, unsigned int z){
	if(this->casilleros->getCursor()->getCursor()->getCursor()->getTipo()==Agua){
		for(unsigned int i=(y)*10;i<10*(y+1);i++){
			for(unsigned int j=(z)*10;j<10*(z+1);j++){
				tablero->obtener(x)->operator ()(i,j)->Green=50;
				tablero->obtener(x)->operator ()(i,j)->Red=50;
			}
		}
	}else if(this->casilleros->getCursor()->getCursor()->getCursor()->getTipo()==Tierra){
		for(unsigned int i=(y)*10;i<10*(y+1);i++){
			for(unsigned int j=(z)*10;j<10*(z+1);j++){
				tablero->obtener(x)->operator ()(i,j)->Blue=30;
				tablero->obtener(x)->operator ()(i,j)->Red=30;
				tablero->obtener(x)->operator ()(i,j)->Green=120;
			}
		}
	}else{
		for(unsigned int i=(y)*10;i<10*(y+1);i++){
			for(unsigned int j=(z)*10;j<10*(z+1);j++){
					tablero->obtener(x)->operator ()(i,j)->Red=200;
			}
	   }
	}
}
void Tablero::impresionFichaBMP(Vector<BMP*>* tablero, unsigned int numJugador,unsigned int x, unsigned int y, unsigned int z){
	if(this->casilleros->getCursor()->getCursor()->getCursor()->getFicha()->getTipo()==Soldado){
		for(unsigned int i=(y)*10;i<10*(y+1);i++){
			for(unsigned int j=(z)*10;j<10*(z+1);j++){
				tablero->obtener(x)->operator ()(i,j)->Green=30;
				tablero->obtener(x)->operator ()(i,j)->Blue=10*(numJugador)+20;
				tablero->obtener(x)->operator ()(i,j)->Red=20*(numJugador)+70;
			}
		}
	}
	else if(this->casilleros->getCursor()->getCursor()->getCursor()->getFicha()->getTipo()==Avion){
		for(unsigned int i=(y)*10;i<10*(y+1);i++){
			for(unsigned int j=(z)*10;j<10*(z+1);j++){
						tablero->obtener(x)->operator ()(i,j)->Green=50+25*(numJugador);
						tablero->obtener(x)->operator ()(i,j)->Blue=25*(numJugador)+50;
						tablero->obtener(x)->operator ()(i,j)->Red=25*(numJugador)+50;
			}
		}
	}
	else if(this->casilleros->getCursor()->getCursor()->getCursor()->getFicha()->getTipo()==Barco){
		for(unsigned int i=(y)*10;i<10*(y+1);i++){
			for(unsigned int j=(z)*10;j<10*(z+1);j++){
				tablero->obtener(x)->operator ()(i,j)->Green=90+20*(numJugador);
				tablero->obtener(x)->operator ()(i,j)->Red=110-10*(numJugador);
				tablero->obtener(x)->operator ()(i,j)->Blue=100;

			}
		}
	}
}

void Tablero::impresionInactivoBMP(Vector<BMP*>* tablero, unsigned int x, unsigned int y, unsigned int z){
	for(unsigned int i=(y)*10;i<10*(y+1);i++){
		for(unsigned int j=(z)*10;j<10*(z+1);j++){
			tablero->obtener(x)->operator ()(i,j)->Blue=50;
			tablero->obtener(x)->operator ()(i,j)->Green=50;
			tablero->obtener(x)->operator ()(i,j)->Red=255;
	    }
    }
}


void Tablero::guradadoEnArchivoBMP(Vector<BMP*>* tablero){
	for(unsigned int i=1;i<this->xMaximo+1;i++){
		if (i==1){
			if(tablero->obtener(i)->WriteToFile("Nivel1.bmp")==false){
				throw "No se pudo guardar primer nivel";
			}
		}
		else if(i==2){
			if(tablero->obtener(i)->WriteToFile("Nivel2.bmp")==false){
				throw "No se pudo guardar segundo nivel";
			}
		}
		else{
			if(tablero->obtener(i)->WriteToFile("Nivel3.bmp")==false){
				throw "No se pudo guardar tercer nivel";
			}
		}
	}
}


unsigned char* Tablero::leerBMP(char* rutaArchivo)
{
	validarParametros(this->xMaximo,this->yMaximo,this->zMaximo);
    FILE* f = fopen(rutaArchivo, "rb");

    if(f == NULL)
        throw "No se pudo leer el archivo";

    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); 
    int ancho = *(int*)&info[18];
    int altura = *(int*)&info[22];

    std::cout << std::endl;
    std::cout << rutaArchivo <<std::endl;
    std::cout << " Ancho: " << ancho << std::endl;
    std::cout << "Alto: " << altura << std::endl;

    int geometria = (ancho*3 + 3) & (~3);
    unsigned char* data = new unsigned char[geometria];
    unsigned char tmp;

    for(int i = 0; i < altura; i++)
    {
        fread(data, sizeof(unsigned char), geometria, f);
        for(int j = 0; j < ancho*3; j += 3)
        {
            // Convierte (B, G, R) a (R, G, B)
            tmp = data[j];
            data[j] = data[j+2];
            data[j+2] = tmp;

            std::cout << "R: "<< (int)data[j] << " G: " << (int)data[j+1]<< " B: " << (int)data[j+2]<< std::endl;
        }
    }

    fclose(f);
    return data;
}

void Tablero::impresionAclaraciones(){
	std::cout << "Casilla inactiva se marca con: " << "X" << std::endl;
	std::cout << "Casilla ocupada por Avion se marca con: " << "A" << std::endl;
	std::cout << "Casilla ocupada por Barco se marca con: " << "B" << std::endl;
	std::cout << "Casilla ocupada por Soldado se marca con: " << "S" << std::endl;
	std::cout << "Casilla Desocupada con territorio agua se marca con: " << " ~"  << std::endl;
	std::cout << "Casilla Desocupada con territorio tierra se marca con: " << " -"  << std::endl;
	std::cout << "Casilla Desocupada con territorio aire se marca con: " << " ' '"  << std::endl;
}


void Tablero::escribirTableroTexto(unsigned int numJugador) {
	validarParametros(this->xMaximo,this->yMaximo,this->zMaximo);
	std::string rutaArchivo="Tablero.txt";
	std::string str=" ";
	std::ofstream tablero;
	unsigned int h=0;
	tablero.open(rutaArchivo.c_str());
	this->casilleros->reiniciarCursor();
	for (unsigned int b=0;b<this->yMaximo;b++){
		str+="      ";
		str +=char(b+65);
	}
	while((this->casilleros->avanzarCursor())){
		tablero<<str<<std::endl;
		tablero << "     —————————————————————————————————————————" << std::endl;
		this->casilleros->getCursor();
		tablero.width(2);
		this->casilleros->getCursor()->reiniciarCursor();
		while(this->casilleros->getCursor()->avanzarCursor()){
			h++;
			tablero.width(2);
			tablero << h << "   ";
			this->casilleros->getCursor()->getCursor()->reiniciarCursor();
			while(this->casilleros->getCursor()->getCursor()->avanzarCursor()){
				Casilla * actual= this->casilleros->getCursor()->getCursor()->getCursor();
				if(actual->getEstado()==Inactivo){
					tablero << "| " << "X" << " ";
				}else if(actual->getEstado()==Ocupado){
					if(actual->getFicha()->getTipo()==Avion){
						tablero<< "| " << "A"<<numJugador << " ";
					}else if(actual->getFicha()->getTipo()==Soldado){
						tablero<< "| " << "S"<<numJugador << " ";}
					else{
						tablero << "| " << "B"<<numJugador << " ";
					}
				}else{
					if(actual->getTipo()==Agua){
						tablero << "| " << " ~" << " ";
					}else if(actual->getTipo()==Tierra){
						tablero << "| " << " -"<< " ";
					}else{
						tablero<< "| " << "'  '" << " ";
					}
				}
			}
			tablero << "|" << std::endl;
			tablero << "     —————————————————————————————————————————" << std::endl;
		}
		h=0;
		tablero << " —————————————————————————————————————————————————————————" << std::endl;
		tablero << " —————————————————————————————————————————————————————————" << std::endl;
	}
	/* cierra el archivo, liberando el recurso */
	tablero.close();
}


void Tablero::leerTableroTexto(std::string rutaArchivo) {
	impresionAclaraciones();
	std::ifstream tablero;
	tablero.open(rutaArchivo.c_str());
	
	
	std::string fila;
	std::getline(tablero, fila);
	std::cout<<fila<<std::endl;

	
	while (! tablero.eof()) {
		if (! tablero.eof()) {
			std::getline(tablero, fila);
			std::cout<<fila<<std::endl;
		}
	}
	tablero.close();
}


void Tablero::impresionFichaTexto(Ficha *ficha, unsigned int numJugador){
	if(ficha->getTipo()==Avion){
		std::cout << "A"<<numJugador;
	}else if(ficha->getTipo()==Soldado){
		std::cout <<"S"<<numJugador;
	}else{
		std::cout << "B"<<numJugador;
	}
	std::cout<<" |  ";
}


void Tablero::impresionTipoTexto(Casilla * actual){
	if( actual->getTipo() == Aire ){
		std::cout<<"A"<<"  |  ";
	} else if ( actual->getTipo() == Agua ){
		std::cout<<"W"<<"  |  ";
	} else {
		std::cout<<"T"<<"  |  ";
	}
}



void Tablero::printTableroFichas(unsigned int numJugador){
	unsigned int x=0;
	unsigned int y=0;
	unsigned int z=0;
	std::cout<<"------------------Ejército Jugador" << numJugador << "--------------" <<std::endl;
	std::cout << "Soldado: ";
	std::cout.width(8);
	std::cout  << "S" << std::endl;
	std::cout << "Avión: " ;
	std::cout.width(10);
	std::cout << "A" << std::endl;
	std::cout << "Barco: ";
	std::cout.width(10);
	std::cout << "B" << std::endl;
	this->casilleros->reiniciarCursor();
	while(this->casilleros->avanzarCursor()){
		std::cout << std::endl;
		x++;
		std::cout << "Altura x = " << x << std::endl;
		
 		std::cout<<"-----------------------------------------"<<std::endl;	
		for(unsigned int i = 1 ; i <= zMaximo ; i++){
			std::cout << "  " ;
			std::cout.width(4);
			std::cout << i;
		}
		std::cout << std::endl;
		this->casilleros->getCursor()->reiniciarCursor();
		while(this->casilleros->getCursor()->avanzarCursor()){
			y++;
			std::cout.width(2);
			std::cout << y << "|  " ;
			this->casilleros->getCursor()->getCursor()->reiniciarCursor();
			while(this->casilleros->getCursor()->getCursor()->avanzarCursor()){
				Casilla * actual=this->casilleros->getCursor()->getCursor()->getCursor();
				z++;
				if(actual->getEstado() == Ocupado){
					if(actual->getFicha()->getJugador()->obtenerId() == numJugador){
						impresionFichaTexto(actual->getFicha(), actual->getFicha()->getJugador()->obtenerId());
					} else {
						std::cout<<" "<<"  |  ";
					}
				} else{
					if(actual->getEstado() == Inactivo){
						std::cout<<"X"<<"  |  ";
					} else{
						std::cout<<" "<<"  |  ";
					}
				}
			}
			z=0;
			std::cout << std::endl;
		}
		y=0;
	}
	std::cout<<"-----------------------------------------"<<std::endl<< std::endl;
}

void Tablero::printTableroTipos(){
	unsigned int x=0;
	unsigned int y=0;
	unsigned int z=0;

	std::cout<<"----------------------Mapa elegido-----------------------"<<std::endl;
	std::cout << "Tierra: ";
	std::cout.width(8);
	std::cout << "T" << std::endl;
	std::cout << "Aire: ";
	std::cout.width(10);
	std::cout << "A" << std::endl;
	std::cout << "Agua: ";
	std::cout.width(10);
	std::cout << "W" << std::endl;
	std::cout << std::endl;
	
	this->casilleros->reiniciarCursor();
	while(this->casilleros->avanzarCursor()){
		x++;
		std::cout.width(20);
		std::cout << "Altura x = " << x << std::endl;
 		std::cout<<"---------------------------------------------------"<<std::endl;
	
		for(unsigned int i = 1 ; i <= zMaximo ; i++){
			std::cout << "  " ;
			std::cout.width(4);
			std::cout << i;
		}
		std::cout << std::endl;
		this->casilleros->getCursor()->reiniciarCursor();
		while(this->casilleros->getCursor()->avanzarCursor()){
			y++;
			std::cout.width(2);
			std::cout << y << "|  " ;
			this->casilleros->getCursor()->getCursor()->reiniciarCursor();
			while(this->casilleros->getCursor()->getCursor()->avanzarCursor()){
				Casilla * actual=this->casilleros->getCursor()->getCursor()->getCursor();
				z++;
				impresionTipoTexto(actual);
			}
			z=0;
			std::cout << std::endl;
		}
		y=0;
	}
	std::cout<<"---------------------------------------------------"<<std::endl<< std::endl;
}

void Tablero::validarRango(unsigned int x,unsigned int y,unsigned int z, unsigned int h, unsigned int i, unsigned int j){
    validarParametros(x,y,z,h,i,j);
    if(x>xMaximo-i){
        std::string str1=" "+this->xMaximo;
        throw  "El x debe ser menor o igual a" + str1;
    }
    if(y>yMaximo-h){
        std::string str1=" " + this->yMaximo;
            throw "El y debe ser menor o igual a" + str1;
    }
    if(z>zMaximo-j){
        std::string str1=" " + this->zMaximo;
            throw "El z debe ser menor o igual a " + str1;
    }
}

void Tablero::validarParametros(unsigned int x,unsigned int y,unsigned int z,unsigned int h, unsigned int i, unsigned int j){
	if(x<1+h){
		throw "x deben ser numeros enteros mayores que 0";
	}
	if(y<1+i){
			throw "y deben ser numeros enteros mayores que 0";
		}
	if(z<1+j){
			throw "z deben ser numeros enteros mayores que 0";
		}
}
