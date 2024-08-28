#include "automato.h"
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

//Função encapsulada para alocar um reticulado
Matriz* alocarReticulado( int tam )
{
    return iniciaMatriz(tam);
}

//Função encapsulada para desalocar um reticulado
void desalocarReticulado( Automato* automato )
{
    desalocaMatriz(automato->reticulado, automato->tam);
}

//Função para ler um reticulado, alocando o esqueleto da matriz e inserindo as células vivas
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

//Função encapsulada para imprimir um reticulado
void imprimeReticulado( Automato* automato )
{
    imprimeMatriz(automato->reticulado, automato->tam);
}

//Função para verificar se uma célula pode ser acessada (nao tem índice negativo e não ultrapassa o tamanho do reticulado)
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
                            continue; //Faz com que pesquisaCelula não seja chamado para a própria célula
                        }
                        
                        int x = k + m;
                        int y = j + l;

                        //Como é short circuited, não dá segmentation fault
                        if (podeAcessar(x, y, automato->tam) && pesquisaCelula(automato->reticulado, x, y)) 
                        {
                            vizinhos++;
                        }
                    }
                }

                if (vizinhos == 3 || (vizinhos == 2 && pesquisaCelula( automato->reticulado, k, j ) ) )
                {
                    insereCelula(novaGeracao, k, j);
                }
            }
        }

        desalocaMatriz(automato->reticulado, automato->tam);

        automato->reticulado = novaGeracao;
    }
}