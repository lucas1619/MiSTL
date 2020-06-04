//
// Created by lucasmoreno on 17/05/20.
//

#ifndef MISTL_NODO_HPP
#define MISTL_NODO_HPP
namespace enlaceSimple{
    template <class T>
    struct Nodo{
        T elemento;
        Nodo * siguiente;
    };
}
namespace enlaceDoble{
    template <class G>
    struct Nodo{
        G elemento;
        Nodo * siguiente;
        Nodo* anterior;
    };
}
namespace enlaceTriple{
    template <class W>
    struct Nodo{
        W elemento;
        Nodo * siguiente;
        Nodo* anterior;
        Nodo* otroEnlace;
    };
}
namespace NodoDeHash {
	template<class Key, class Value>
	struct Nodo
	{
		Key publicKey;
		Value value;
		Nodo(){}
		Nodo(Key publicKey, Value value) : publicKey(publicKey), value(value) {}
	};
	
}
#endif //MISTL_NODO_HPP
