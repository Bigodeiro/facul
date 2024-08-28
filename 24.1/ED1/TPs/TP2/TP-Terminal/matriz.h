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

typedef struct lista
{
    Celula* pCabeca;
    Celula* pUltimo;

}Lista;

typedef struct matriz
{
    Lista* vetColunas;
    Lista* vetLinhas;

}Matriz;

Matriz* iniciaMatriz( int tam );
bool insereCelula( Matriz* matriz, int x, int y );
bool pesquisaCelula( Matriz* matriz, int x, int y );
void imprimeMatriz( Matriz* matriz , int tam );
void desalocaMatriz( Matriz* matriz, int tam );

# endif
