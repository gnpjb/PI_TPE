#include "query4ADT.h"
#define LONG_OACI 4
#define ATER 1
#define DES 0

typedef struct query4Node{
	struct query4Node* next;
	char otroOaci[LONG_OACI];
	long aterrizajes;
	long despegues;
}query4Node;

typedef struct query4Head{
	struct query4Head* next;
	query4Node* first;
	char localOaci[LONG_OACI];
}query4Head;

//lista de nodos a listas de entradas de query4
typedef struct query4CDT{
	query4Head* first;
}query4CDT;


query4ADT newQuery4(){
	query4ADT resp=calloc(1,sizeof(*resp));
	return resp;
}

static void addToHead(query4Head* head, char otroOaci[],int tipoDeMov){

	//dado el head busca el otrooaci y agrega a ese o lo crea si no existe

}
//locFlagDes y locFlagAter son flags que dicen si el aeropuerto es local o no
void add4(query4ADT query,char oaciDes[],char locFlagDes,char oaciAter[],char locFlagAter){
	if(locFlagDes==1){

		int c;//usado para el resultado de una funcion de comparacion
		query4Head* aux;


		//si no hay nada en first o hay que insertar antes de first
		if(query->first==NULL||(c=memcmp(oaciDes,query->first->localOaci)<0)){
			aux=query->first;
			query->first=malloc(sizeof(*newFirst));
			query->first->next=aux;
			memcpy(query->first->localOaci,oaciDes,LONG_OACI);
			query->first->first=NULL
			addToHead(query->first);
		}


		else if(c==0){

			// si hay que agregarlo al primero ya lo hacemos

		}


		else{
			aux=query->first->next;
			//sino se recorre hasta encontrar donde agregarlo;
			while( aux!=NULL && (c=memcmp(oaciDes,aux->localOaci)) < 0 ){
				if(c==0)
			}
		}
	}
}


//funciones de liberacion de memoria
static void freeQuery4Head(query4Head* qHead){
	query4Node* aux=qHead->next,aux1;
	while(aux!=NULL){
		aux1=aux->next;
		free(aux);
		aux=aux1;
	}
	free(qHead);
}

void freeQuery4(query4ADT query){
	query4Head* aux=query->first,aux1;
	while(aux!=NULL){
		aux1=aux->next;
		freeQuery4Head(aux);
		aux=aux1;
	}
	free(query);
}
