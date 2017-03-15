#include "utility.h"

int* SumStruct(dados* arg, int N)
{
    int i,*v_maximos;
    v_maximos = (int*)malloc(N*sizeof(int));/*Aloca vetor pra contabilizar soma*/

    for( i=0; i< N; i++)/*recebe a soma de todas as structs*/
    {
        v_maximos[i] = arg[i].soma;
    }
    return v_maximos;
}

int maiorSoma(int numero_1, int numero_2)
{
    int maior=0;

    if( numero_1 > numero_2)
    {
        maior = numero_1;
    }
    else
    {
        maior = numero_2;
    }
    return maior;
}

