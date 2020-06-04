#pragma once
#include"Lista.hpp"
using namespace listaSimple;
template<class T>
class Pila
{
private:
	Lista<T>* pila;
public:
	Pila() {
		pila = new Lista<T>();
	};
	~Pila() {
		delete pila;
	};
	void push(T elemento) {
		pila->insertarAlInicio(elemento);
	}
	void pop() {
		pila->eliminarAlPrincipio();
	}
	T top() {
		return pila->obtenerElementoAlInicio();
	}
	bool isEmpty() {
		return pila->estaVacia();
	}
	long long size() {
		return pila->obtenerTamanho();
	}
};
