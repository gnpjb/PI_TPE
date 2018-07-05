#include "TAD.h"//!!ATENTION placeholder
#define LONG_CODIGO_LOCAL 3
#define LONG_CODIGO_OACI 4
#define LONG_CODIGO_IATA 4
//definicion de constantes que usara el TAD AeropuertoCDT
enum{AERODROMO,HELIPUERTO};
enum{PUBLICO,PRIVADO};
enum{NACIONAL, INTERNACIONAL};

//estructura para manejo de datos de aeropuertos
typedef struct AeropuertoCDT{
	char local[LONG_CODIGO_LOCAL];
	char oaci[LONG_CODIGO_OACI];
	char iata[LONG_CODIGO_IATA];
	char tipo;
	int *denominacion;
	char condicion;
	char trafico;
}AeropuertoCDT;

void setAeropuertoLocal(AeropuertoADT aeropuerto, char local[]){
	for( int i=0 ; i<LONG_CODIGO_LOCAL ; i++){
		aeropuerto->local[i]=local[i];
	}
}

void setAeropuertoOACI(AeropuertoADT aeropuerto, char oaci[]){
	for(int i=0; i<LONG_CODIGO_OACI; i++){
		aeropuerto->oaci[i]=oaci[i];
	}
}

void setAeropuertoIATA(AeropuertoADT aeropuerto, char iata[]){
	for(int i=0; i<LONG_CODIGO_IATA; i++){
		aeropuerto->iata[i]=iata[i];
	}
}
