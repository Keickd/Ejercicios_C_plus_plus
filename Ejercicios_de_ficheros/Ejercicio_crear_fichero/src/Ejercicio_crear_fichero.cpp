
#include <iostream>
#include <fstream>
#include <stdlib.h>


using namespace std;

void escribir();

int main() {
	escribir();
	return 0;
}


void escribir(){

	ofstream archivo;
	string nombre, frase;

	cout<<"Escribe el nombre: "<<endl;
	getline(cin, nombre);

	archivo.open(nombre.c_str(), ios::out);

	cout<<"Escribe una frase: "<<endl;
	getline(cin, frase);

	archivo<<frase;

	archivo.close();
}
