#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

Matriz* iniciaMatriz( int tam )
{
    printf("Alocando reticulado do tamanho %dx%d\n", tam, tam);

    return NULL;
}


void desalocaMatriz( Matriz* matriz )
{
    printf("Desalocando matriz\n");
}

bool insereCelula( Matriz* matriz, int x, int y )
{
    printf("Inserindo célula na posição %d %d\n", x, y);
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


void imprimeMatriz( Matriz* matriz )
{

}




