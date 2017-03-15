#include "thread_process.h"
dados* processa_threads(int n_threads,dados *arg)
{
    pthread_t thread_ID[n_threads];
    int i,j,k=0,rt;
    int mod = arg->N%n_threads;
    int cont = 0;
    int n = arg->N/n_threads;
    if( mod == 0)/*cada thread realiza N/n_threads operacoes */
    {
        i=0;
        while( cont < n)
        {
            for(k=0; k < n_threads; k++,i++)
            {
                arg[i].thread_ID = i;
                rt = pthread_create(&thread_ID[k],NULL,MaxPop_thread,&arg[i]);/*Cria threads*/
                if( rt != 0)
                {
                    printf( "Falha na criacao da Thread");
                    exit(0);
                }
            }

            for (j= 0; j < n_threads; j++)/*Verifica se thread ja foi finalizasa*/
            {
                pthread_join(thread_ID[j], NULL);
            }
            cont++;
        }
    }
    else/* caso Numero de linhas da matriz seja diferente do numero de threads*/
    {
        i=0;
        while( cont < n+1)
        {
            if( cont == n)
            {
                n_threads = arg->N%n_threads;
            }
            for(k=0; k < n_threads; k++,i++)
            {
                arg[i].thread_ID = i;
                rt = pthread_create(&thread_ID[k],NULL,MaxPop_thread,&arg[i]);/*cria threads*/
                if( rt != 0)
                {
                    printf( "Falha na criacao da Thread");
                    exit(0);
                }
            }

            for (j= 0; j < n_threads; j++)/*Verifica se thread encerrou*/
            {
                pthread_join(thread_ID[j], NULL);
            }
            cont++;
        }
    }


    return arg;
}
/*Calcula soma otima comparando somas*/
void *MaxPop_thread(void* args )
{
    dados *arg = (dados*)args;
    int i=1,soma_max=0,soma_parcial=0,soma_temp=0,num;

    soma_max = arg->populacao[0];/*Le primeiro*/
    soma_parcial = arg->populacao[1]; /*le segund numero*/

    for( i = 2; i < arg->M; i++ )
    {
        num = arg->populacao[i];
        soma_temp = soma_parcial;
        soma_parcial = soma_max + num;/*salva soma entre 2 numeros extremos, ex: primeiro e terceiro*/
        soma_max = maiorSoma(soma_temp,soma_max);

    }
    soma_max = maiorSoma(soma_max,soma_parcial);/*comparação necessária pois soma_parial pode ser maior que a soma soma_temp*/
    arg->soma = soma_max;
    pthread_exit((void *)NULL);
    return NULL;
}

