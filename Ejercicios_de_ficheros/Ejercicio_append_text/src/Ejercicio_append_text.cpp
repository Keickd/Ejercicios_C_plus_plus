//============================================================================
// Name        : Ejercicio_append_text.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

void append();

int main() {
	append();
	return 0;
}

void append(){

	ofstream archivo;

	archivo.open("prueba.txt", ios::app);

	if(archivo.fail()){
		cout<<"No se pude abrir"<<endl;
		exit(1);
	}

	archivo<<"soy texto añadido";

	archivo.close();
}
