#include "io.h"
#include "utility.h"

dados* LeEntrada()
{
    int i=0,j=0,N,M;

    scanf("%d %d",&N,&M);/*Le parametros Iniciais*/

    dados *cidade = alocaMapa(N,M);/*Aloca matriz*/

    for( i=0; i<N; i++)
    {
        for( j=0; j<M; j++)
        {
            scanf("%d",&(cidade[i].populacao[j]));/*Le mapa*/
        }
    }
    return cidade;

}
void MaxPop(int n,int *v)
{
    int i=0,soma_max=0,soma_parcial=0,soma_temp=0,num=0;

    soma_max = v[0];
    soma_parcial = v[1];
    for( i=2; i< n; i++)
    {
        num = v[i];
        soma_temp = soma_parcial;
        soma_parcial = soma_max + num;
        soma_max = maiorSoma(soma_temp,soma_max);

    }
    soma_max = maiorSoma(soma_max,soma_parcial);
    free(v);
    v = NULL;
    printf("%d\n",soma_max);
}

dados* alocaMapa(int N, int M)
{
    int i=0;
    dados *cidades = (dados*)malloc(N*sizeof(dados));/*Aloca linhas*/
    for( i = 0; i< N; i++)
    {
        cidades[i].M = M;
        cidades[i].N = N;
    }
    if( cidades == NULL)
    {
        printf(" Erro ao alocar memoria\n");
        exit(0);
    }
    for( i=0; i<N; i++)/*aloca "Colunas"*/
    {
        cidades[i].populacao = (int*)malloc(M*sizeof(int));
        if( cidades[i].populacao == NULL)
        {
            printf(" Erro ao alocar memoria\n");
            exit(0);
        }
    }
    return cidades;
}
dados* liberaMapa(int N, dados* Map)
{
    int i;
    for( i=0; i<N; i++)/*libera linhas*/
    {
        free( Map[i].populacao);
        Map[i].populacao = NULL;
    }
    free(Map);
    Map = NULL;
    return Map;
}
