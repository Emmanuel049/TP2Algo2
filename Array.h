// Versión simple, no se consideraron excepciones

#include <iostream>
#ifndef ARRAYTEMP_H
#define ARRAYTEMP_H


template <class T>
class Array {
    public:
        Array();
        Array(int );
        Array( const T & );
        ~Array( );
        int getSize( );
        Array<T>&operator=( const T & );
        bool operator==( const T & );
        T &operator[ ]( int );
        void agregarAlFinal(T &);
        T& obtener(int posicion);
        void agregar(int, T);

    private:
        int size;
        T *ptr;
};


template <class T>
Array<T>::Array() {
    ptr = new T[10];
    size=10;
}

template <class T>
Array<T>::Array(int x){ // RECIBE EL TAMAÑO A GENERAR EL ARRAY
    if ((x<1)||(x>500)) 
    size=10; 
    else size=x;
    ptr = new T[size];
}

template <class T>
Array<T>::Array( const T &init ){
    size=init.size ;
    ptr = new T[ size ];
    for ( int i = 0; i < size; i++ )
    ptr[ i ] = init.ptr[ i ];      //debe existir el = para la clase T !
}



template <class T>
Array<T>::~Array() {
    if (ptr)
    delete [ ] ptr;
}


template <class T>
int Array<T>::getSize() {
    return size;
}

template <class T>
Array<T>& Array<T>::operator=( const T &rigth ){
    if ( &rigth != this ) {
        if ( size != rigth.size )  {
            T *aux;
            aux=new T[ rigth.size ];
            delete [] ptr;
            size =rigth.size ;
            ptr=aux;
            for ( int i = 0; i < size; i++ )
                {ptr[ i ] = rigth.ptr[ i ];}
            return *this;
        }
        else {
            for ( int i = 0; i < size; i++ )
                ptr[ i ] = rigth.ptr[ i ];
        return *this;
        }
    }
    return *this;
}


template <class T>
bool Array<T>::operator==( const T &rigth ) {
    if ( size != rigth.size )
        return false;
    else
        for ( int i = 0; i < size; i++ )
    if ( ptr[ i ] != rigth.ptr[ i ] )
        return false;
    else
        return true;
}


template <class T>
T & Array<T>::operator [ ]( int subscript ) {     
    return ptr[ subscript ];
}


template <class T>
void Array<T>::agregarAlFinal(T& dato){
    this->ptr = new T[(this->size)+1];
    this->ptr[this->size] = dato;
}

template <class T>
void Array<T>::agregar(int posicion, T dato){
    this->ptr[posicion-1] = dato;
}


template <class T>
T& Array<T>::obtener(int posicion){
    return this->ptr[posicion-1];
}





#endif // ARRAYTEMP_H
