#pragma once
#include <functional>
#include <iostream>
using namespace std;

template<class J>
struct JNodo {
	J elemento;
	JNodo* izq;
	JNodo* der;
	long long altura;
	JNodo() {
		izq = nullptr;
		der = nullptr;
		altura = 0;
	}
};

template<class J>
class ArbolAVL {
private:
	typedef function<int(long long, long long)> Comp;
	JNodo<J>* raiz;
	void(*procesar)(J);
	Comp comparar;

	bool _Buscar(JNodo<J>* nodo, J e) {
		if (nodo == nullptr) return false;
		else {
			if (nodo->elemento == e)
			{
				return true;
			}
			else if (e > nodo->elemento) {
				return _Buscar(nodo->derecha, e);
			}
			else {
				return _Buscar(nodo->izquierda, e);
			}
		}
	}

	JNodo<J>* _Obtener(JNodo<J>* nodo, J e) {
		if (nodo == nullptr) return nullptr;
		else {
			if (nodo->elemento == e)
			{
				return nodo;
			}
			else if (e > nodo->elemento) {
				return _Obtener(nodo->derecha, e);
			}
			else {
				return _Obtener(nodo->izquierda, e);
			}
		}
	}

	long long _altura(JNodo<J>* nodo) {
		if (nodo == nullptr) return 0;
		return nodo->altura;
	}
	void _rotarDerecha(JNodo<J>*& nodo) {
		JNodo<J>* p = nodo->izq;
		nodo->izq = p->der;
		p->der = nodo;
		nodo = p;
	}

	void _rotarIzquierda(JNodo<J>*& nodo) {
		JNodo<J>* p = nodo->der;
		nodo->der = p->izq;
		p->izq = nodo;
		nodo = p;
	}
	void _balanceo(JNodo<J>*& nodo) {
		int fb = comparar(_altura(nodo->der), _altura(nodo->izq));

		if (fb > 1) {
			int hhizq = _altura(nodo->der->izq);
			int hhder = _altura(nodo->der->der);
			if (hhizq > hhder) {
				_rotarDerecha(nodo->der);
			}
			_rotarIzquierda(nodo);
		}
		if (fb < -1) {
			int hhizq = _altura(nodo->izq->izq);
			int hhder = _altura(nodo->izq->der);
			if (hhizq < hhder) { 
				_rotarIzquierda(nodo->izq);
			}
			_rotarDerecha(nodo);
		}
		int hizq = _altura(nodo->izq);
		int hder = _altura(nodo->der);
		nodo->altura = 1 + ((hizq > hder) ? hizq : hder);
	}

	bool _insertar(JNodo<J>*& nodo, J e) {

		if (nodo == nullptr) {
			nodo = new JNodo<J>();
			nodo->elemento = e;
			return true;
		}
		else if (e < nodo->elemento) {
			_insertar(nodo->izq, e);
		}
		else {
			_insertar(nodo->der, e);
		}
		_balanceo(nodo);
		return true;
	}
	long long _Cantidad(JNodo<J>* nodo) {
		if (nodo == nullptr) return 0;
		else {
			int cantidad_izquierda, cantidad_derecha;
			cantidad_izquierda = _Cantidad(nodo->izquierda);
			cantidad_derecha = _Cantidad(nodo->derecha);
			return 1 + cantidad_izquierda + cantidad_derecha;
		}
	}
	long long _Minimo(JNodo<J>* nodo) {
		if (nodo->izquierda == nullptr) return nodo->elemento;
		else {
			return _Minimo(nodo->izquierda);
		}
	}
	long long _Maximo(JNodo<J>* nodo) {
		if (nodo->derecha == nullptr) return nodo->elemento;
		else {
			return _Maximo(nodo->derecha);
		}
	}
	long long _Altura(JNodo<J>* nodo) {
		return nodo->altura;
	}

	void _inOrden(JNodo<J>* nodo) {
		if (nodo == nullptr) return;
		_inOrden(nodo->izq);
		procesar(nodo->elemento);
		_inOrden(nodo->der);
	}
	void _ascendente(JNodo<J>* nodo) {
		if (nodo == nullptr) return;
		_ascendente(nodo->izq);
		procesar(nodo->elemento);
		_ascendente(nodo->der);
	}
	void _descendente(JNodo<J>* nodo) {
		if (nodo == nullptr) return;
		_descendente(nodo->der);
		procesar(nodo->elemento);
		_descendente(nodo->izq);
	}
	void _inOrdenH(JNodo<J>* nodo) {
		if (nodo == nullptr) return;
		_inOrdenH(nodo->izq);
		procesar(nodo->altura);
		_inOrdenH(nodo->der);
	}

public:
	ArbolAVL() {
		this->procesar = nullptr;
		this->comparar = [](long long a, long long b) -> long long {return a - b;};
		this->raiz = nullptr;
	}
	void setProcesar(void(*nuevaFuncion)(J)) {
		this->procesar = nuevaFuncion;
	}
	bool Insertar(J e) {
		return _insertar(raiz, e);
	}
	void inOrden() {
		_inOrden(raiz);
	}
	void inOrdenH() {
		_inOrdenH(raiz);
	}
	bool Buscar(J e) {
		_Buscar(raiz, e);
	}
	JNodo<J>* Obtener(J e) {
		return _Obtener(raiz, e);
	}

	void ascendente() {
		_ascendente(this->raiz);
	}
	void descendente() {
		_descendente(this->raiz);
	}

	long long Cantidad() {
		return _Cantidad(raiz);
	}

	long long Altura() {
		return _Altura(raiz);
	}

	long long Minimo() {
		return _Minimo(raiz);
	}

	long long Maximo() {
		return _Maximo(raiz);
	}
};