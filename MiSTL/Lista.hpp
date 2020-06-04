//
// Created by lucasmoreno on 17/05/20.
//

#ifndef MISTL_LISTA_HPP
#define MISTL_LISTA_HPP

#include "Nodo.hpp"
namespace listaSimple{
    using namespace enlaceSimple;
    template <class L>
	class Lista {
	private:
		Nodo<L>* inicio;
		Nodo<L>* fin;
		long long tamanho;
		Nodo<L>* crearNodo(L elemento) {
			Nodo<L> * nuevo = new Nodo<L>();
			nuevo->elemento = elemento;
			return nuevo;
		}
	public:
		Lista() {
			this->inicio = this->fin = nullptr;
			this->tamanho = 0;
		}
		~Lista() {
			while (!this->estaVacia()) {
				this->eliminarAlPrincipio();
			}
			delete this->inicio;
			delete this->fin;
		}
		void insertarAlInicio(L elemento) {
			Nodo<L> * nuevo = crearNodo(elemento);
			if (this->tamanho > 0) {
				nuevo->siguiente = this->inicio;
				this->inicio = nuevo;
			}
			else {
				this->inicio = this->fin = nuevo;
			}
			++this->tamanho;
		}
		void insertarAlFinal(L elemento) {
			if (this->tamanho > 0) {
				Nodo<L> * nuevo = crearNodo(elemento);
				this->fin->siguiente = nuevo;
				this->fin = nuevo;
				++this->tamanho;
			}
			else {
				this->insertarAlInicio(elemento);
			}
		}
		void insertarEnPosicion(long long posicion, L elemento) {
			if (posicion < this->tamanho && posicion >= 0) {
				if (posicion == 0) {
					this->insertarAlInicio(elemento);
				}
				else if (posicion == this->tamanho - 1) {
					this->insertarAlFinal(elemento);
				}
				else {
					Nodo<L> * nuevo = crearNodo(elemento);
					Nodo<L> * puntero = this->inicio;
					long long contador = 0;
					while (contador != posicion - 1) {
						puntero = puntero->siguiente;
						++contador;
					}
					nuevo->siguiente = puntero->siguiente;
					puntero->siguiente = nuevo;
					++this->tamanho;
				}
			}
		}
		void eliminarAlPrincipio() {
			if (this->tamanho > 0) {
				if (this->tamanho == 1) {
					delete this->inicio;
					this->inicio = this->fin = nullptr;
				}
				else {
					Nodo<L> * eliminado = this->inicio;
					this->inicio = eliminado->siguiente;
					eliminado->siguiente = nullptr;
					delete eliminado;
				}
				--this->tamanho;
			}

		}
		void eliminarAlFinal() {
			if (this->tamanho <= 1) {
				this->eliminarAlPrincipio();
			}
			else {
				Nodo<L> * eliminado = this->fin;
				Nodo<L> * puntero = this->inicio;
				while (puntero->siguiente != eliminado) {
					puntero = puntero->siguiente;
				}
				puntero->siguiente = nullptr;
				this->fin = puntero;
				delete eliminado;
				--this->tamanho;
			}
		}
		void eliminarEnPosicion(long long posicion) {
			if (posicion < this->tamanho && posicion >= 0) {
				if (posicion == 0) {
					this->eliminarAlPrincipio();
				}
				else if (posicion == this->tamanho - 1) {
					this->eliminarAlFinal();
				}
				else {
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
		void eliminarPorValor(L elemento) {
			Nodo<L> * puntero = this->inicio;
			long long contador = 0;
			bool encontro = false;
			while (contador < this->tamanho && !encontro) {
				puntero = puntero->siguiente;
				if (puntero->elemento == elemento)
				{
					encontro = true;
				}
				++contador;
			}
			if (contador == this->tamanho) {
				return;
			}
			else if (encontro) {
				this->eliminarEnPosicion(contador);
			}
		}
		L obtenerElementoAlInicio() {
			return this->inicio->elemento;
		}
		L obtenerElementoAlFinal() {
			return this->fin->elemento;
		}
		L obtenerElementoEnPosicion(long long posicion) {
			if (posicion < this->tamanho && posicion >= 0) {
				if (posicion == 0) {
					return this->obtenerElementoAlInicio();
				}
				else if (posicion == this->tamanho - 1) {
					return this->obtenerElementoAlFinal();
				}
				else {
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
		long long obtenerPosicionPorValor(L elemento) {
			Nodo<L> * puntero = this->inicio;
			long long contador = 0;
			bool encontro = false;
			while (contador < this->tamanho && !encontro) {
				puntero = puntero->siguiente;
				if (puntero->elemento == elemento)
				{
					encontro = true;
				}
				++contador;
			}
			if (contador == this->tamanho) {
				return NULL;
			}
			else if (encontro) {
				return contador;
			}
		}
        long long obtenerTamanho(){
            return this->tamanho;
        }
        bool estaVacia(){
            return this->tamanho == 0;
        }
    };
}
namespace listaDoble{
    using namespace enlaceDoble;
    template <class K>
    class Lista{
    private:
        Nodo<K>* inicio;
        Nodo<K>* fin;
        long long tamanho;
        Nodo<K>* crearNodo(K elemento){
            Nodo<K> * nuevo = new Nodo<K>();
            nuevo->elemento = elemento;
            return nuevo;
        }
    public:
        Lista(){
            this->inicio = this->fin = nullptr;
            this->tamanho = 0;
        }
        ~Lista(){
        }
        void insertarEnPosicion(long long posicion, K elemento){
            Nodo<K>* nuevo = this->crearNodo(elemento);
            Nodo<K>* puntero = this->inicio;
            long long contador = 0;
            while (contador != posicion - 1){
                puntero = puntero->siguiente;
                ++contador;
            }
            puntero->siguiente->anterior = nuevo;
            nuevo->siguiente = puntero->siguiente;
            nuevo->anterior = puntero;
            puntero->siguiente = nuevo;
            ++this->tamanho;
        }
        void eliminarEnPosicion(long long posicion){
            Nodo<K>*puntero = this->inicio;
            long long contador = 0;
            while (contador != posicion - 1){
                puntero = puntero->siguiente;
                ++contador;
            }
            Nodo<K>*eliminado = puntero->siguiente;
            puntero->siguiente = eliminado->siguiente;
            eliminado->siguiente->anterior = puntero;
            eliminado->anterior = eliminado->siguiente = nullptr;
            delete eliminado;
            --this->tamanho;
        }
    };
}
#endif //MISTL_LISTA_HPP
