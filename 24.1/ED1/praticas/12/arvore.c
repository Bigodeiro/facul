#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//* Função para criar a árvore BST
void criar(No** no) {
    *no = NULL;
}

void destruir(No** no) {
    if (*no != NULL) {
        destruir(&(*no)->esq);
        destruir(&(*no)->dir);
        free(*no);
        *no = NULL;
    }
}

// Função auxiliar para criar um novo nó
No* criar_no(Item item, int pos) {
    No* no = (No*)malloc(sizeof(No));
    no->itens[0] = item;
    no->n = 1;
    no->esq = no->dir = NULL;
    return no;
}

// Função para inserir um preço na árvore
bool inserir(No** no, Item item) {
    int pos = item.preco;
    if (*no == NULL) 
    {
        *no = criar_no(item, pos);
    
        return true;
    }
    if (pos == (*no)->itens[0].preco) {
        if ((*no)->n == 10) 
        {
            return false;
        }
        
        (*no)->itens[(*no)->n++] = item;
        
        return true;
    }
    if (pos < (*no)->itens[0].preco)
    {
        return inserir(&(*no)->esq, item);
    }

    return inserir(&(*no)->dir, item);
}

void imprimeNo(No* no) {
    printf("%d ( ", no->itens[0].preco);
    for (int i=0;i<no->n;i++)
        printf("[%s|%s] ", no->itens[i].cultura, no->itens[i].fazenda);
    printf(")\n");
}

//*Impressao em ordem
void imprimeIn(No* no, int a, int b) {
    if (no == NULL) return;
    imprimeIn(no->esq, a, b);
    if (no->itens[0].preco >= a && no->itens[0].preco <= b) {
        imprimeNo(no);
    }
    imprimeIn(no->dir, a, b);
}

//*Impressao em pre-ordem
void imprimePre(No* no, int a, int b) 
{
    if (no == NULL) return;

    if (no->itens[0].preco >= a && no->itens[0].preco <= b) {
        imprimeNo(no);
    }

    imprimePre(no->esq, a, b);
    imprimePre(no->dir, a, b);
}

//*Impressao em pos-ordem
void imprimePos(No* no, int a, int b) 
{
    if (no == NULL) return;

    imprimePos(no->esq, a, b);
    imprimePos(no->dir, a, b);

    if (no->itens[0].preco >= a && no->itens[0].preco <= b) {
        imprimeNo(no);
    }
}
