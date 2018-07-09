#include "TAD.h"//!!ATENTION placeholder
#include <string.h>
#include <stdlib.h>

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

static void copyAeropuerto(AeropuertoADT dest,AeroListaADT src){
	memcpy(dest,src,sizeof(*dest));
	dest->denominacion=malloc(strlen(src->denominacion));
	strcpy(dest->denominacion,src->denominacion);
}

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
void setAeropuertoTipo(AeropuertoADT aeropuerto,int tipo){
	aeropuerto->tipo=tipo;
}
void setAeropuertoDenominacion(AeropuertoADT aeropuerto,char *denominacion){
	aeropuerto->denominacion=malloc(strlen(denominacion)+1);
	strcpy(aeropuerto->denominacion,denominacion);
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
void getAeropuertoIATA(AeropuertoADT aeropuerto){
	return aeropuerto->iata;
}
void getAeropuertoTipo(AeropuertoADT aeropuerto){
	return aeropuerto->tipo;
}
void getAeropuertoDenominacion(AeropuertoADT aeropuerto){
	return aeropuerto->denominacion;
}
void getAeropuertoCondicion(AeropuertoADT aeropuerto){
	return aeropuerto->condicion;
}
void getAeropuertoTrafico(AeropuertoADT aeropuerto){
	return aeropuerto->trafico;
}


void freeAeropuerto(AeropuertoADT ap){
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
	//si es el primero lo agrega al principio
	if(aux==NULL||(c=memcmp(aux->aeropuerto.oaci,aeropuerto->oaci))<0){
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
			if(aux==NULL||(c=memcmp(aux->aeropuerto.oaci,aeropuerto->oaci))<0){
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
	while(!found && aux!=NULL && (c=memcmp(oaci,aux->aeropuerto.oaci,LONG_CODIGO_OACI))>=0){
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
	while(!found&&aux!=NULL&&c<0){
		if((c=memcmp(oaci,aux->aeropuerto.oaci))==0){
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
	AeroListaNode* aux=lista->first,aux1;
	while(aux!=NULL){
		aux1=aux->next;
		free(aux->aeropuerto.denominacion);
		free(aux);
		aux=aux1;
	}
	free(lista);
}
