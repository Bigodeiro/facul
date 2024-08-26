#include "automato.h"
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


// Função que aloca/inicia um reticulado de nLinhas x nColunas
Matriz* alocarReticulado( int tam )
{

    return iniciaMatriz(tam);
}

// Função que desaloca um reticulado
void desalocarReticulado( Automato* automato )
{
    desalocaMatriz(automato->reticulado);
}

// Função que lê um reticulado e armazena no automato
void LeituraReticulado( Automato* automato )
{
    int tam, geracoes;

    scanf("%d %d", &tam, &geracoes);

    automato->nLinhas = tam;
    automato->nColunas = tam;

    automato->geracao = geracoes;

    automato->reticulado = alocarReticulado(tam);    

    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            int celula;
            scanf("%d", &celula);

            if (celula == 1)
            {
                insereCelula(automato->reticulado, j, i);
            }
        }   
    }
    

}


void imprimeReticulado( Automato* automato )
{

}


void evoluirReticulado( Automato* automato )
{
    printf("Evoluindo reticulado %d vezes\n", automato->geracao);
}

