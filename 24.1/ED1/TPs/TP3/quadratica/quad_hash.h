#ifndef double_hash_h
#define double_hash_h
#include <stdbool.h>

typedef struct celula
{
    int x;
    int y;

}Celula;


typedef struct tabela
{
    Celula* tabela;
    int tam;
    int nColisoes;

}TabelaHash;

TabelaHash* iniciaTabela(int tam);
void destroiTabela(TabelaHash* tabela);
void insereCelula(TabelaHash* tabela, Celula celula);
void imprimeTabela(TabelaHash* tabela, int tam);
bool pesquisaCelula(TabelaHash* tabela, Celula celula);
int hashQuadratico(Celula celula, int i);



#endif // "double_hash.h"