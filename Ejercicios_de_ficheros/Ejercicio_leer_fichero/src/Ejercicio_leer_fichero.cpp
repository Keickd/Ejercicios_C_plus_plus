//============================================================================
// Name        : Ejercicio_leer_fichero.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

void leer();

int main() {
	leer();
	return 0;
}

void leer(){
	ifstream archivo;
	string texto;

	archivo.open("prueba.txt", ios::in);

	if(archivo.fail()){
		cout<<"No se puede abrir el archivo"<<endl;
		exit(1);
	}

	while(!archivo.eof()){
		getline(archivo, texto);
	}
	cout<<texto<<endl;

	archivo.close();


}
