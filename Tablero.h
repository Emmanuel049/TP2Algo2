
#ifndef TABLERO_H_
#define TABLERO_H_
#include "Lista.h"
#include "Casilla.h"
#include "EasyBMP.h"
#include "Jugador.h"
#include "Vector.h"


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
	virtual ~Tablero();

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
	void escribirTableroTexto();

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
	void impresionTableroTexto();
	
	
	/*
	 *Pre:-
	 *Pos: Devuelve verdadero o falso segun la existencia de la casilla
	 */
	bool existeCasilla(unsigned int x, unsigned int y, unsigned int z);

private:
	/*
	 * Pre:-
 	 * Pos: Si los valores no estan en reango tira una excepcion.
 	 */
	void validarRango(unsigned int x,unsigned int y,unsigned int z);

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
	void Tablero::impresionFichaTexto(Ficha *ficha);

	/*
	 *Pre:Tablero debe estar inicializado
	 *Pos:Imprime el simbolo del tipo (terreno) de la casilla en la que se esté
	 */
	void Tablero::impresionTipoTexto();

	/*
	 *Pre:Tablero y ficha deben estar inicializados
	 *Pos:Guarda en un archivo de texto el simbolo correspondiente
	 * a la ficha que ocupa una determinada casilla
	 */
	void Tablero::guardadoEnArchivoTextoFicha(Ficha *ficha);

	/*
	 *Pre: Tablero debe estar inicializado
	 *Pos: Guarda el sibolo correspondiente al Tipo de la casilla de
	 * acuerdo a lo encontrado en esta
	 */
	void Tablero::guardadoEnArchivoTextoTipo();
};


#endif /* TABLERO_H_ */
