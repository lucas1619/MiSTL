#pragma once
#include"Lista.hpp"
#include<vector>
#include<functional>
using namespace std;
namespace hashTableConLista {
	using namespace listaSimple;
	template <class Key, class Value>
	class HashTable
	{
	private:
		vector<Lista<NodoDeHash::Nodo<Key, Value>>*> * table;
		function<long long(Key)>encrypt;
		long long myEncryt(long long ePublicKey) {
			long long publicKeyEncrypt = (long long) pow(ePublicKey * 4, 2) * 2;
			return publicKeyEncrypt;
		}
		long long hashFunction(Key publicKey) {
			long long ePublicKey = encrypt(publicKey);
			long long privateKey = myEncryt(ePublicKey) % table->size();
			return privateKey;
		}
	public:
		HashTable(long long size, function<long long(Key)>encrypt) {
			table = new vector<Lista<NodoDeHash::Nodo<Key, Value>>*>(size);
			for (long long i = 0; i < size; i++)
			{
				table->at(i) = new Lista<NodoDeHash::Nodo<Key, Value>>();
			}
			this->encrypt = encrypt;
		}
		~HashTable() {
			table->clear();
			delete table;
		}
		void insertarElemento(Key publicKey, Value elemento) {
			long long privateKey = this->hashFunction(publicKey);
			table->at(privateKey)->insertarAlFinal(NodoDeHash::Nodo<Key, Value>(publicKey, elemento));
		}
		void eliminarElemento(Key publicKey) {
			long long privateKey = this->hashFunction(publicKey);
			Lista<NodoDeHash::Nodo<Key, Value>> * puntero = table->at(privateKey);
			for (long long i = 0; i < puntero->obtenerTamanho(); i++)
			{
				if (puntero->obtenerElementoEnPosicion(i).publicKey == publicKey)
				{
					puntero->eliminarEnPosicion(i);
					break;
				}
			}
		}
		bool estaVacia() {
			return this->table->empty();
		}
		long long obtenerNumeroDeFilas() {
			return this->table->size();
		}
		void showTable(){
			for (long long i = 0; i < table->size(); i++)
			{
				cout << i;
				for (long long j = 0; j < table->at(i)->obtenerTamanho(); j++)
				{
					cout << "--->" << table->at(i)->obtenerElementoEnPosicion(j).value;
				}
				cout << endl;
			}
		}
	};

}