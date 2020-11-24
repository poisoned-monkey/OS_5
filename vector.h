#ifndef VECTOR_H__
#define VECTOR_H__

typedef struct vector_ {
    double* data;
    int size;
    int count;
} vector;

void vectorInit(vector* v);
int vectorCount(vector* v);
void vectorAdd(vector* v, double d);
void vectorSet(vector* v, int index, double d);
double vectorGet(vector* v, int index);
void vectorPrint(vector* v);

void vectorDelete(vector* v, int index);
void vectorFree(vector* );

#endif