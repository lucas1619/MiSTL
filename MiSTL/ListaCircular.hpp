//
// Created by lucasmoreno on 19/05/20.
//

#ifndef MISTL_LISTACIRCULAR_HPP
#define MISTL_LISTACIRCULAR_HPP

#include "Nodo.hpp"
namespace listaCircularSimple{
    using namespace enlaceSimple;
    template <class L>
    class ListaCircular{
    private:
        Nodo<L>*inicio;
        Nodo<L>*fin;
        long long tamanho;
        Nodo<L>* crearNodo(L elemento){
            Nodo<L> * nuevo = new Nodo<L>();
            nuevo->elemento = elemento;
            return nuevo;
        }
    public:
        ListaCircular(){
            this->inicio = this->fin = nullptr;
            tamanho = 0;
        }
        ~ListaCircular(){

        }
        void insertarAlInicio(L elemento){
            Nodo<L> * nuevo = crearNodo(elemento);
            if(this->tamanho == 0){
                this->inicio = this->fin = nuevo;
                nuevo->siguiente = nuevo;
            } else{
                nuevo->siguiente = this->inicio;
                this->fin->siguiente = nuevo;
                this->inicio = nuevo;
            }
            ++this->tamanho;
        }
        void insertarAlFinal(L elemento){
            if(this->tamanho == 0){
                this->insertarAlInicio(elemento);
            } else{
                Nodo<L> * nuevo = crearNodo(elemento);
                this->fin->siguiente = nuevo;
                nuevo->siguiente = this->inicio;
                this->fin = nuevo;
                ++this->tamanho;
            }
        }
        void insertarEnPosicion(long long posicion, L elemento){
            if(posicion < this->tamanho && posicion >= 0){
                if(posicion == 0){
                    this->insertarAlInicio(elemento);
                } else if(posicion == this->tamanho - 1){
                    this->insertarAlFinal(elemento);
                } else{
                    Nodo<L> * nuevo = crearNodo(elemento);
                    Nodo<L> * puntero = this->inicio;
                    long long contador = 0;
                    while(contador != posicion-1){
                        puntero = puntero->siguiente;
                        ++contador;
                    }
                    nuevo->siguiente = puntero->siguiente;
                    puntero->siguiente = nuevo;
                    ++this->tamanho;
                }
            }
        }
        void eliminarAlPrincipio(){
            if(this->tamanho == 1){
                this->fin->siguiente = nullptr;
                delete this->fin;
                this->inicio = this->fin = nullptr;
                this->tamanho = 0;
            }else if(this->tamanho > 1){
                Nodo<L> * eliminado = this->inicio;
                this->inicio = eliminado->siguiente;
                eliminado->siguiente = nullptr;
                this->fin->siguiente = this->inicio;
                delete eliminado;
                --this->tamanho;
            }
        }
        void eliminarAlFinal(){
            if(this->tamanho == 1){
                eliminarAlPrincipio();
            } else if(this->tamanho > 1){
                Nodo<L> * eliminado = this->fin;
                Nodo<L> * puntero = this->inicio;
                while (puntero->siguiente != eliminado){
                    puntero = puntero->siguiente;
                }
                eliminado->siguiente = nullptr;
                puntero->siguiente = this->inicio;
                this->fin = puntero;
                delete eliminado;
                --this->tamanho;
            }
        }
        void eliminarEnPosicion(long long posicion){
            if(posicion < this->tamanho && posicion >= 0) {
                if (posicion == 0) {
                    this->eliminarAlPrincipio();
                } else if (posicion == this->tamanho - 1) {
                    this->eliminarAlFinal();
                } else {
                    Nodo<L> *puntero = this->inicio;
                    long long contador = 0;
                    while (contador != posicion - 1) {
                        puntero = puntero->siguiente;
                        ++contador;
                    }
                    Nodo<L> *eliminado = puntero->siguiente;
                    puntero->siguiente = eliminado->siguiente;
                    eliminado->siguiente = nullptr;
                    delete eliminado;
                    --this->tamanho;
                }
            }
        }
        L obtenerElementoAlInicio(){
            return this->inicio->elemento;
        }
        L obtenerElementoAlFinal(){
            return this->fin->elemento;
        }
        L obtenerElementoEnPosicion(long long posicion) {
            if (posicion < this->tamanho && posicion >= 0){
                if(posicion == 0){
                    return this->obtenerElementoAlInicio();
                } else if(posicion == this->tamanho - 1){
                    return this->obtenerElementoAlFinal();
                } else{
                    Nodo<L> *puntero = this->inicio;
                    long long contador = 0;
                    while (contador != posicion) {
                        puntero = puntero->siguiente;
                        ++contador;
                    }
                    return puntero->elemento;
                }
            }
        }
        long long obtenerTamanho(){
            return this->tamanho;
        }
        bool estaVacia(){
            return this->tamanho == 0;
        }
        L obtenerIterandoNVeces(long long n){
            /*long long obtener = n%this->tamanho;
            return obtenerElementoEnPosicion(obtener);*/
            Nodo<L> *puntero = this->inicio;
            long long contador = 0;
            while (contador < n) {
                puntero = puntero->siguiente;
                ++contador;
            }
            return puntero->elemento;
        }
    };
}
namespace listaCircularDoble{
    using namespace enlaceDoble;
    template <class K>
    class ListaCircular{

    };
}
#endif //MISTL_LISTACIRCULAR_HPP
