#include "TAD.h"//!!ATENTION placeholder


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

AeropuertoADT newAeropuerto(){
	AeropuertoADT resp=calloc(1,sizeof(*resp));
	return resp;
}

void setAeropuertoLocal(AeropuertoADT aeropuerto, char local[]){
	memcpy(aeropuerto->local,local,LONG_CODIGO_LOCAL);
}



void setAeropuertoOACI(AeropuertoADT aeropuerto, char oaci[]){
	memcpy(aeropuerto->oaci,oaci,LONG_CODIGO_OACI);
}



void setAeropuertoIATA(AeropuertoADT aeropuerto, char iata[]){
	memcpy(aeropuerto->iata,iata,LONG_CODIGO_IATA);
}

void freeAeropuerto(AeropuertoADT ap){
	free(ap->denominacion);
	free(ap);
}


//estructura para el manejo de datos de vuelos
typedef struct vueloCDT{
	VTFecha fecha;
	VTHora hora;
	char clasificacion;
	char tipoDeMov;
	char origOaci[4];
	char destOaci[4];
	char *nomAerolin;
	char *aeronave;
	char anAPC;
}vueloCDT;

vueloADT newVuelo(){
	vueloADT resp=calloc(1,sizeof(*resp));
	return resp;
}

void freeVuelo(vueloADT v){
	free(v->nomAerolin);
	free(v->aeronave);
	free(v);
}
