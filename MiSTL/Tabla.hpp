#pragma once
#include"Lista.hpp"
#include<vector>
using namespace std;
namespace tablaSimple {
	using namespace listaSimple;
	template<class K>
	class Tabla
	{
	private:
		Lista<Lista<K>*> * tabla;
	public:
		Tabla() {
			tabla = new Lista<Lista<K>*>();
		};
		~Tabla() {
			while (!this->estaVacia())
			{
				this->eliminarFilaAlFinal();
			}
			delete tabla;
		};
		void insertarFilaAlFinal() {
			tabla->insertarAlFinal(new Lista<K>());
		}
		void eliminarFilaAlFinal() {
			tabla->eliminarAlFinal();
		}
		void insertarElementoEnUnaFilaAlFinal(K elemento, long long filaN) {
			if (filaN < tabla->obtenerTamanho()) {
				tabla->obtenerElementoEnPosicion(filaN)->insertarAlFinal(elemento);
			}
			return;
		}
		void eliminarElementoEnUnaFilaEnPosicion(long long filaN, long long posicion) {
			if (filaN < tabla->obtenerTamanho()) {
				tabla->obtenerElementoEnPosicion(filaN)->eliminarEnPosicion(posicion);
			}
		}
		bool estaVacia() {
			return tabla->estaVacia();
		}
		long long obtenerNumeroDeFilas() {
			return tabla->obtenerTamanho();
		}
		long long obtenerNumeroDeColumnasDeUnaFila(long long filaN) {
			if (filaN < tabla->obtenerTamanho()) {
				return tabla->obtenerElementoEnPosicion(filaN)->obtenerTamanho();
			}
			return NULL;
		}
	};
}
namespace tablaConVectorSimple {
	using namespace listaSimple;
	template<class K>
	class Tabla
	{
	private:
		vector<Lista<K>*> * tabla;
	public:
		Tabla() {
			tabla = new vector<Lista<K>*>();
		};
		Tabla(long long tamanho) {
			tabla = new vector<Lista<K>*>(tamanho);
			for (long long i = 0; i < tamanho; i++)
			{
				tabla->at(i) = new Lista<K>();
			}
		};
		~Tabla() {
			tabla->clear();
			delete tabla;
		};
		void insertarFilaAlFinal() {
			tabla->push_back(new Lista<K>());
		}
		void eliminarFilaAlFinal() {
			tabla->pop_back();
		}
		long long obtenerPosicionElementoEnUnaFilaPorValor(K elemento, long long filaN) {
			if (filaN < tabla->size()) {
				return this->tabla->at(filaN)->obtenerPosicionPorValor(elemento);
			}
			return NULL;
		}
		void insertarElementoEnUnaFilaAlFinal(K elemento, long long filaN) {
			if (filaN < tabla->size()) {
				tabla->at(filaN)->insertarAlFinal(elemento);
			}
			return;
		}
		void eliminarElementoEnUnaFilaEnPosicion(long long filaN, long long posicion) {
			if (filaN < tabla->size()) {
				tabla->at(filaN)->eliminarEnPosicion(posicion);
			}
		}
		void eliminarElementoEnUnaFilaPorValor(long long filaN, K elemento) {
			if (filaN < tabla->size()) {
				tabla->at(filaN)->eliminarPorValor(elemento);
			}
		}
		bool estaVacia() {
			return tabla->empty();
		}
		long long obtenerNumeroDeFilas() {
			return tabla->size();
		}
		long long obtenerNumeroDeColumnasDeUnaFila(long long filaN) {
			if (filaN < tabla->size()) {
				return tabla->at(filaN)->obtenerTamanho();
			}
			return 0;
		}
		void showTable() {
			for (long long i = 0; i < this->tabla->size(); i++)
			{
				cout << i;
				for (long long j = 0; j < this->obtenerNumeroDeColumnasDeUnaFila(i); j++)
				{
					cout << " ---> " << this->tabla->at(i)->obtenerElementoEnPosicion(j);
				}
				cout << endl;
			}
		}
	};
}
