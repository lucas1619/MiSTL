#pragma once
#include"Lista.hpp"
namespace colaSimple {
	using namespace listaDoble;
	template<class T>
	class Cola
	{
	private:
		Lista<T>* cola;
	public:
		Cola() {
			cola = new Lista<T>();
		}
		~Cola() {
			delete cola;
		}
		void pop() {
			cola->eliminarAlInicio();
		}
		void pop_back() {
			cola->eliminarAlFinal();
		}
		void push(T elemento) {
			cola->insertarAlFinal(elemento);
		}
		T front() {
			return cola->obtenerElementoAlInicio();
		}
		T back() {
			return cola->obtenerElementoAlFinal();
		}
		bool isEmpty() {
			return cola->estaVacia();
		}
		long long size() {
			return cola->obtenerTamanho();
		}
	};
}
namespace colaPrioridad {
    using namespace enlaceDoble;
    template <class K>
    class   Cola {
    private:
        void insertarAlInicio(K elemento) {
            Nodo<K>* nuevo = crearNodo(elemento);
            if (this->tamanho > 0) {
                nuevo->siguiente = this->inicio;
                this->inicio->anterior = nuevo;
                this->inicio = nuevo;
            }
            else {
                this->inicio = this->fin = nuevo;
            }
            ++this->tamanho;
        }
        /*----------------------------------------*/
        void swap(Nodo<K>* xp, Nodo<K>* yp)
        {
            K temp = xp->elemento;
            xp->elemento = yp->elemento;
            yp->elemento = temp;
        }
        /*--------------------INICIO QUICK SORT--------------------------------------*/
        long long partition(long long low, long long high)
        {
            Nodo<K>* pivote = this->inicio;
            long long p = 0;
            while (p < high)
            {
                pivote = pivote->siguiente;
                ++p;
            }
            Nodo<K>* indice = this->inicio;
            long long i = 0;
            while (i < low)
            {
                indice = indice->siguiente;
                ++i;
            }
            Nodo<K>* puntero = indice;
            long long contador = i;
           /* Nodo<K>* puntero = this->inicio;
            long long contador = 0;
            while (contador < low)
            {
                puntero = puntero->siguiente;
                ++contador;
            }*/
            while (contador <= high - 1)
            {
                if (puntero->elemento < pivote->elemento)
                {
                    swap(indice, puntero);
                    indice = indice->siguiente;
                    ++i;
                }
               ++contador;
            }
            swap(indice, pivote);
            return i;
        }
        void quickSort(long long low, long long high)
        {
            if (low < high)
            {
                long long pi = partition(low, high);
                quickSort(low, pi - 1);
                quickSort(pi + 1, high);
            }
        }
        void sort() {
            quickSort(0, this->tamanho - 1);
            ordenado = true;
        }
        Nodo<K>* inicio;
        Nodo<K>* fin;
        long long tamanho;
        Nodo<K>* crearNodo(K elemento) {
            Nodo<K>* nuevo = new Nodo<K>();
            nuevo->elemento = elemento;
            return nuevo;
        }
        bool ordenado;
    public:
        Cola() {
            this->inicio = this->fin = nullptr;
            this->tamanho = 0;
            ordenado = false;
        }
        ~Cola() {
        }
        void push(K elemento) {
            if (this->tamanho > 0) {
                Nodo<K>* nuevo = crearNodo(elemento);
                this->fin->siguiente = nuevo;
                nuevo->anterior = this->fin;
                this->fin = nuevo;
                ++this->tamanho;
            }
            else {
                this->insertarAlInicio(elemento);
            }
            ordenado = false;
        }
        void pop() {
            if (!ordenado) {
                this->sort();
            }
            if (this->tamanho > 0) {
                if (this->tamanho == 1) {
                    delete this->inicio;
                    this->inicio = this->fin = nullptr;
                }
                else {
                    Nodo<K>* eliminado = this->inicio;
                    this->inicio = eliminado->siguiente;
                    eliminado->siguiente->anterior = nullptr;
                    eliminado->siguiente = nullptr;
                    delete eliminado;
                }
                --this->tamanho;
            }
        }
        void pop_back() {
            if (!ordenado) {
                this->sort();
            }
            if (this->tamanho <= 1) {
                this->eliminarAlInicio();
            }
            else {
                Nodo<K>* eliminado = this->fin;
                eliminado->anterior->siguiente = nullptr;
                this->fin = eliminado->anterior;
                eliminado->anterior = nullptr;
                delete eliminado;
                --this->tamanho;
            }
        }
        K front() {
            if (!ordenado) {
                this->sort();
            }
            return this->inicio->elemento;
        }
        K back() {
            if (!ordenado) {
                this->sort();
            }
            return this->fin->elemento;
        }
        long long size() {
            return this->tamanho;
        }
        bool isEmpty() {
            return this->tamanho == 0;
        }
    };
}