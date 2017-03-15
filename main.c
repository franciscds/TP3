#include "io.h"
#include "thread_process.h"
#include "utility.h"

int main(int argc,char** argv)
{

    int n_threads,*vetor_maximos;
    dados *mapa;
    if( argc >0)
    {
        n_threads = atoi(argv[1]);/*Numero de threads*/
    }
    mapa = LeEntrada();
    mapa = processa_threads(n_threads,mapa);
    vetor_maximos = SumStruct(mapa,mapa->N);
    MaxPop(mapa->M,vetor_maximos);/*Encontra maior numero de pessoas para dominar*/
    mapa = liberaMapa(mapa->N,mapa);
    return 0;
}
