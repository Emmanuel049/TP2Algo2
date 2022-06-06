#ifndef DEFINE_BATALLA_CAMPAL
#define DEFINE_BATALLA_CAMPAL

#include "Tablero.h"
#include "Array.h"
#include "Jugador.h"

#include <iostream>

const unsigned int msoldados = 1; // es fijo, depende del juego 100%
const unsigned int xmax = 3; // es fijo, depende del juego 100%
const unsigned int ymax = 10; // es fijo, depende del juego 100%
const unsigned int zmax = 10; // es fijo, depende del juego 100%
const unsigned int qCartas = 3; // es fijo, depende del juego 100%
const unsigned int qEscenarios = 3; // es fijo, depende del juego 100%

enum TipoCarta{
    CartaMisil,
    CartaAvion,
    CartaBarco,
    Ninguna
};

class BatallaCampal{
    private:
        Tablero* tablero; 
        Array <Jugador*> *jugadores; 
        unsigned int turnoDeJugador;
        unsigned int nJugadores;
        unsigned int jugadoresRestantes;

    public:
        /*  
            comentario: el constructor es vacío, pues quienes piden la memoria para son los escenarios 123.
            pre: nada
            post: devuelve un puntero a un TDA BatallaCampal sin inicializar sus atributos.
        */
        BatallaCampal();
        /*
            pre: debe estar creado el objeto Batalla Campal
            post: destruye el TDABatallaCampal, incluyendo todos sus array dinámicos y el tablero.
        */
        void vaciarBatallaCampal();
        /*
            comentario: tiene el menú para el tipo de mapa, según la elección carga el escenario.
            pre: debe estar creado el Objeto.
            post: modifica el tipo de casillero en cada punto del tablero. 
        */
        void elegirYCargarMapa();
        /*
            comentario: carga la cantidad de jugadores elegidas por los usuarios, minimo 2 maximo 6.
            pre: debe estar creado el objeto Batalla Campal.
            post: carga los jugadores.
        */
        void cargarJugadores();
        /*
            comentario: este método carga todo lo necesario para que luego se pueda empezar a jugar. 
            pre: debe estar creado el objeto Batalla Campal.
            post: Inicializa todos los atributos según las decisión de los jugadores.
        */
        void inicializar();
        /*
            comentario: crea y designa soldados de manera aleatoria en el tablero. Recibe el tablero y el num de jugador.
            pre: debe existir el objeto BatallaCampal
            post: deja posicionado los soldados en el tablero.
        */
        void setearPosIniciales(Jugador* numJugador);
        /*
            comentario: MAPA OCEANO, nivel 1 agua resto aire. Este método llama al creador de tablero que genera los casilleros vacíos. Según el tipo de escenario se asignan los tipos de casillero.
            No hace falta validar los maximos porque lo hace el constructor de Tablero.
            pre: debe existir el objeto BatallaCampal
            post: crea el escenario uno con las dimensiones y tipos de casilla indicadas.
        */
        void cargarEscenarioUno(unsigned int xmax, unsigned int ymax, unsigned int zmax);
        /*
            comentario: MAPA TERRITORIO, nivel 1 tierra resto aire. Este método llama al creador de tablero que genera los casilleros vacíos. Según el tipo de escenario se asignan los tipos de casillero.
            No hace falta validar los maximos porque lo hace el constructor de Tablero.
            pre: debe existir el objeto BatallaCampal
            post: crea el escenario uno con las dimensiones y tipos de casilla indicadas.
        */
        void cargarEscenarioDos(unsigned int xmax, unsigned int ymax, unsigned int zmax);
        /*
            comentario: MAPA COSTA, nivel 1 mezcla resto aire. Este método llama al creador de tablero que genera los casilleros vacíos. Según el tipo de escenario se asignan los tipos de casillero.
            No hace falta validar los maximos porque lo hace el constructor de Tablero.
            pre: debe existir el objeto BatallaCampal
            post: crea el escenario uno con las dimensiones y tipos de casilla indicadas.
        */
        void cargarEscenarioTres(unsigned int xmax, unsigned int ymax, unsigned int zmax);
        /*
            comentario: 
            pre: debe existir el objeto Batalla Campañ
            post: devuelve el idJugador ganador de la partida.
        */
        unsigned int obtenerGanador();
        /*
            comentario: este método tiene el algoritmo que ejecuta un disparo de un jugador.
            pre: debe existir el objeto Batalla Campal y el puntero a jugador debe existir y ser distinto de NULL.
            post: ejecuta el disparo según las reglas del juego.
        */
        void ejecutarDisparo(Jugador* jugador);
        /*
            comentario: verifica la factibilidad de movimientos entre casillas aledañas (horizontal, vertical, diagonal)
            pre: ninguna, la validación de si las coordenadas iniciales o finales están dentro del tablero se hace en el método moverFicha.
            post: devuelve true si el movimiento se puede hacer, false en caso contrario.
        */
        bool verificarMovimiento(unsigned int xi, unsigned int yi, unsigned int zi, unsigned int xf, unsigned int yf, unsigned int zf);
        /*
            comentario: mueve una ficha (soldado o armamento) de un casillero a otro, con las reglas del juego.
            pre: jugador debe ser un puntero a TDA Jugador, distinto de NULL
            post: realiza el movimiento según las reglas del juego.
        */
        void moverFicha(Jugador* jugador);
        /*
            comentario: ejecuta el beneficio de un barco en el agua.
            pre: debe existir jugador y ser distinto de NULL
            post: realiza el beneficio del barco en el agua.
        */
        void beneficioBarco(Jugador* jugador);
        /*
            comentario: ejecuta el beneficio de un avión en el aire.
            pre: debe existir jugador y ser distinto de NULL
            post: realiza el beneficio del avión en el aire.
        */
        void beneficioAvion(Jugador* jugador);
        /*
            comentario: chequea si el cubo elegido por el jugador entra o no en el tablero.
            pre: ninguna, la validación de las coordenadas en el tablero se hace fuera de este método, en dispararMisil.
            post: devuelve true si el centro del cubo seleccionado por el jugador es factible para el tablero actual.
        */
        bool verificarCentroCubo(unsigned int &a, unsigned int &b, unsigned int &c);
        /*
            comentario: 
            pre: jugador debe existir y ser distinto de NULL.
            post: realiza el disparo del misil en un cubo de 3x3x3 dentro del tablero. Según las reglas del juego.
        */
        void dispararMisil(Jugador* jugador);
        /*
            comentario: random para dar la carta al jugador al inicio de su turno.
            pre: el objeto BatallaCampal debe estar creado
            post: devuelve el TipoCarta que recibe el jugador
        */
        TipoCarta tomarCarta();
        /*
            comentario: 
            pre: debe existir BatallaCampal y ya estar inicializado.
            post: realiza los turnos de todo el juego hasta que uno de todos los jugadores gane.
        */
        void jugar();
        /*
            comentario: este método recibe un jugador y un tipo de carta levantado por ese jugador. Solicita posición al jugador para colocar la ficha dada por la carta en el tablero.
            pre: jugador debe existir y ser distinto de NULL. carta debe ser una de las cartas disponibles por el juego.
            post: realiza el posicionamiento del armamento en el tablero.
        */
        void colocarArmamentoCarta(Jugador* jugador, TipoCarta carta);
        /*
            comentario: 
            pre: jugador debe existir y ser distinto de NULL
            post: este método es el paso a paso de un turno completo para un jugador, toma de carta, disparo, movimiento, uso de carta, muestra de su ejército.
        */
        void desarrollarTurno(Jugador* jugador);
};



#endif // BATALLA CAMPAL