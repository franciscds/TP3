#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    long int N,M;
    int *populacao,thread_ID;
    int soma;
}dados;

int* MelhorSoma(int n,int m);
dados* LeEntrada();
void MaxPop(int n,int *v);
dados* liberaMapa(int N, dados* Map);
dados* alocaMapa(int N, int M);

#endif // IO_H_INCLUDED
