#include<iostream>
#include"HashTable.hpp"
using namespace std;
using namespace hashTableConLista;
void main() {
	auto valor = [](int a) {
		return long long(a*a + 3);
	};
	HashTable<int, int>ht(15, valor);
	ht.insertarElemento(3, 17);
	ht.insertarElemento(8, 48);
	ht.insertarElemento(10, 3);
	ht.insertarElemento(15, 24);
	ht.showTable();
	ht.eliminarElemento(3);
	cout << endl;
	ht.showTable();
	system("pause>0");
}