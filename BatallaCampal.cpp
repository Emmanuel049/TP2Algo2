#include "BatallaCampal.h"
#include <iostream>


/*  
    comentario: el constructor es vacío, pues quienes piden la memoria para son los escenarios 123.
    pre: nada
    post: devuelve un puntero a un TDA BatallaCampal sin inicializar sus atributos.
*/
BatallaCampal::BatallaCampal(){
}

/*
    pre: debe estar creado el objeto Batalla Campal
    post: destruye el TDABatallaCampal, incluyendo todos sus array dinámicos y el tablero.
*/

void BatallaCampal::vaciarBatallaCampal(){
    for( unsigned int x = 1 ; x <= xmax ; x++ ){
        for( unsigned int y = 1 ; y <= ymax ; y++ ){
            for ( unsigned int z = 1 ; z <= zmax ; z++){
                if( this->tablero->getCasilla(x, y, z)->getEstado() == Ocupado ){
                    delete this->tablero->getCasilla(x, y, z)->getFicha();
                }
            }
        } 
    }
    for(unsigned int i = 1 ; i <= this->nJugadores ; i++){
        delete this->jugadores->obtener(i);
    }
    delete this->jugadores;
    this->tablero->eliminarTablero();
    delete this->tablero;
}

/*
    comentario: tiene el menú para el tipo de mapa, según la elección carga el escenario.
    pre: debe estar creado el Objeto.
    post: modifica el tipo de casillero en cada punto del tablero. 
*/

void BatallaCampal::elegirYCargarMapa(){
    unsigned int num;
    std::cout << "Bienvenido al juego de Batalla Campal." << std::endl;
    std::cout << "Por favor, elija el mapa ingresando un número del menú." << std::endl;
    std::cout << "   1. Oceano" << std::endl; // nivel 1 agua, resto de los niveles aire
    std::cout << "   2. Territorio" << std::endl; // nivel 1 tierra, resto de los niveles aire.
    std::cout << "   3. Costa" << std::endl; // nivel 1 mezcla entre tierra y agua, resto de los niveles aire.
    std::cin >> num;
    while( (num <= 0) || (num > 3) ){
        std::cout << "El número ingresado es incorrecto, elija nuevamente" << std::endl;
        std::cin >> num;
    }
    std::cout << "Usted eligió el mapa " << num << std::endl;
    if( num == 1 ){
        this->cargarEscenarioUno(xmax, ymax, zmax);
    } else {
        if ( num == 2 ){
            this->cargarEscenarioDos(xmax, ymax, zmax);
        } else {
            this->cargarEscenarioTres(xmax, ymax, zmax);
        }
    }
    this->tablero->printTableroTipos();
}

/*
    comentario: carga la cantidad de jugadores elegidas por los usuarios, minimo 2 maximo 6.
    pre: debe estar creado el objeto Batalla Campal.
    post: carga los jugadores.
*/

void BatallaCampal::cargarJugadores(){
    unsigned int num;
    std::cout << "Ingrese la cantidad de jugadores entre 2 y 6 " << std::endl;
    std::cin >> num;
    while( (num <= 1) || (num > 6) ){
        std::cout << "Número incorrecto, elija nuevamente" << std::endl;
        std::cin >> num;
    }
    this->nJugadores = num;
    this->jugadoresRestantes = num;

    this->jugadores = new Array <Jugador*> (this->nJugadores);

    for(unsigned int i = 1 ; i <= this->nJugadores ; i++){
        this->jugadores->agregar(i, new Jugador(i));
    }
}


/*
    comentario: este método carga todo lo necesario para que luego se pueda empezar a jugar. 
    pre: debe estar creado el objeto Batalla Campal.
    post: Inicializa todos los atributos según las decisión de los jugadores.
*/

void BatallaCampal::inicializar(){
    
    this->elegirYCargarMapa();
    this->cargarJugadores();         
    
    for(unsigned int i = 1 ; i <= this->nJugadores ; i++){
        setearPosIniciales(this->jugadores->obtener(i));
    }
    
    for(unsigned int i = 1 ; i <= this->nJugadores ; i++){
        std::cout << "JUGADOR " << this->jugadores->obtener(i)->getNumJugador() << ". Este es la posición inicial de sus soldados: " << std::endl;
        this->tablero->printTableroFichas(this->jugadores->obtener(i)->getNumJugador());
    }                                    

}

/*
    comentario: crea y designa soldados de manera aleatoria en el tablero. Recibe el tablero y el num de jugador.
    pre: debe existir el objeto BatallaCampal
    post: deja posicionado los soldados en el tablero.
*/

void BatallaCampal::setearPosIniciales(Jugador* numJugador){
    int x, y, z;
    for( unsigned int i = 0 ; i < msoldados ; ){
        x = rand() % (xmax) + 1;   
        y = rand() % (ymax) + 1;   
        z = rand() % (zmax) + 1;   

        if( this->tablero->getCasilla(x, y, z)->getEstado() == Vacio ){
            this->tablero->getCasilla(x, y, z)->setFicha(new Ficha(Soldado, numJugador));
            this->tablero->getCasilla(x, y, z)->setEstado(Ocupado);
            i++;
        }
    }
    numJugador->setCantSoldados(msoldados);
}


/*
    comentario: MAPA OCEANO, nivel 1 agua resto aire. Este método llama al creador de tablero que genera los casilleros vacíos. Según el tipo de escenario se asignan los tipos de casillero.
    No hace falta validar los maximos porque lo hace el constructor de Tablero.
    pre: debe existir el objeto BatallaCampal
    post: crea el escenario uno con las dimensiones y tipos de casilla indicadas.
*/
void BatallaCampal::cargarEscenarioUno(unsigned int xmax, unsigned int ymax, unsigned int zmax){

    this->tablero = new Tablero(xmax, ymax, zmax);
    // Validar con try - catch la memoria

    for( unsigned int x = 1 ; x <= xmax ; x++ ){
        for( unsigned int y = 1 ; y <= ymax ; y++ ){
            for ( unsigned int z = 1 ; z <= zmax ; z++){
                if( x == 1 )
                    this->tablero->getCasilla(x,y,z)->setTipo(Agua);
                else{
                    this->tablero->getCasilla(x,y,z)->setTipo(Aire);
                }
                this->tablero->getCasilla(x,y,z)->setEstado(Vacio);
            }
        }
    }


}

/*
    comentario: MAPA TERRITORIO, nivel 1 tierra resto aire. Este método llama al creador de tablero que genera los casilleros vacíos. Según el tipo de escenario se asignan los tipos de casillero.
    No hace falta validar los maximos porque lo hace el constructor de Tablero.
    pre: debe existir el objeto BatallaCampal
    post: crea el escenario uno con las dimensiones y tipos de casilla indicadas.
*/
void BatallaCampal::cargarEscenarioDos(unsigned int xmax, unsigned int ymax, unsigned int zmax){

    this->tablero = new Tablero(xmax, ymax, zmax);
    // Validar con try - catch la memoria

    for( unsigned int x = 1 ; x <= xmax ; x++ ){
        for( unsigned int y = 1 ; y <= ymax ; y++ ){
            for ( unsigned int z = 1 ; z <= zmax ; z++){
                if( x == 1 )
                    this->tablero->getCasilla(x,y,z)->setTipo(Tierra);
                else{
                    this->tablero->getCasilla(x,y,z)->setTipo(Aire);
                }
                this->tablero->getCasilla(x,y,z)->setEstado(Vacio);
            }
        }
    }
}

/*
    comentario: MAPA COSTA, nivel 1 mezcla resto aire. Este método llama al creador de tablero que genera los casilleros vacíos. Según el tipo de escenario se asignan los tipos de casillero.
    No hace falta validar los maximos porque lo hace el constructor de Tablero.
    pre: debe existir el objeto BatallaCampal
    post: crea el escenario uno con las dimensiones y tipos de casilla indicadas.
*/
void BatallaCampal::cargarEscenarioTres(unsigned int xmax, unsigned int ymax, unsigned int zmax){

    this->tablero = new Tablero(xmax, ymax, zmax);
    // Validar con try - catch la memoria

    for( unsigned int x = 1 ; x <= xmax ; x++ ){
            for( unsigned int y = 1 ; y <= ymax ; y++ ){
                for ( unsigned int z = 1 ; z <= zmax ; z++){
                    if ( x == 1 ){
                        if( y < z ){
                            this->tablero->getCasilla(x,y,z)->setTipo(Tierra);
                        } else{
                            this->tablero->getCasilla(x,y,z)->setTipo(Agua);
                        }
                    } else {
                        this->tablero->getCasilla(x,y,z)->setTipo(Aire);
                    }
                    this->tablero->getCasilla(x,y,z)->setEstado(Vacio);
                }
            }
    }

}

/*
    comentario: 
    pre: debe existir el objeto Batalla Campañ
    post: devuelve el idJugador ganador de la partida.
*/

unsigned int BatallaCampal::obtenerGanador(){
    for( unsigned int i = 1 ; i <= this->nJugadores ; i++ ){
        if( this->jugadores->obtener(i)->getCantSoldados() != 0 )
            return i;
    }
    return 0;
}

/*
    comentario: este método tiene el algoritmo que ejecuta un disparo de un jugador.
    pre: debe existir el objeto Batalla Campal y el puntero a jugador debe existir y ser distinto de NULL.
    post: ejecuta el disparo según las reglas del juego.
*/
void BatallaCampal::ejecutarDisparo(Jugador* jugador){
    unsigned int x, y, z;

    while( this->tablero->leerCoordenadas(x, y, z) == false ){
        std::cout << "Las coordenadas ingresadas no forman parte del tablero, ingresar nuevas." << std::endl;
    }         

    if ( (this->tablero->getCasilla(x, y, z)->getEstado() == Inactivo) || (this->tablero->getCasilla(x, y, z)->getEstado() == Vacio) ){
        std::cout << "Usted ha disparado a una casilla Inactiva o Vacía, el disparo no tiene ningún efecto." << std::endl;
    } else {
        if ( this->tablero->getCasilla(x, y, z)->getFicha()->getJugador() == jugador ){
            std::cout << "Usted ha disparado a una casilla que posee un soldado o armamento de su ejército, el disparo no tiene efecto" << std::endl;
        } else {
            if( this->tablero->getCasilla(x, y, z)->getFicha()->getTipo() == Soldado ){
                std::cout << "Usted ha eliminado un soldado del jugador "<< this->tablero->getCasilla(x, y, z)->getFicha()->getJugador()->getNumJugador() << "!" << std::endl;
                this->tablero->getCasilla(x, y, z)->getFicha()->getJugador()->eliminarSoldado();
                if ( this->tablero->getCasilla(x, y, z)->getFicha()->getJugador()->getCantSoldados() == 0 ){
                    std::cout << "El jugador "<< this->tablero->getCasilla(x, y, z)->getFicha()->getJugador()->getNumJugador() << " ha perdido todos sus soldados y fue eliminado del juego." << std::endl;
                    this->jugadoresRestantes--;
                }
            } else {
                std::cout << "Usted ha eliminado un armanento enemigo!" << std::endl;
            }
            delete this->tablero->getCasilla(x, y, z)->vaciar(Inactivo);
        }
    }
}

/*
    comentario: verifica la factibilidad de movimientos entre casillas aledañas (horizontal, vertical, diagonal)
    pre: ninguna, la validación de si las coordenadas iniciales o finales están dentro del tablero se hace en el método moverFicha.
    post: devuelve true si el movimiento se puede hacer, false en caso contrario.
*/

bool BatallaCampal::verificarMovimiento(unsigned int xi, unsigned int yi, unsigned int zi, unsigned int xf, unsigned int yf, unsigned int zf){
    if( xf < (xi-1) || xf > (xi+1) )
        return false;
    if( yf < (yi-1) || yf > (yi+1) )
        return false;
    if( zf < (zi-1) || zf > (zi+1) )
        return false;
    return true;
} 

/*
    comentario: mueve una ficha (soldado o armamento) de un casillero a otro, con las reglas del juego.
    pre: jugador debe ser un puntero a TDA Jugador, distinto de NULL
    post: realiza el movimiento según las reglas del juego.
*/
void BatallaCampal::moverFicha(Jugador* jugador){
    unsigned int xi, yi, zi, xf, yf, zf;    
    while( this->tablero->leerCoordenadas(xi, yi, zi) == false ){
        std::cout << "Las coordenadas ingresadas no forman parte del tablero, ingresar nuevas." << std::endl;
    }

    while( this->tablero->getCasilla(xi, yi, zi)->getEstado() == Inactivo || this->tablero->getCasilla(xi, yi, zi)->getEstado() == Vacio || this->tablero->getCasilla(xi, yi, zi)->getFicha()->getJugador() != jugador ){
        std::cout << "Esa casilla está vacía, inactiva o la ficha no le pertenece. Ingrese nuevas coordenadas" << std::endl;
        while( this->tablero->leerCoordenadas(xi, yi, zi) == false ){
            std::cout << "Las coordenadas ingresadas no forman parte del tablero, ingresar nuevas." << std::endl;
        }
    }

    if ( this->tablero->getCasilla(xi, yi, zi)->getFicha()->getTipo() == Avion && this->tablero->getCasilla(xi, yi, zi)->getTipo() == Aire ){
        std::cout << "Acaba de seleccionar un avión en el aire, antes de realizar el movimiento debe utilizar el armamento." << std::endl;
        this->beneficioAvion(jugador);
    } else {
            if ( this->tablero->getCasilla(xi, yi, zi)->getFicha()->getTipo() == Avion && this->tablero->getCasilla(xi, yi, zi)->getTipo() == Agua ){
                std::cout << "Acaba de seleccionar un barco en el agua, antes de realizar el movimiento debe utilizar el armamento." << std::endl;
                this->beneficioBarco(jugador);
            } else {
                std::cout << "Acaba de seleccionar un soldado o un armamento que no puede atacar" << std::endl;
            }
    }

    std::cout << "Ahora elija la posición adonde quiere moverlo." << std::endl;
    while( this->tablero->leerCoordenadas(xf, yf, zf) == false ){
        std::cout << "Las coordenadas ingresadas no forman parte del tablero, ingresar nuevas." << std::endl;
    }

    while( verificarMovimiento(xi, yi, zi, xf, yf, zf) == false ){
        std::cout << "Este movimiento es inválido ya que las posiciones inicial y final deben ser aledañas, elija nueva posición destino." << std::endl;
        while( this->tablero->leerCoordenadas(xf, yf, zf) == false ){
            std::cout << "Las coordenadas ingresadas no forman parte del tablero, ingresar nuevas." << std::endl;
        }
    }

    if( this->tablero->getCasilla(xf, yf, zf)->getEstado() == Inactivo ){
            std::cout << "Esta casilla está inactiva, usted pierde el movimiento" << std::endl;
    } else {
        if( this->tablero->getCasilla(xf, yf, zf)->getEstado() == Vacio ){
                this->tablero->getCasilla(xf, yf, zf)->setFicha(this->tablero->getCasilla(xi, yi, zi)->getFicha());
                this->tablero->getCasilla(xi, yi, zi)->vaciar(Vacio);
                this->tablero->getCasilla(xf, yf, zf)->setEstado(Ocupado);
                std::cout << "Se realizó el movimiento" << std::endl;
        } else {
            if( this->tablero->getCasilla(xf, yf, zf)->getFicha()->getJugador() == jugador ){
                std::cout << "En esta posición ya tiene un soldado o armamento, usted pierde el movimiento" << std::endl;
            } else {
                std::cout << "¡Aquí había un soldado o armamento enemigo! Ambos pierden la ficha" << std::endl;
                if( this->tablero->getCasilla(xi, yi, zi)->getFicha()->getTipo() == Soldado ){
                    this->tablero->getCasilla(xi, yi, zi)->getFicha()->getJugador()->eliminarSoldado();
                }
                if( this->tablero->getCasilla(xf, yf, zf)->getFicha()->getTipo() == Soldado ){
                    this->tablero->getCasilla(xf, yf, zf)->getFicha()->getJugador()->eliminarSoldado();
                }

                delete this->tablero->getCasilla(xi, yi, zi)->vaciar(Inactivo);
                delete this->tablero->getCasilla(xf, yf, zf)->vaciar(Inactivo);

                if ( this->tablero->getCasilla(xi, yi, zi)->getFicha()->getJugador()->getCantSoldados() == 0 ){
                    std::cout << "El jugador "<< this->tablero->getCasilla(xi, yi, zi)->getFicha()->getJugador()->getNumJugador() << " ha perdido todos sus soldados y fue eliminado del juego." << std::endl;
                    this->jugadoresRestantes--;
                }
                if ( this->tablero->getCasilla(xf, yf, zf)->getFicha()->getJugador()->getCantSoldados() == 0 ){
                    std::cout << "El jugador "<< this->tablero->getCasilla(xf, yf, zf)->getFicha()->getJugador()->getNumJugador() << " ha perdido todos sus soldados y fue eliminado del juego." << std::endl;
                    this->jugadoresRestantes--;
                }
            }
        }
    }
}

/*
    comentario: ejecuta el beneficio de un barco en el agua.
    pre: debe existir jugador y ser distinto de NULL
    post: realiza el beneficio del barco en el agua.
*/
void BatallaCampal::beneficioBarco(Jugador* jugador){
    std::cout << "Un barco en el agua permite realizar el disparo de un misil." << std::endl;
    dispararMisil(jugador);
}

/*
    comentario: ejecuta el beneficio de un avión en el aire.
    pre: debe existir jugador y ser distinto de NULL
    post: realiza el beneficio del avión en el aire.
*/
void BatallaCampal::beneficioAvion(Jugador* jugador){
    std::cout << "Un avión en el aire permite realizar dos nuevos disparos adicionales a los del turno." << std::endl;
    ejecutarDisparo(jugador);
    ejecutarDisparo(jugador);
}

/*
    comentario: chequea si el cubo elegido por el jugador entra o no en el tablero.
    pre: ninguna, la validación de las coordenadas en el tablero se hace fuera de este método, en dispararMisil.
    post: devuelve true si el centro del cubo seleccionado por el jugador es factible para el tablero actual.
*/

bool BatallaCampal::verificarCentroCubo(unsigned int &a, unsigned int &b, unsigned int &c){
    std::cout << "Ingrese el valor del eje vertical x (altura): ";
    std::cin >> a;
    std::cout << "Ingrese el valor del eje profundidad y: ";
    std::cin >> b;
    std::cout << "Ingrese el valor del eje horizontal z: ";
    std::cin >> c;
    if( a < 2 || a > (xmax - 1) )
        return false;
    if( b < 2 || b > (ymax - 1) )
        return false;
    if( c < 2 || c > (zmax - 1) )
        return false;
    return true;
}


/*
    comentario: 
    pre: jugador debe existir y ser distinto de NULL.
    post: realiza el disparo del misil en un cubo de 3x3x3 dentro del tablero. Según las reglas del juego.
*/
void BatallaCampal::dispararMisil(Jugador* jugador){
    unsigned int xc, yc, zc;
    std::cout << "Elija las coordenadas que definen el centro del cubo a destruir" << std::endl;
    while( verificarCentroCubo(xc, yc, zc) == false ){
        std::cout << "Coordenadas erróneas, el cubo no entra en el tablero. Ingrese nuevamente." << std::endl;
    }
    for(unsigned int x = xc-1 ; x <= xc + 1 ; x ++){
        for(unsigned int y = yc-1 ; y <= yc + 1 ; y ++){
            for(unsigned int z = zc-1 ; z <= zc + 1 ; z ++){
                if( this->tablero->getCasilla(x, y, z)->getEstado() == Vacio || this->tablero->getCasilla(x, y, z)->getEstado() == Inactivo ){
                
                } else {
                    if ( this->tablero->getCasilla(x, y, z)->getFicha()->getTipo() == Soldado ){
                        this->tablero->getCasilla(x, y, z)->getFicha()->getJugador()->eliminarSoldado();
                        if ( this->tablero->getCasilla(x, y, z)->getFicha()->getJugador()->getCantSoldados() == 0 ){
                            std::cout << "El jugador "<< this->tablero->getCasilla(x, y, z)->getFicha()->getJugador()->getNumJugador() << " ha perdido todos sus soldados y fue eliminado del juego." << std::endl;
                            this->jugadoresRestantes--;
                        }
                    }
                    delete this->tablero->getCasilla(x, y, z)->vaciar( Inactivo );
                }  
            }
        }
    }
}



/*
    comentario: random para dar la carta al jugador al inicio de su turno.
    pre: el objeto BatallaCampal debe estar creado
    post: devuelve el TipoCarta que recibe el jugador
*/
TipoCarta BatallaCampal::tomarCarta(){
    unsigned int num = rand() % (qCartas-1) + 0;
    return (TipoCarta)num;
}

/*
    comentario: 
    pre: debe existir BatallaCampal y ya estar inicializado.
    post: realiza los turnos de todo el juego hasta que uno de todos los jugadores gane.
*/
void BatallaCampal::jugar(){
    
    while( this->jugadoresRestantes > 1 ){
        for( unsigned int i = 1 ; i <= this->nJugadores ; i++){
            if( this->jugadores->obtener(i)->getCantSoldados() != 0 ){
                std::cout << "JUGADOR " << i << ": es su turno. Mucha suerte." << std::endl;
                this->turnoDeJugador = i;
                this->desarrollarTurno(this->jugadores->obtener(i));
            }
        }      
    }
    
    if( this->jugadoresRestantes == 0 ){
        std::cout << "Ningún jugador ha ganado." << std::endl;
    } else {
        std::cout << "El jugador número " << this->obtenerGanador() << " ha ganado la batalla. Felicitaciones!!" << std::endl;
    }
}

/*
    comentario: este método recibe un jugador y un tipo de carta levantado por ese jugador. Solicita posición al jugador para colocar la ficha dada por la carta en el tablero.
    pre: jugador debe existir y ser distinto de NULL. carta debe ser una de las cartas disponibles por el juego.
    post: realiza el posicionamiento del armamento en el tablero.
*/

void BatallaCampal::colocarArmamentoCarta(Jugador* jugador, TipoCarta carta){
    std::cout << "Ingrese las coordenadas donde quiere depositar la ficha." << std::endl;
    std::cout << "Recordar que es conveniente depositar los aviones en casilleros de aire y los barcos en casilleros de agua." << std::endl;
    unsigned int x, y, z;
    while( this->tablero->leerCoordenadas(x, y, z) == false ){
        std::cout << "Las coordenadas ingresadas no forman parte del tablero, ingresar nuevas." << std::endl;
    }

    while( this->tablero->getCasilla(x, y, z)->getEstado() == Inactivo || this->tablero->getCasilla(x, y, z)->getEstado() == Ocupado ){
        std::cout << "Esa casilla está ocupada o inactiva, ingrese nuevas coordenadas." << std::endl;
        while( this->tablero->leerCoordenadas(x, y, z) == false ){
            std::cout << "Las coordenadas ingresadas no forman parte del tablero, ingresar nuevas." << std::endl;
        }
    }

    if( carta == CartaAvion ){
        this->tablero->getCasilla(x, y, z)->setFicha(new Ficha(Avion, jugador));
        this->tablero->getCasilla(x, y, z)->setEstado(Ocupado);
    }

    if( carta == CartaBarco ){
        this->tablero->getCasilla(x, y, z)->setFicha(new Ficha(Barco, jugador));
        this->tablero->getCasilla(x, y, z)->setEstado(Ocupado);
    }
}

/*
    comentario: 
    pre: jugador debe existir y ser distinto de NULL
    post: este método es el paso a paso de un turno completo para un jugador, toma de carta, disparo, movimiento, uso de carta, muestra de su ejército.
*/

void BatallaCampal::desarrollarTurno(Jugador* jugador){
    TipoCarta carta = Ninguna;
    unsigned int idTurnoActual = jugador->getNumJugador();

    std::cout << "JUGADOR " << idTurnoActual << ": Levante una carta del mazo, la utilizará al final del turno." << std::endl;

    std::cout << "JUGADOR " << idTurnoActual << ": Dispare a una posición del tablero ingresando sus coordenadas." << std::endl;
    this->ejecutarDisparo(jugador);
    
    std::cout << "JUGADOR " << idTurnoActual << ": Elija las coordenadas del soldado o armamento a utilizar/mover." << std::endl;
    this->moverFicha(jugador);

    carta = this->tomarCarta();
    if( carta == CartaMisil ){
        std::cout << "JUGADOR " << idTurnoActual << ": La carta recibida es un misil." << std::endl;
        dispararMisil(jugador);
    } else {
        if( carta == CartaAvion ){
            std::cout << "JUGADOR " << idTurnoActual << ": La carta recibida es de Avión." << std::endl;
            colocarArmamentoCarta(jugador, carta); 
            std::cout << "JUGADOR " << idTurnoActual << ": En el próximo turno podrá hacer uso de este armamento." << std::endl;
        } else {
            std::cout << "JUGADOR " << idTurnoActual << ": La carta recibida es de Barco." << std::endl;
            colocarArmamentoCarta(jugador, carta); 
            std::cout << "JUGADOR " << idTurnoActual << ": En el próximo turno podrá hacer uso de este armamento." << std::endl;
        }
    }
    std::cout << "JUGADOR " << jugador->getNumJugador() << ": Este es su ejército actual: " << std::endl;
    this->tablero->printTableroFichas(jugador->getNumJugador());
    
}
