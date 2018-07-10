#include <stdio.h>
#include <string.h>
#include "TAD.h"
#include "cargarAeropuertos.h"

#define DELIM ";"
#define MAX_LONG_LINEA 500

AeroListaADT cargarAeropuertos(char *filename){

	FILE* f=fopen(filename,"rt");
	if(f==NULL){
		return NULL;
	}

	AeroListaADT resp=newAeroLista();
	AeropuertoADT toAdd=newAeropuerto();

	char linea[MAX_LONG_LINEA];

	int c,i;
	char *field;
	while(!feof(f)){
		i=0;
		while((c=fgetc(f))!='\n'){
			linea[i]=c;
			i++;
		}
		linea[i]=0;

		//primer field es local
		field=strtok(linea,DELIM);
		setAeropuertoLocal(toAdd,field);

		//segundo field es oaci, de que este exista depende si es valido o no
		field=strtok(NULL,DELIM);
		if(strlen(field)==3){
			setAeropuertoOACI(toAdd,field);

			//tercer field es iata
			field=strtok(NULL,DELIM);
			setAeropuertoIATA(toAdd,field);

			//cuarto field es tipo
			field=strtok(NULL,DELIM);
			if(strcmp("Helipuerto",field)==0){
				setAeropuertoTipo(toAdd,A_HELIPUERTO);
			}
			else{
				setAeropuertoTipo(toAdd,A_AERODROMO);
			}

			//quinto field es denominacion
			field=strtok(NULL,DELIM);
			setAeropuertoDenominacion(toAdd,field);

			//luego ignoramos los fields que no necesitamos
			for(int k=0;k<8;k++){
				strtok(NULL,DELIM);
			}

			//despues tomamos el field condicion
			field=strtok(NULL,DELIM);
			if(strcmp(field,"PUBLICO")==0){
				setAeropuertoCondicion(toAdd,A_PUBLICO);
			}
			else{
				setAeropuertoCondicion(toAdd,A_PRIVADO);
			}

			//ignoramos los siguientes 4 fields
			for(int k=0;k<4;k++){
				strtok(NULL,DELIM);
			}

			//tomamos trafico
			field=strtok(NULL,DELIM);
			if(strcmp("Nacional",field)==0){
				setAeropuertoTrafico(toAdd,A_NACIONAL);
			}
			else{
				setAeropuertoTrafico(toAdd,A_INTERNACIONAL);
			}

			addAeroLista(resp,toAdd);
		}
	}
	freeAeropuerto(toAdd);
	fclose(f);
	return resp;
}
