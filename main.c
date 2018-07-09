#include <stdio.h>

#include "query1ADT.h"
#include "query2ADT.h"
#include "query3ADT.h"
#include "query4ADT.h"
#include "TAD.h"



int main( int argc, char *argv[] ){
	if(int argc==2){
		int year;
		sscanf(argv[1],"%d",&year);
		if(year>=2014 && year<=2018){

			/*
				1. Pasar todos los aeropuertos a memoria, supongo
				que con estructuras de 4 campos (oaci, iata,
				desc, local), los que son suficientes para las
				4 queries.
				2. Leer vuelo por vuelo (while y scanf o strtok, lo
				que convenga), por cada vuelo ejecutar los process
				3. Imprimir todo
			*/

		}
		else{
			printf("Argumento incorrecto. El argumento debe ser un año entre 2014 y 2018\n");
			return 2;
		}
	}
	else{
		printf("Cantidad de argumentos incorrecta(debe ser 1)\n");
		return 1;
	}
}
