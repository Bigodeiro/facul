#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

Matriz* iniciaMatriz( int tam )
{
    printf("Alocando reticulado do tamanho %dx%d\n", tam, tam);

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



void desalocaMatriz( Matriz* matriz )
{
    printf("Desalocando matriz\n");
}

bool insereCelula( Matriz* matriz, int x, int y )
{
    // printf("Inserindo célula na posição %d %d\n", x, y);
    return false;

}


bool removeCelula( Matriz* matriz, int x, int y )
{
    return false;

}


bool pesquisaCelula( Matriz* matriz, int x, int y )
{
    return false;

}


void imprimeMatriz( Matriz* matriz, int tam)
{
    //teste
    Celula* celula = (Celula*) malloc( sizeof(Celula) );
    matriz->vetLinhas[1].pCabeca->direitaProx = celula;

    printf("Imprimindo matriz\n");
    for (int i = 0; i < tam; i++)
    {
        if (matriz->vetLinhas[i].pCabeca->direitaProx == NULL)
        {
            for (int j = 0; j < tam; j++)
            {
                printf("0 ");
            }
        }else
        {
            for (int j = 0; j < tam; j++)
            {
                printf("1 ");
            }
        }
        
        printf("\n");
    }
}




