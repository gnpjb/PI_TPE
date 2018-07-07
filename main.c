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


			//aca sucede el programa

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
