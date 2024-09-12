#include "heap.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/** Mantenha como especificado
 * Refaz o heap da raiz para as folhas
 */ 
void refaz(Heap *heap);

/** Mantenha como especificado
 * Insere um chamada na posicao index
 */ 
void heapInsere(Heap *heap, Chamada chamada, int index);

/** Mantenha como especificado
 * Retorna true se c1 tem mais prioridade do que c2.
 * Se forem iguais, retorne false
 */ 
bool temMaisPrioridade(Chamada* c1, Chamada* c2);

//* Mantenha como especificado
Chamada criarChamada(char *nome, int prioridade, int dia, int mes, int ano) {
    Chamada aux;

    strcpy(aux.nome, nome);

    aux.prioridade = prioridade;

    aux.nascimento.dia = dia;
    aux.nascimento.mes = mes;
    aux.nascimento.ano = ano;

    return aux;
}

//* Mantenha como especificado
void imprimeChamada(Chamada chamada) {
    printf("%02d | %02d/%02d/%04d | %s\n", chamada.prioridade, chamada.nascimento.dia,
            chamada.nascimento.mes, chamada.nascimento.ano, chamada.nome);
}

//* Mantenha como especificado
Heap* criarHeap() {
    Heap* heap = (Heap*) malloc(sizeof(Heap));
    heap->tam = 0;
    return heap;
}

//* Mantenha como especificado
Heap* destroiHeap(Heap *heap) {
    free(heap);
    return NULL;
}

//* Mantenha como especificado
void inserirChamada(Heap *heap, Chamada chamada) {
    heapInsere(heap, chamada, heap->tam);
    heap->tam++;
    
    refaz(heap);
}

//* Mantenha como especificado
Chamada atenderChamada(Heap *heap) {
    Chamada chamada = heap->chamadas[0];
    heap->tam--;

    heapInsere(heap, heap->chamadas[heap->tam], 0);

    refaz(heap);

    return chamada;
}

//* Mantenha como especificado
bool consultarSeTemProximaChamada(Heap *heap) {

    return heap->tam > 0;
}

// Mantenha como especificado
void refaz(Heap *heap) {

    int i = heap->tam - 1; // Get the index of the last element in the heap
    while (i > 0) {
        int pai = (i - 1) / 2; // Calculate the index of the parent node

        // Check if the child node has higher priority than its parent
        if (temMaisPrioridade(&heap->chamadas[i], &heap->chamadas[pai])) {
            // Swap the child node with its parent
            Chamada aux = heap->chamadas[i];
            heap->chamadas[i] = heap->chamadas[pai];
            heap->chamadas[pai] = aux;
            i = pai; // Update the index to the parent node
        } else {
            break; // If the child node has lower or equal priority, exit the loop
        }
    }

    i = 0; // Reset the index to the root node

    while (i < heap->tam) {
        int filhoEsq = 2 * i + 1; // Calculate the index of the left child node
        int filhoDir = 2 * i + 2; // Calculate the index of the right child node
        int maior = i; // Assume the current node is the largest

        // Check if the left child node has higher priority than the current node
        if (filhoEsq < heap->tam && temMaisPrioridade(&heap->chamadas[filhoEsq], &heap->chamadas[maior])) {
            maior = filhoEsq; // Update the index to the left child node
        }

        // Check if the right child node has higher priority than the current node or the left child node
        if (filhoDir < heap->tam && temMaisPrioridade(&heap->chamadas[filhoDir], &heap->chamadas[maior])) {
            maior = filhoDir; // Update the index to the right child node
        }

        // If the current node is not the largest, swap it with the largest child node
        if (maior != i) {
            Chamada aux = heap->chamadas[i];
            heap->chamadas[i] = heap->chamadas[maior];
            heap->chamadas[maior] = aux;
            i = maior; // Update the index to the largest child node
        } else {
            break; // If the current node is the largest, exit the loop
        }
    }
}

//* Mantenha como especificado
void heapInsere(Heap *heap, Chamada chamada, int index) {
    heap->chamadas[index] = chamada;
}

//*
bool ehMaisNovo(Data d1, Data d2) {
    bool res = false;
    if (d1.ano < d2.ano) {
        res = true;
    }else if (d1.ano > d2.ano) {
        res = false;
    }else {
        if (d1.mes < d2.mes) {
            res = true;
        }else if (d1.mes > d2.mes) {
            res = false;
        }else {
            if (d1.dia < d2.dia) {
                res = true;
            }else if (d1.dia > d2.dia) {
                res = false;
            }else {
                res = false;
            }
        }
    }
    return !res;
}

//* Mantenha como especificado
bool temMaisPrioridade(Chamada* c1, Chamada* c2) {
    bool res = false;
    if (c1->prioridade > c2->prioridade) {
        res = true;
    }else if (c1->prioridade < c2->prioridade) {
        res = false;
    }else {
        res = ehMaisNovo(c1->nascimento, c2->nascimento);
    }
    
    return res;
}