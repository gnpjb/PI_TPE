#include "query3ADT.h"

typedef struct query3CDT{
    long days[7];
} query3CDT;

query3ADT newQuery3(void){
    return calloc(1, sizeof(query3CDT));
}

void add3(query3ADT query, int day){

    query->days[day]++;
}

void freeQuery3(query3ADT query){
    free(query);
}
