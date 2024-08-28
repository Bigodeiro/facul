#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

Matriz* iniciaMatriz( int tam )
{
    Matriz* matriz = (Matriz*) malloc( sizeof(Matriz) );

    matriz->vetColunas = (Lista*) malloc( tam * sizeof(Lista) );

    matriz->vetLinhas = (Lista*) malloc( tam * sizeof(Lista) );

    for (int i = 0; i < tam; i++)
    {
        Celula* cabecaColuna = (Celula*) malloc( sizeof(Celula) );
        cabecaColuna->x = -1;
        cabecaColuna->y = -1;
        cabecaColuna->baixoProx = NULL;
        cabecaColuna->direitaProx = NULL;

        matriz->vetColunas[i].pCabeca = cabecaColuna;
        matriz->vetColunas[i].pUltimo = cabecaColuna;

        Celula* cabecaLinha = (Celula*) malloc( sizeof(Celula) );
        cabecaLinha->x = -1;
        cabecaLinha->y = -1;
        cabecaLinha->baixoProx = NULL;
        cabecaLinha->direitaProx = NULL;

        matriz->vetLinhas[i].pCabeca = cabecaLinha;
        matriz->vetLinhas[i].pUltimo = cabecaLinha;
    }

    return matriz;
}


void desalocaMatriz( Matriz* matriz, int tam )
{
    for (int i = 0; i < tam; i++)
    {
        Celula* aux = matriz->vetLinhas[i].pCabeca->direitaProx;
        while (aux != NULL)
        { 
            Celula* temp = aux;
            aux = aux->direitaProx; //sem perder o ponteiro da celula atual
            free(temp);
        }
        free(matriz->vetLinhas[i].pCabeca);
    }
    for (int i = 0; i < tam; i++)
    {
        Celula* aux = matriz->vetColunas[i].pCabeca->direitaProx;
        while (aux != NULL)
        { 
            Celula* temp = aux;
            aux = aux->direitaProx; //sem perder o ponteiro da celula atual
            free(temp);
        }
        free(matriz->vetColunas[i].pCabeca);
    }
    //depois que todas as listas forem liberadas
    free(matriz->vetLinhas); 
    free(matriz->vetColunas);
    free(matriz);
}


bool insereCelula( Matriz* matriz, int x, int y )
{
    Celula* celula = (Celula*) malloc( sizeof(Celula) );
    celula->x = x;
    celula->y = y;
    celula->baixoProx = NULL;
    celula->direitaProx = NULL;

    if (matriz->vetLinhas[y].pCabeca->direitaProx == NULL)
    {
        matriz->vetLinhas[y].pCabeca->direitaProx = celula;
        matriz->vetLinhas[y].pUltimo = celula;
    }else
    {
        Celula* aux = matriz->vetLinhas[y].pCabeca->direitaProx;
        while (aux->direitaProx != NULL && aux->x < x)
        {
            aux = aux->direitaProx;
        }

        if (aux->direitaProx == NULL)
        {
            matriz->vetLinhas[y].pUltimo = celula;
        }

        celula->direitaProx = aux->direitaProx;
        aux->direitaProx = celula;
    }

    if (matriz->vetColunas[x].pCabeca->baixoProx == NULL)
    {
        matriz->vetColunas[x].pCabeca->baixoProx = celula;
        matriz->vetColunas[x].pUltimo = celula;
    }else
    {
        Celula* aux = matriz->vetColunas[x].pCabeca->baixoProx;
        while (aux->baixoProx != NULL && aux->y < y)
        {
            aux = aux->baixoProx;
        }

        if (aux->baixoProx == NULL)
        {
            matriz->vetColunas[x].pUltimo = celula;
        }

        celula->baixoProx = aux->baixoProx;
        aux->baixoProx = celula;
    }

    return false;

}


bool removeCelula( Matriz* matriz, int x, int y )
{
    return false;

}


bool pesquisaCelula( Matriz* matriz, int x, int y )
{
    Celula* aux = matriz->vetLinhas[y].pCabeca->direitaProx;

    while (aux != NULL && aux->x <= x)
    {
        if (aux->x == x)
        {
            return true;
        }
        aux = aux->direitaProx;
    }

    return false;
}


void imprimeMatriz( Matriz* matriz, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        Celula* aux = matriz->vetLinhas[i].pCabeca->direitaProx;
        for (int j = 0; j < tam; j++)
        {
            if (aux != NULL && aux->x == j)
            {
                printf("1 ");
                aux = aux->direitaProx;
            }else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }

    printf("\n");
}




