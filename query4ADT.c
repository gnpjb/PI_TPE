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

//dado el head busca el otrooaci y agrega a ese o lo crea si no existe
static void addToHead(query4Head* head, char otroOaci[],int tipoDeMov){
	int c;
	query4Node* aux;

	//el objetivo de esta serie de if-else es encontrar el otroOaci o crearlo
	//si no existiese
	if(head->first==NULL||(c=memcmp(otroOaci,head->first->otroOaci,LONG_OACI)<0)){

		aux=head->first;
		head->first=malloc(sizeof(*head->first));
		head->first->next=aux;
		head->first->aterrizajes=0;
		head->first->despegues=0;
		memcpy(head->first->otroOaci,otroOaci,LONG_OACI);
		aux=head->first;

	}
	else if(c==0){

		aux=head->first;

	}
	else{
		int found=0;
		query4Node* wAux,wAuxPrev;
		wAuxPrev=head->first;
		wAux=wAuxPrev->next;
		while(!found){
			if(wAux==NULL||(c=memcmp(otroOaci,wAux->otroOaci))<0){
				wAuxPrev->next=malloc(sizeof(*wAuxPrev->next));
				memcpy(wAuxPrev->next->otroOaci,otroOaci,LONG_OACI);
				wAuxPrev->next->aterrizajes=0;
				wAuxPrev->next->despegues=0;
				wAuxPrev->next->next=wAux;
				found=1;
			}
			else if(c==0){
				aux=wAux;
				found=1;
			}
			else{
				wAuxPrev=wAux;
				wAux=wAux->next;
			}
		}
	}

	if(tipoDeMov==ATER){
		aux->aterrizajes++;
	}
	else if(tipoDeMov==DES){
		aux->despegues++;
	}
}
//locFlagDes y locFlagAter son flags que dicen si el aeropuerto es local o no
void add4(query4ADT query,char oaciDes[],char locFlagDes,char oaciAter[],char locFlagAter){
	if(locFlagDes==1){

		int c;//usado para el resultado de una funcion de comparacion
		query4Head* aux;


		//si no hay nada en first o hay que insertar antes de first
		if(query->first==NULL||(c=memcmp(oaciDes,query->first->localOaci,LONG_OACI)<0)){
			aux=query->first;
			query->first=malloc(sizeof(*newFirst));
			query->first->next=aux;
			memcpy(query->first->localOaci,oaciDes,LONG_OACI);
			query->first->first=NULL
			addToHead(query->first,oaciAter,DES);
		}


		else if(c==0){

			addToHead(query->first,oaciAter,DES);

		}

		else{
			int found=0;
			query4Head* aux1=query->first;
			aux=query->first->next;
			//sino se recorre hasta encontrar donde agregarlo
			while( !found ){
				if(aux==NULL||(c=memcmp(oaciDes,aux->localOaci,LONG_OACI))<0){
					aux1->next=malloc(sizeof(*aux1->next));
					aux1->next->first=NULL;
					aux1->next->next=aux;
					memcpy(aux1->next->localOaci,oaciDes,LONG_OACI);
					aux=aux1->next;
					found=1;
				}
				if(c==0){
					found=1;
				}
				else{
					aux1=aux;
					aux=aux->next;
				}
			}
			addToHead(aux,oaciAter,DES);
		}
	}
	if(locFlagAter==1){

		int c;//usado para el resultado de una funcion de comparacion
		query4Head* aux;


		//si no hay nada en first o hay que insertar antes de first
		if(query->first==NULL||(c=memcmp(oaciAter,query->first->localOaci,LONG_OACI)<0)){
			aux=query->first;
			query->first=malloc(sizeof(*newFirst));
			query->first->next=aux;
			memcpy(query->first->localOaci,oaciAter,LONG_OACI);
			query->first->first=NULL
			addToHead(query->first,oaciDes,ATER);
		}


		else if(c==0){

			addToHead(query->first,oaciDes,ATER);

		}

		else{
			int found=0;
			query4Head* aux1=query->first;
			aux=query->first->next;
			//sino se recorre hasta encontrar donde agregarlo
			while( !found ){
				if(aux==NULL||(c=memcmp(oaciAter,aux->localOaci,LONG_OACI))<0){
					aux1->next=malloc(sizeof(*aux1->next));
					aux1->next->first=NULL;
					aux1->next->next=aux;
					memcpy(aux1->next->localOaci,oaciAter,LONG_OACI);
					aux=aux1->next;
					found=1;
				}
				if(c==0){
					found=1;
				}
				else{
					aux1=aux;
					aux=aux->next;
				}
			}
			addToHead(aux,oaciDes,ATER);
		}
	}
}

static void printQuery4Head(query4Head* head, FILE * fd){
	query4Node* aux=head->first;
	while(head!=NULL){
		fprintf(fd, "%.4s;%.4s;%ld;%ld\n",head->localOaci,aux->otroOaci,aux->aterrizajes,aux->despegues);
	}
}

void printQuery4(query4ADT query, FILE * fd){

    if(query!=NULL && query->first!=NULL){
	    fprintf(fd, "oaciLocal;otroOaci;vuelosHacia;vuelosDesde\n");
	    for(query4Head aux = query->first; aux!=NULL; aux=aux->next){
			printQuery4Head(aux,fd);
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
