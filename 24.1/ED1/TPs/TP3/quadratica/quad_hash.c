#include "quad_hash.h"
#include "automato.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define VAZIO -1

//*
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

//*
void destroiTabela(TabelaHash* tabela)
{
    free(tabela->tabela);
}

int H1(Celula celula)
{
    int peso1[] = {1, 2};
    return (celula.x * peso1[0] + celula.y * peso1[1]);
}

int H2(Celula celula)
{
    int peso2[] = {3, 4};
    return (celula.x * peso2[0] + celula.y * peso2[1]);
}


//*função hash quadratico
int hashQuadratico(Celula celula, int i) 
{
    int indice;
    int h1 = H1(celula);
    int peso3[] = {5, 6};

    indice = (h1 + peso3[0]*i + peso3[1]*(i * i));

    return indice;
}

//*
void insereCelula(TabelaHash* tabela, Celula celula)
{
    int i = 0;
    int indice = hashQuadratico(celula, i) % tabela->tam;

    while (!ehVazia(tabela->tabela[indice]))
    {
        indice = hashQuadratico(celula, ++i) % tabela->tam;
        tabela->nColisoes++;
    }
    
    tabela->tabela[indice] = celula;
    
}

bool pesquisaCelula(TabelaHash* tabela, Celula celula)
{
    int i = 0;
    int indice = hashQuadratico(celula, i);

    while (!ehVazia(tabela->tabela[indice]))
    {
        if (tabela->tabela[indice].x == celula.x && tabela->tabela[indice].y == celula.y)
        {
            return true;
        }
        indice = hashQuadratico(celula, ++i) % tabela->tam;
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
    //printf("Quantidade de colisões: %d\n", tabela->nColisoes);
}
