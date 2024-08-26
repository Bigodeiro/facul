# ifndef matriz_h
# define matriz_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct celula
{
    int x;
    int y;

    struct celula* baixoProx;
    struct celula* direitaProx;

}Celula;

typedef struct matriz
{
    Celula* direitaCabeca;
    Celula* direitaUltima;

    Celula* baixoCabeca;
    Celula* baixoUltima;

}Matriz;

Matriz* iniciaMatriz( int tam );
bool insereCelula( Matriz* matriz, int x, int y );
bool removeCelula( Matriz* matriz, int x, int y );
bool pesquisaCelula( Matriz* matriz, int x, int y );
void imprimeMatriz( Matriz* matriz );
void desalocaMatriz( Matriz* matriz );


# endif
