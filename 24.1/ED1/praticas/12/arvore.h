#ifndef ARVORE_H
#define ARVORE_H

#include <stdbool.h>

typedef struct {
    int preco;
    char cultura[21];
    char fazenda[51];
} Item;

typedef struct no {
    Item itens[10];
    int n;
    struct no* esq;
    struct no* dir;
} No;

void criar(No** no);
void destruir(No** no);
bool inserir(No** no, Item item);
void imprimeIn(No* no, int a, int b);
void imprimePre(No* no, int a, int b);
void imprimePos(No* no, int a, int b);

#endif // ARVORE_H