//============================================================================
// Name        : Ejercicios_binarios.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdio.h>
#include <stdlib.h> //para el NULL

typedef struct Persona Persona;
//https://www.ibm.com/docs/en/i/7.3?topic=functions-fopen-open-files
struct Persona{
	char *nombre;
	int edad;
	double salario;
};


int escribirArchivo(Persona [], int, const char *);
int leerArchivo(Persona [], int, const char *);

void muestraEmpleados(Persona [], int);
void muestraPersona(Persona);

int main() {

	Persona empleados[] = {
			{"Juan", 25, 1250},
			{"Tomas", 15, 50},
			{"James", 45, 4500}
	};


	int tam = sizeof(empleados) / sizeof(Persona);

	Persona empleadosLectura[tam];

	if(!escribirArchivo(empleados, tam, "Binario.dat")){ //bin
		printf("Error de escritura");
		return 1;
	}

	if(!leerArchivo(empleadosLectura, tam, "Binario.dat")){ //bin
		printf("Error de lectura");
		return 1;
	}

	muestraEmpleados(empleadosLectura, tam);
	return 0;
}


int escribirArchivo(Persona empleados[], int tam, const char *nombreArchivo){
	FILE *file;

	file = fopen(nombreArchivo, "wb"); //w de write, b de binary
	if(file == NULL){
		return 0;
	}

	for(int i = 0;i < tam; i++){
		fwrite(&empleados[i], sizeof(Persona), 1, file);
		//size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
	}
	fflush(file);
	fclose(file);
	return 1;
}

int leerArchivo(Persona empleados[], int tam, const char *nombreArchivo){
	FILE *file;

	file = fopen(nombreArchivo, "rb"); //r de read, b de binary
	if(file == NULL){
		return 0;
	}

	for(int i = 0;i < tam; i++){
		fread(&empleados[i], sizeof(Persona), 1, file);
	}
	fclose(file);
	return 1;
}

void muestraEmpleados(Persona empleados[], int tam){
	for(int i = 0; i < tam; i++){
		muestraPersona(empleados[i]);
		printf("\n");
	}
}

void muestraPersona(Persona persona){
	printf("Nombre: %s\n", persona.nombre);
	printf("Edad: %d\n", persona.edad);
	printf("Salario: %lf\n", persona.salario);
}
