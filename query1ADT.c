#include "query1ADT.h"
#include <string.h>
#include <stdlib.h>

typedef struct query1CDT{
    q1Node * first;
    int count;
} query1CDT;

typedef struct q1Node{

    char oaci[5];
    char local[4];
    char *desc;
    long cant;
    struct q1Node * next;

}q1Node;

query1ADT newQuery1(){
    return calloc(1, sizeof(query1CDT));
}

void add1(query1ADT query, char * oaci, char * local, char * desc){

    q1Node *aux;

    /*Si la lista esta vacia o el OACI del aeropuerto es menor (en orden alfabetico)
    que el primero de la lista, crear un nodo dedicado a ese aeropuerto e inicializar
    la cantidad de movimientos con 1*/

    if(query->first==NULL || strcmp(oaci, query->first->oaci)<0){

        aux=malloc(sizeof(q1Node));
        aux->desc = malloc(strlen(desc)+1);
        strcpy(aux->desc, desc);
        aux->cant=1;
        strcpy(aux->oaci, oaci);
        strcpy(aux->local, local);
        aux->next=query->first;
        query->first=aux;

        }

    /*Si el primero de la lista tiene el OACI que buscamos, agregar uno a la cantidad
    de movimientos*/

    else if(strcmp(oaci, query->first->oaci)==0){

        query->first->cant++;
    }

    /*En cualquier otro caso, buscar hasta encontrar el OACI o crear un nuevo nodo si
    no se encontro*/

    else{
		int found=0;
        aux=query->first;
        while(aux->next!=NULL && !(strcmp(oaci, aux->next->oaci)<0) && !found){
            if(strcmp(oaci, aux->next->oaci)==0){

                aux->next->count++;
                found=1;
            }
        }
		if(!found){
	        q1Node * new = malloc(sizeof(q1Node));
	        new->desc = malloc(strlen(desc)+1);
	        strcpy(new->desc, desc);
	        strcpy(new->oaci, oaci);
	        strcpy(new->local, local);
	        new->cant++;
	        new->next=aux->next;
	        aux->next=new;
		}
    }

}

void printQuery1(query1ADT query, FILE * fd){

    if(query==NULL || query->first==NULL)
        return;
    char * fmt = malloc(MAX_FMT);

    fprintf(fd, "\n\n***Query 1: Cantidad de movimientos***\n\noaci;local;desc;cant_movs\n");
    for(q1Node aux = query->first; aux!=NULL; aux=aux->next){
        sprintf(fmt, "%%4s;%%3s;%%%ds;%%d\n", strlen(aux->desc));
        fprintf(fd, fmt, aux->oaci, aux->local, aux->desc, aux->cant);
    }
    free(fmt);
    return;

}

void freeQuery1(query1ADT query){

    q1Node * aux = query->first, aux1;
    while(aux!=NULL){

        aux1 = aux->next;
        free(aux->desc);
        free(aux);
        aux=aux1;
    }
}
