#ifndef QUERY1ADT_H_INCLUDED
#define QUERY1ADT_H_INCLUDED

#define MAX_FMT 30
typedef struct query1CDT * query1ADT;

query1ADT newQuery1(void);
void add(query1ADT, char*, char*);
void freeQuery1(query1ADT);
void printQuery1(query1ADT);


#endif // QUERY1ADT_H_INCLUDED
