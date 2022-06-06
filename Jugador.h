#ifndef DEFINE_JUGADOR
#define DEFINE_JUGADOR

#include <iostream>

#include "Array.h"

#include "string" // Si es que uso string



class Jugador{
    private:
        unsigned int numJugador;
        unsigned int cantSoldados;  

    public:
        Jugador(unsigned int numJugador);
        ~Jugador();
        void setNumJugador(unsigned int num);
        void eliminarSoldado();
        unsigned int getNumJugador();
        unsigned int getCantSoldados();
        void setCantSoldados(unsigned int soldados);
      //  void setCarta(TipoCarta cartaNueva);
      //  TipoCarta getCarta();


};










#endif // DEFINE_JUGADOR