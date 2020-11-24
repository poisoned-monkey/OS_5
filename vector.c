#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

void vectorInit(vector *v)
{
	v->data = NULL;
	v->size = 0;
	v->count = 0;
}

int vectorCount(vector *v)
{
	return v->count;
}
void vectorPrint(vector *v) {
    for (int i = 0; i<v->count; ++i) {
        printf("%lf ",v->data[i]);
    }
    printf("\n");
}
void vectorAdd(vector *v, double e)
{
	if (v->size == 0) {
		v->size = 10;
		v->data = malloc(sizeof(double*) * v->size);
	}


	if (v->size == v->count) {
		v->size *= 2;
		v->data = realloc(v->data, sizeof(void*) * v->size);
	}

	v->data[v->count] = e;
	v->count++;
}

void vectorSet(vector *v, int index, double d)
{
	if (index >= v->count) {
		return;
	}

	v->data[index] = d;
}

double vectorGet(vector *v, int index)
{
	if (index >= v->count) {
		return;
	}

	return v->data[index];
}

void vectorDelete(vector *v, int index)
{
	if (index >= v->count) {
		return;
	}

	for (int i = index; i<v->count-1; ++i) {
        v[i] = v[i+1];
    }
	v->count--;
    
}

void vectorFree(vector *v)
{
	free(v->data);
}