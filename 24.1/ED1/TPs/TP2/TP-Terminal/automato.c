#include "automato.h"
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

Matriz* alocarReticulado( int tam )
{
    return iniciaMatriz(tam);
}

void desalocarReticulado( Automato* automato )
{
    desalocaMatriz(automato->reticulado, automato->tam);
}

void LeituraReticulado( Automato* automato )
{
    int tam, geracoes;

    scanf("%d %d", &tam, &geracoes);

    automato->tam = tam;

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
    imprimeMatriz(automato->reticulado, automato->tam);
}

bool podeAcessar( int x, int y, int tam )
{
    return x >= 0 && x < tam && y >= 0 && y < tam;
}

void evoluirReticulado( Automato* automato )
{
    for (int i = 0; i < automato->geracao; i++) //Para cada geração
    {
        Matriz* novaGeracao = iniciaMatriz(automato->tam);

        for (int j = 0; j < automato->tam; j++)
        {
            for (int k = 0; k < automato->tam; k++) //Para cada célula do reticulado
            {
                int vizinhos = 0;

                for (int l = -1; l <= 1; l++)
                {
                    for (int m = -1; m <= 1; m++) //Para cada vizinho
                    {
                        if (l == 0 && m == 0)
                        {
                            continue; //*Descobri que isso existe
                        }
                        
                        int x = k + m;
                        int y = j + l;

                        //*Aprendi que o operador && é short-circuited
                        //*Ou seja, se a primeira condição for falsa, a segunda nem é avaliada
                        if (podeAcessar(x, y, automato->tam) && pesquisaCelula(automato->reticulado, x, y)) 
                        {
                            vizinhos++;
                        }
                    }
                }

                if (vizinhos == 3 || (vizinhos == 2 && pesquisaCelula( automato->reticulado, k, j ) ) ) //* mesmo caso aqui
                {
                    insereCelula(novaGeracao, k, j);
                }
            }
        }

        desalocaMatriz(automato->reticulado, automato->tam);

        automato->reticulado = novaGeracao;
    }
}