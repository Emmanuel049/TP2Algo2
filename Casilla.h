

#ifndef CASILLA_H_
#define CASILLA_H_
enum TipoDeCasilla{
	Agua,
	Tierra,
	Aire,
	General
};
enum EstadoDeCasilla{
	Vacio,
	Inactivo,
	Ocupado
};
enum Ficha{
	Soldado,
	Avion,
	Barco,
	Vacia
};
class Casilla {
private:
	EstadoDeCasilla estado;
	TipoDeCasilla tipo;
	Ficha ficha;
	unsigned int x;
	unsigned int y;
	unsigned int z;
public:

	Casilla(unsigned int x, unsigned int y,unsigned int z, TipoDeCasilla tipoCasilla, Ficha ficha);
	virtual ~Casilla() {
		// TODO Auto-generated destructor stub
	}
	/*
	 * Pre: Debe estar inicializada
	 * Pos: Devuelve el estado de la casilla
	 */
	EstadoDeCasilla getEstado() const;
	/*
	 * Pre: el tipo de parametro debe ser EstadoDeFicha
	 * Pos: Cambia el estado
	 */
	void setEstado(EstadoDeCasilla estado);
	/*
	 * Pre: Debe estar inicializada
	 * Pos: Devuelve el tipo de la casilla
	 */
	TipoDeCasilla getTipo() const;
	/*
	 * Pre: el tipo de parametro debe ser TipoDeCasila
	 * Pos: Cambia el tipo
	 */
	void setTipo(TipoDeCasilla tipo);
	/*
	 * Pre: x debe estar inicializado
	 * Pos: Debuelve x
	 */
	unsigned int getX() const;
	/*
	 * Pre: y debe estar inicializado
	 * Pos: Debuelve y
	 */
	unsigned int getY() const;
	/*
	 * Pre: z debe estar inicializado
	 * Pos: Debuelve z
	 */
	unsigned int getZ() const;

	/*
	 * Pre: Debe haber una ficha en la casilla
	 * Pos: Se libera la casilla dejandola en el estado correspondiente
	 */
	void vaciar(EstadoDeCasilla estado);
	/*
	 * Pre: Debe estar inicializada
	 * Pos: Devuelve el tipo de ficha que hay en la casilla
	 */
	Ficha getFicha() const ;
	/*
	 * Pre: el tipo de parametro debe ser Ficha
	 * Pos: Cambia el tipo de ficha
	 */
	void setFicha(Ficha ficha);
};

#endif /* CASILLA_H_ */
