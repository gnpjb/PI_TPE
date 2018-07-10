///!!ATENTION placeholder
#include "TAD.h"
#include <string.h>
#include <stdlib.h>

//estructura para manejo de datos de aeropuertos
typedef struct AeropuertoCDT{
	char local[LONG_CODIGO_LOCAL+1];
	char oaci[LONG_CODIGO_OACI+1];
	char iata[LONG_CODIGO_IATA+1];
	char tipo;
	char *denominacion;
	char condicion;
	char trafico;
}AeropuertoCDT;

static void copyAeropuerto(AeropuertoADT dest,AeropuertoADT src){
	memcpy(dest,src,sizeof(*dest));
	if(src->denominacion!=NULL){
		dest->denominacion=malloc(strlen(src->denominacion)+1);
		strcpy(dest->denominacion,src->denominacion);
	}
}

AeropuertoADT newAeropuerto(){
	AeropuertoADT resp=calloc(1,sizeof(*resp));
	return resp;
}

void setAeropuertoLocal(AeropuertoADT aeropuerto, char *local){
	if(local!=NULL&&strlen(local)==LONG_CODIGO_LOCAL)
		strcpy(aeropuerto->local,local);
}
void setAeropuertoOACI(AeropuertoADT aeropuerto, char *oaci){
	if(oaci!=NULL&&strlen(oaci)==LONG_CODIGO_OACI)
		strcpy(aeropuerto->oaci,oaci);
}
void setAeropuertoIATA(AeropuertoADT aeropuerto, char *iata){
	if(iata!=NULL&&strlen(iata)==LONG_CODIGO_IATA){
		strcpy(aeropuerto->iata,iata);
	}
}
void setAeropuertoTipo(AeropuertoADT aeropuerto,int tipo){
	aeropuerto->tipo=tipo;
}
void setAeropuertoDenominacion(AeropuertoADT aeropuerto,char *denominacion){
	if(denominacion!=NULL&&denominacion[0]!=0){
		aeropuerto->denominacion=malloc(strlen(denominacion)+1);
		strcpy(aeropuerto->denominacion,denominacion);
	}
}
void setAeropuertoCondicion(AeropuertoADT aeropuerto, char condicion){
	aeropuerto->condicion=condicion;
}
void setAeropuertoTrafico(AeropuertoADT aeropuerto, char trafico){
	aeropuerto->trafico=trafico;
}


char* getAeropuertoLocal(AeropuertoADT aeropuerto){
	return aeropuerto->local;
}
char* getAeropuertoOACI(AeropuertoADT aeropuerto){
	return aeropuerto->oaci;
}
char* getAeropuertoIATA(AeropuertoADT aeropuerto){
	return aeropuerto->iata;
}
char getAeropuertoTipo(AeropuertoADT aeropuerto){
	return aeropuerto->tipo;
}
char* getAeropuertoDenominacion(AeropuertoADT aeropuerto){
	return aeropuerto->denominacion;
}
char getAeropuertoCondicion(AeropuertoADT aeropuerto){
	return aeropuerto->condicion;
}
char getAeropuertoTrafico(AeropuertoADT aeropuerto){
	return aeropuerto->trafico;
}


void freeAeropuerto(AeropuertoADT ap){
	if(ap->denominacion!=NULL)
		free(ap->denominacion);
	free(ap);
}


//lista de aeropuertos

typedef struct AeroListaNode{
	struct AeroListaNode* next;
	AeropuertoCDT aeropuerto;
}AeroListaNode;


typedef struct AeroListaCDT{
	AeroListaNode* first;
	AeroListaNode* iterator;
}AeroListaCDT;

AeroListaADT newAeroLista(){
	AeroListaADT resp=calloc(1,sizeof(*resp));
	return resp;
}


void addAeroLista(AeroListaADT lista,AeropuertoADT aeropuerto){
	AeroListaNode *aux=lista->first,*aux1;
	int c;
	if(aeropuerto==NULL){
		return;
	}
	//si es el primero lo agrega al principio
	if(aux==NULL||(c=strcmp(aux->aeropuerto.oaci,aeropuerto->oaci))<0){
		lista->first=malloc(sizeof(*lista->first));
		lista->first->next=aux;
		copyAeropuerto(&lista->first->aeropuerto,aeropuerto);
	}
	//si c==0 no se hace nada
	else if(c>0){
		aux1=aux;
		aux=aux->next;
		int found=0,alreadyIn=0;
		//lo busca, si encuentra uno con el mismo oaci no hace nada
		//sino cuando encuentra el lugar lo agrega
		while(!found&&!alreadyIn){
			if(aux==NULL||(c=strcmp(aux->aeropuerto.oaci,aeropuerto->oaci))<0){
				found=1;
			}
			else if(c==0){
				alreadyIn=1;
			}
			else{
				aux=aux->next;
			}
		}
		if(!alreadyIn){
			aux1->next=malloc(sizeof(*aux1->next));
			aux1->next->next=aux;
			copyAeropuerto(&aux1->next->aeropuerto,aeropuerto);
		}
	}
}

int enAeroLista(AeroListaADT lista, char oaci[]){
	AeroListaNode* aux=lista->first;
	int found=0,c;
	if(oaci==NULL||oaci[0]==0){
		return 0;
	}
	while(!found && aux!=NULL && (c=strcmp(oaci,aux->aeropuerto.oaci))>=0){
		if(c==0){
			found=1;
		}
		aux=aux->next;
	}
	return found;
}


AeropuertoADT getAeropuertoFromAeroLista(AeroListaADT lista,char oaci[]){
	int c,found=0;
	AeroListaNode *aux;
	AeropuertoADT resp=NULL;
	if(oaci==NULL||oaci[0]=0){
		return NULL;
	}
	while(!found&&aux!=NULL&&c<0){
		if((c=strcmp(oaci,aux->aeropuerto.oaci))==0){
			found=1;
		}
		else{
			aux=aux->next;
		}
	}
	if(found){
		resp=&aux->aeropuerto;
	}
	return resp;
}


void freeAeroLista(AeroListaADT lista){
	AeroListaNode *aux=lista->first,*aux1;
	while(aux!=NULL){
		aux1=aux->next;
		free(aux->aeropuerto.denominacion);
		free(aux);
		aux=aux1;
	}
	free(lista);
}

/*
-------------------------------------------------------------------------------
vuelos:
*/

typedef struct vueloCDT{
	VTFecha fecha;
	VTHora hora;
	char clasificacion;
	char tipoDeMov;
	char origOaci[LONG_CODIGO_OACI+1];
	char destOaci[LONG_CODIGO_OACI+1];
	char *nomAerolin;
	char *aeronave;
	char anAPC;
}vueloCDT;

vueloADT newVuelo(){
	vueloADT resp=calloc(1,sizeof(*resp));
	return resp;
}

void setVueloFecha(vueloADT vuelo,VTFecha fecha){
	vuelo->fecha=fecha;
}
void setVueloHora(vueloADT vuelo,VTHora hora){
	vuelo->hora=hora;
}
void setVueloClasificacion(vueloADT vuelo,char clasificacion){
	vuelo->clasificacion=clasificacion;
}
void setVueloTipoDeMov(vueloADT vuelo,char tipoDeMov){
	vuelo->tipoDeMov=tipoDeMov;
}
void setVueloOrigOaci(vueloADT vuelo,char origOaci[]){
		strcpy(vuelo->origOaci,origOaci);
}
void setVueloDestOaci(vueloADT vuelo,char destOaci[]){
		strcpy(vuelo->destOaci,destOaci);
}
void setVueloNomAerolin(vueloADT vuelo,char *nomAerolin){
	if(nomAerolin!=NULL&&nomAerolin[0]!=0){
		vuelo->nomAerolin=malloc(strlen(nomAerolin));
		strcpy(vuelo->nomAerolin,nomAerolin);
	}
}
void setVueloAeronave(vueloADT vuelo,char *aeronave){
	if(aeronave!=NULL&&aeronave[0]!=0){
		vuelo->aeronave=malloc(strlen(aeronave));
		strcpy(vuelo->aeronave,aeronave);
	}
}
void setVueloANAPC(vueloADT vuelo,char anAPC){
	vuelo->anAPC=anAPC;
}


VTFecha getVueloFecha(vueloADT vuelo){
	return vuelo->fecha;
}
VTHora getVueloHora(vueloADT vuelo){
	return vuelo->hora;
}
char getVueloClasificacion(vueloADT vuelo){
	return vuelo->clasificacion;
}
char getVueloTipoDeMov(vueloADT vuelo){
	return vuelo->tipoDeMov;
}
char *getVueloOrigOaci(vueloADT vuelo){
	return vuelo->origOaci;
}
char *getVueloDestOaci(vueloADT vuelo){
	return vuelo->destOaci;
}
char* getVueloNomAerolin(vueloADT vuelo){
	return vuelo->nomAerolin;
}
char* getVueloAeronave(vueloADT vuelo){
	return vuelo->aeronave;
}
char getVueloANAPC(vueloADT vuelo){
	return vuelo->anAPC;
}

void freeVuelo(vueloADT vuelo){
	free(vuelo->nomAerolin);
	free(vuelo->aeronave);
	free(vuelo);
}
