#include "double_hash.h"
#include "automato.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define VAZIO -1

//*Definimos VAZIO como (-1,-1) para representar uma célula vazia
bool ehVazia(Celula celula)
{
    return (celula.x == VAZIO && celula.y == VAZIO);
}

//*Função para inicializar a tabela hash
TabelaHash* iniciaTabela(int tam)
{
    TabelaHash* tabelaAux = malloc(sizeof(TabelaHash));
    tabelaAux->nColisoes = 0;
    tabelaAux->tam = tam * tam;

    tabelaAux->tabela = malloc(tam * tam * sizeof(Celula));

    for (int i = 0; i < tam * tam; i++)
    {
        tabelaAux->tabela[i].x = VAZIO;
        tabelaAux->tabela[i].y = VAZIO;
    }

    return tabelaAux;
}

//*Função para desalocar a tabela hash
void destroiTabela(TabelaHash* tabela)
{
    free(tabela->tabela);
    free(tabela);
}

//*Função auxiliar 1
int H1(Celula celula)
{
    int peso1[] = {1, 2};
    return (celula.x * peso1[0] + celula.y * peso1[1]);
}

//*Função auxiliar 2
int H2(Celula celula)
{
    int peso2[] = {3, 4};
    return (celula.x * peso2[0] + celula.y * peso2[1]);
}

//*Função hash duplo
int hashDuplo(Celula celula, int i) 
{
    int indice;
    int h1 = H1(celula);
    int h2 = H2(celula);

    indice = (h1 + i * h2);

    return indice;
}

//*Essa função tentará inserir uma célula na tabela hash no indice indicado pela função hash duplo e, caso haja colisão, tentará inserir em outro índice, incrementando o valor de i
void insereCelula(TabelaHash* tabela, Celula celula)
{
    int i = 0;
    int indice = hashDuplo(celula, i) % tabela->tam;

    while (!ehVazia(tabela->tabela[indice]))
    {
        indice = hashDuplo(celula, ++i) % tabela->tam;
        tabela->nColisoes++;
    }
    
    tabela->tabela[indice] = celula;
    
}

//*Semelhante à função insereCelula, essa função tentará encontrar uma célula na tabela hash no indice indicado pela função hash duplo e, incrementará o valor de i até encontrar a célula ou uma célula vazia
bool pesquisaCelula(TabelaHash* tabela, Celula celula)
{
    int i = 0;
    int indice = hashDuplo(celula, i) % tabela->tam;

    while (!ehVazia(tabela->tabela[indice]))
    {
        if (tabela->tabela[indice].x == celula.x && tabela->tabela[indice].y == celula.y)
        {
            return true;
        }
        indice = hashDuplo(celula, ++i) % tabela->tam;
    }

    return false;
}

void imprimeTabela(TabelaHash* tabela, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            if (pesquisaCelula(tabela, (Celula) {i, j}))
            {
                printf("1 ");
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
