#ifndef QUERY4ADT_H_INCLUDED
#define QUERY4ADT_H_INCLUDED

enum{Q4_LOCAL,Q4_NO_LOCAL}

query4ADT newQuery4();
//locFlag es un flag que dicta si el oaci es de un aeropuerto local o no local
void add4(query4ADT query,char oaciDes[],char locFlagDes,char oaciAter[],char locFlagAter);
void freeQuery4(query4ADT query);

typedef struct query4CDT* query4ADT;

#endif
