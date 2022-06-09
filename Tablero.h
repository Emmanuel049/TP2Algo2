
#ifndef TABLERO_H_
#define TABLERO_H_
#include "Lista.h"
#include "Casilla.h"
#include "EasyBMP.h"
#include "Jugador.h"
#include "Vector.h"

#ifndef NULL
#define NULL 0
#endif /* NULL */

class Tablero {
private:
	Lista<Lista<Lista<Casilla *>*>*> *casilleros;
	unsigned int xMaximo;
	unsigned int yMaximo;
	unsigned int zMaximo;
public:
	/*
	 * Pre:Las dimensiones deben ser igual o mayor a 1
	 * Pos:Se crea un tablero de las dimenciones dadas con todos los casilleros vacios
	 */
	Tablero(unsigned int xMaximo,unsigned int yMaximo,unsigned int zMaximo);
	
	/*
	 *Pre:-
	 *Pos: Elimina los valores guardados en memoria dinámica (actual como el destructor);
	 */
	void eliminarTablero();

	/*
	 * Pre: Las dimensiones deben ser iguales o mayores que 1
	 * Pos: Devuelve el casillero indicado
	 */
	Casilla * getCasilla(unsigned int x,unsigned int y,unsigned int z) ;
	/*
	 * Pre: Las dimension x debe estar inicializada
	 * Pos: Devuelve la dimencion x
	 */
	unsigned int getxMaximo() const;
	/*
	 * Pre: Las dimension y debe estar inicializada
	 * Pos: Devuelve la dimencion y
	 */
	unsigned int geytMaximo() const;
	/*
	 * Pre: Las dimension z debe estar inicializada
	 * Pos: Devuelve la dimencion z
	 */
	unsigned int getzMaximo() const;
	
	/*
	 * Pre: Tablero debe estar inicializado
	 * Pos: Devuelve verdadero o faslo según la veracitud de la existencia de la 
	 * casilla y devuelve los parámetros a,b y c con el valor introducido por 
	 * teclado.
	 */
	bool leerCoordenadas(unsigned int& a, unsigned int& b, unsigned int& c,unsigned int h=0, unsigned int i=0, unsigned int j=0);

	/*
	 *Pre: La identificacion del jugador debe ser un numero entero positivo o 0
	 *Pos: Genera un bitmap por nivel (altura [x]) del tablero cambiando el color
	 *segun tipo de ficha, estado de casilla y terreno de la casilla.
	 */
	void BMPdeTablero(Jugador* jugador);

	/*
	 *Pre:Deben estar generados los archivos de los bitmaps
	 *Pos: Debuelve un puntero a una impresión de una lista correspondiente a cada 
	 * numero de color del bit en cada posicion del tablero.
	 */
	unsigned char* leerBMP(char* rutaArchivo);

	/*
	 *Pre:-
	 *Pos: El tablero queda escrito en un archivo de texto.
	 */
	void escribirTableroTexto(Jugador *jugador);

	/*
	 *Pre: Debe existir el archivo de texto done se encuentra el tablero a leer
	 *Pos: Imprime por pantalla el estado del tablero (completo con posicion de 
	 * fichas, inactividad de casillas y distintos terrenos) que obtiene del
	 *archivo de texto del tablero.
	 */
	void leerTableroTexto(std::string rutaArchivo);

	/*
	 *Pre: El tda Tablero debe estar inicializado para conocer las dimensiones de este
	 *Pos: Muestra por pantalla el estado del tablero (completo con posicion de 
	 * fichas, inactividad de casillas y distintos terrenos) actual.
	 *
	 */
	void impresionTableroTextoMixto(Jugador *jugador);
	
	
	/*
	 *Pre:-
	 *Pos: Devuelve verdadero o falso segun la existencia de la casilla
	 */
	bool existeCasilla(unsigned int x, unsigned int y, unsigned int z);
	
	/*
	 * Pre: El tablero debe estar inicializado
	 * Pos: Se imprime el Tablero solo mostrando fichas no terreno
	 */
	void printTableroFichas(unsigned int numJugador);

	/*
	 * Pre: El tablero debe estar inicializado
	 * Pos: Se imprime el terreno del Tablero
	 */
	void printTableroTipos();

private:
	/*
	 * Pre:-
 	 * Pos: Si los valores no estan en reango tira una excepcion, los enteros h, i y j son por si se quiere
	 * achicar el rango que se puede admitir.
 	 */
	void validarRango(unsigned int x,unsigned int y,unsigned int z,unsigned int h=0, unsigned int i=0, unsigned int j=0);
	
	/*
	 * Pre:-
 	 * Pos: Si los valores no son mayores o iguales a 1 y enteros tira una exepcion, los enteros h, i y j son por si se quiere
	 * achicar el valor mínimmo de entero que se puede admitir.
 	 */
	void validarParametros(unsigned int x,unsigned int y,unsigned int z,unsigned int h=0, unsigned int i=0, unsigned int j=0);

	/*
	 *Pre: Tablero debe estar inicializado para obtener dimensiones de este
	 *Pos: Se generan las dimensiones en 2D (ancho y largo [y,z]) del bitmap del nivel correspondinete (x)
	 */
	void inicializarBMP(Vector<BMP*>* tablero);

	/*
	 *Pre: TDA BMP debe estar inicializado, tablero también
	 *Pos:Devuelve en el archivo del bitmap del nivel correspondiente el color que
	 * corresponda a una casilla inactiva.
	 */
	void impresionInactivoBMP(Vector<BMP*>* tablero, unsigned int x, unsigned int y, unsigned int z);
	
	/*
	 *Pre: TDA BMP debe estar inicializado, tablero y Jugador también
	 * Id del jugador debe se se un número entro mayor o igual a 0
	 *Pos:Devuelve en el archivo del bitmap al nivel correspondiente el color que
	 * corresponda según el tipo de ficha y a que jugador le corresponde
	 */
	void impresionFichaBMP(Vector<BMP*>* tablero,Jugador* jugador,unsigned int x, unsigned int y, unsigned int z);
	
	/*
	 *Pre: TDA BMP debe estar inicializado, tablero también
	 *Pos:Devuelve en el archivo del bitmap al nivel correspondiente, el color que
	 * se asignó según el tipo de terreno
	 */
	void impresionTipoBMP(Vector<BMP*>* tablero,unsigned int x, unsigned int y, unsigned int z);
	
	/*
	 *Pre: BMP debe estar inicializado
	 *Pos:Guarda en el archivo correspondiente al nivel el bitmap generado para este
	 */
	void guradadoEnArchivoBMP(Vector<BMP*>* tablero);
	
	
	
	/*
	 *Pre:-
	 *Pos:Imprime los simbolos que se usaron para los distintos terrenos y las
	 *distintas fichas para otorgar claridad
	 */
	void impresionAclaraciones();
	

	/*
	 *Pre:Tablero inicializado
	 *Pos:Imprime el simbolo del la ficha que se encuentra en la casilla 
	 *que se está recorriendo
	 */	
	void Tablero::impresionFichaTexto(Ficha *ficha, unsigned int numJugador );

	/*
	 *Pre:Tablero debe estar inicializado
	 *Pos:Imprime el simbolo del tipo (terreno) de la casilla en la que se esté
	 */
	void Tablero::impresionTipoTexto(Casilla * actual);

	/*
	 *Pre:Tablero y ficha deben estar inicializados
	 *Pos:Guarda en un archivo de texto el simbolo correspondiente
	 * a la ficha que ocupa una determinada casilla
	 */
	void Tablero::guardadoEnArchivoTextoFicha(Ficha *ficha, unsigned int numJugador);

	/*
	 *Pre: Tablero debe estar inicializado
	 *Pos: Guarda el sibolo correspondiente al Tipo de la casilla de
	 * acuerdo a lo encontrado en esta
	 */
	void Tablero::guardadoEnArchivoTextoTipo(Casilla *actual);


	/*
	 * Pre: El tablero debe estar inicializado
	 * Pos: Se imprime el Tablero solo mostrando fichas no terreno
	 */
	void printTableroFichas(unsigned int numJugador);

	/*
	 * Pre: El tablero debe estar inicializado
	 * Pos: Se imprime el terreno del Tablero
	 */
	void printTableroTipos();


};




#endif /* TABLERO_H_ */
