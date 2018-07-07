#ifndef QUERY3ADT_H_INCLUDED
#define QUERY3ADT_H_INCLUDED

typedef struct query3CDT * query3ADT;
enum {LUN=0,MAR,MIE,JUE,VIE,SAB,DOM};

query3ADT newQuery3(void);
void add3(query3ADT, int);
void freeQuery3(query3ADT);
void printQuery3(query3ADT);

#endif // QUERY3ADT_H_INCLUDED
