#ifndef QUERY1ADT_H_INCLUDED
#define QUERY1ADT_H_INCLUDED

#define MAX_FMT 30
typedef struct query1CDT * query1ADT;

query1ADT newQuery1(void);
void add1(query1ADT,char * oaci, char * local, char * desc);
void freeQuery1(query1ADT);
void printQuery1(query1ADT,FILE* file);


#endif // QUERY1ADT_H_INCLUDED
